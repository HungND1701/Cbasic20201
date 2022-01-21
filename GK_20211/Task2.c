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
void push_back(IToP * s,char x){
    IToP_Node * node = makenode(x);
    if(IsEmpty(s)){
        s->top=node;
        return;
    }
    else{
        IToP_Node* ptr= s->top;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=node;
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
int isnum(char X){
    char *ptr;
    ptr=&X;
    return(atoi(ptr));
}
int isop(char ptr){
    return(ptr=='+'||ptr=='-'||ptr=='*'||ptr=='/');
}
int uutien(char x1,char x2){
    int ut1,ut2;
    if(x1=='*'||x1=='/') ut1=2;
    if(x2=='*'||x2=='/') ut2=2;
    if(x1=='+'||x1=='-') ut1=1;
    if(x2=='+'||x2=='-') ut2=1;
    if(ut1<ut2) return -1;
    if(ut1==ut2) return 0;
    else return 1;
}
IToP * InToPost(char * str){
    IToP * s=stackconstruct();
    IToP * s1=stackconstruct();
    char * ptr=str;
    while(*ptr!='\0'){
        if(isnum(*ptr)!=0){
            push_back(s1,*ptr);
        }
        if(isop(*ptr)){
            if(!IsEmpty(s)){
                char x=s->top->X;
                if(uutien(*ptr,x)==1)
                {
                    push(s,*ptr);
                }
                if(uutien(*ptr,x)==0){
                       push_back(s1,pop(s));
                       push(s,*ptr); 
                }
                if(uutien(*ptr,x)==-1){
                    while(!IsEmpty(s)&&uutien(*ptr,s->top->X)==-1){
                        push_back(s1,pop(s));
                    }
                    if(!IsEmpty(s)&&uutien(ptr[0],s->top->X)==0){
                            push_back(s1,pop(s));
                    }
                    push(s,*ptr);
                }
            }
            else push(s,*ptr);   
        }
        ptr++;
    }
    while(!IsEmpty(s)){
        push_back(s1,pop(s));
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
// Cac ham tinh 
int stack[100];
int top;
int do_op(int a,int b,char op){
    int ans;
    switch (op)
    {
    case '+':
        ans=a+b;
        break;
    case '-':
        ans=a-b;
        break;
    case '*':
        ans=a*b;
        break;
    case '/':
        ans=a/b;
        break;
    default:
        break;
    }
    return ans;
}
int pop_t(){
    int ret;
    ret=stack[top];
    top --;
    return ret;
}
void push_t(int a){
    top ++;
    stack[top]=a;
}
int eval(IToP * s){
    int first, second,c;
    while (!IsEmpty(s))
    {
        char X= pop(s);
        if(isop(X)){
            second=pop_t();
            first= pop_t();
            c= do_op(first,second,X);
            push_t(c);
        }
        else{
            c=atoi(&X);
            push_t(c);
        }
    }
    return (pop_t());
}

int menu(){
    printf("****************** MENU ******************\n\n");
    printf("             1.Nhap bieu thuc\n");
    printf("         2.Chuyen sang dang postfix\n");
    printf("      3.Tinh gia tri bieu thuc Postfix\n");
    printf("                 4.Thoat\n\n");
}
int main(){
    int c;
    char f;
    do{
        menu();
        printf("Nhap lua chon cua bn : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            getc(stdin);
            char str[100];
            printf("Nhap bieu thuc can chuyen doi : ");
            gets(str);
            printf("\n");
            printf("Press 't' to continue : ");
            scanf("%c",&f);
            if(f=='t') break;
        case 2:
            IToP *S;
            S=InToPost(str);
            disp(S);
            printf("\n");
            printf("Press 't' to continue : ");
            getc(stdin);
            scanf("%c",&f);
            if(f=='t') break;
        case 3:
            int result= eval(S);
            printf("Ket qua : %d\n\n",result);
            printf("Press 't' to continue : ");
            getc(stdin);
            scanf("%c",&f);
            if(f=='t') break;
        case 4:
            break;
        default:
            break;
        }
    }while(c!=4);

    return 0;
}