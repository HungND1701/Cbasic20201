// nhap 1 - 2 ^ 3 ^ 3 - ( 4 + 5 * 6 ) * 7  
// In ra 1 2 3 3 ^ ^ - 4 5 6 * + 7 2 * + 7 * -
// chi nhan string 1 chu so 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct InfixToPostfix
{
    char X;
    struct InfixToPostfix * next;
}IToP_Node;
typedef struct IToPost
{
    IToP_Node * top;
}IToP;

IToP * stackconstruct(){
    IToP * s;
    s=(IToP*)malloc(sizeof(IToP));
    s->top=NULL;
    return s;
}
IToP_Node * makenode(char x){
    IToP_Node * node;
    node=(IToP_Node * )malloc(sizeof(IToP_Node));
    node->next=NULL;
    node->X=x;
    return node;
}
int IsEmpty(IToP *s){
    return(s->top==NULL);
}
void push(IToP * s,char x){
    IToP_Node * node = makenode(x);
    if(IsEmpty(s)){
         s->top=node;
         return;
    }
    else{
        node->next=s->top;
        s->top=node;
        return;
    }
}
char pop(IToP * s){
    char X ;
    IToP_Node * node;
    node=s->top;
    X= s->top->X;
    s->top=s->top->next;
    free(node);
    return X;
}
int isnum(char *ptr){
    return(atoi(ptr));
}
int isop(char ptr){
    return(ptr=='^'||ptr=='+'||ptr=='-'||ptr=='*'||ptr=='/');
}
int ngoacmo(char ptr){
    return(ptr=='(');
}
int ngoacdong(char ptr){
    return(ptr==')');
}
int uutien(char x1,char x2){
    int ut1,ut2;
    if(x1=='(') ut1=4;
    if(x2=='(') ut2=4;
    if(x1=='^') ut1=3;
    if(x2=='^') ut2=3;
    if(x1=='*'||x1=='/') ut1=2;
    if(x2=='*'||x2=='/') ut2=2;
    if(x1=='+'||x1=='-') ut1=1;
    if(x2=='+'||x2=='-') ut2=1;
    if(ut1<ut2) return -1;
    if(ut1==ut2) return 0;
    else return 1;
}
int Is_Left_associative(char X){
    return (X!='^');
}
IToP * InToPost(char * str){
    IToP * s=stackconstruct();
    IToP * s1=stackconstruct();
    char * ptr;
    ptr=strtok(str," ");
    while(ptr){
        if(isnum(ptr)!=0){
            push(s1,ptr[0]);
        }
        if(isop(ptr[0])){
            if(!IsEmpty(s)){
                char x=s->top->X;
                if(uutien(ptr[0],x)==1)
                {
                    push(s,ptr[0]);
                }
                if(uutien(ptr[0],x)==0){
                    if(Is_Left_associative(ptr[0])){
                       push(s1,pop(s));
                       push(s,ptr[0]);
                    }
                    else push(s,ptr[0]);
                }
                if(uutien(ptr[0],x)==-1){
                    while(!IsEmpty(s)&&uutien(ptr[0],s->top->X)==-1 && s->top->X!='('){
                        push(s1,pop(s));
                    }
                    if(!IsEmpty(s)&&uutien(ptr[0],s->top->X)==0){
                        if(Is_Left_associative(ptr[0])){
                            push(s1,pop(s));
                        }
                    }
                    push(s,ptr[0]);
                }
            }
            else push(s,ptr[0]);   
        }
        if(ngoacmo(ptr[0])){
            push(s,ptr[0]);
        }
        if(ngoacdong(ptr[0])){
            while(s->top->X!='('){
                 push(s1,pop(s));
            }
            pop(s);
        }
        ptr=strtok(NULL," ");
    }
    while(!IsEmpty(s)){
        push(s1,pop(s));
    }
    return s1;
}
void disp(IToP *s){
    IToP_Node * node;
    char m;
    printf("\nDanh Sach Cac phan tu cua Stack\n");
    if(IsEmpty(s)){
        printf("\n\n >>>>> EMPTY STACK <<<<<\n");
        getchar();
    }else{
        node = s->top;
        do{
            m=node->X;
            printf("%c ",m); 
            node=node->next;
        }while(!(node==NULL));
        printf("\n");
    }
}
IToP * Dao(IToP * s){
    IToP * S;
    S=stackconstruct();
    IToP_Node * node;
    node=s->top;
    while (node!=NULL)
    {
        push(S,node->X);
        node=node->next;
    }
    return S;
}
int main(){
    char str[100];
    printf("Nhap bieu thuc can chuyen doi : ");
    gets(str);
    IToP * S1,*S;
    S1=InToPost(str);
    S=Dao(S1);
    disp(S);
    return 0;
}