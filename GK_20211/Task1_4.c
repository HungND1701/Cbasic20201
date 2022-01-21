#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{SUCCESS,FAIL};
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
typedef struct Node_t
{
    phoneaddress phone;
    struct Node_t *Next;
}Node;
typedef struct Task1_2
{
    Node * top;
}TOP;

Node * makenode(phoneaddress *X){
    Node * node = (Node*) malloc(sizeof(Node));
    node->Next= NULL;
    strcpy(node->phone.name,X->name);
    strcpy(node->phone.tel,X->tel);
    strcpy(node->phone.email,X->email);
    return node;
}
TOP * ListConstruct(){
    TOP * s ;
    s= (TOP * )malloc(sizeof(TOP));
    s->top=NULL;
    return s;
}
void push_back(TOP* s,phoneaddress *X){
    Node * newnode = makenode(X);
    if(s->top==NULL){
        s->top=newnode;
        return;
    }
    else{
        Node* ptr= s->top;
        while(ptr->Next!=NULL){
            ptr=ptr->Next;
        }
        ptr->Next=newnode;
    }
}
phoneaddress pop(TOP*s){
    phoneaddress X;
    Node *node = s->top;
    s->top= s->top->Next;
    X=node->phone;
    return X;
}
int main(){
    TOP * S= ListConstruct();
    FILE * fin,*fout;
    int n,irc;
    char name[20];
    int reval=SUCCESS;
    printf("How many contacts do you want to enter (<=15)?");
    scanf("%d",&n);
    printf("%d",n);
    if((fin=fopen("phonebook1.dat","rb"))==NULL){
        printf("Can not open %s.\n","phonebook1.dat");
        reval = FAIL;
    }
    for(int i=1;i<=10;i++){
            phoneaddress *X;
            irc= fread(X,sizeof(phoneaddress),1,fin);
            printf("1 ");
            push_back(S,X);
    } 
    while (n>10)
    {   
            phoneaddress Y = pop(S);
            phoneaddress *X;
            irc= fread(X,sizeof(phoneaddress),1,fin);
            push_back(S,X);
            printf("\n%s have the email address %s and telephone number : %s",Y.name,Y.email,Y.tel);
            n--;
    }
    
    fclose(fin);
    return reval;
}