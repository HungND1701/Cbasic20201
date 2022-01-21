/* Tim cac phan tu nam trong tep phonebook.dat 
file phonebook.dat luu tru cac phan tu thuoc file phone phonebook.txt
*/
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
Node * Middle(Node * start , Node * last){
    if(start ==NULL){
        return NULL;
    }
    Node * slow = start;
    Node * fast = start->Next;
    while (fast!=last)
    {
        fast= fast->Next;
        if(fast!=last){
            slow= slow->Next;
            fast=fast->Next;
        }
    }
    return slow;
}
Node * BinSearch(Node * head, char *name){
    Node * start = head;
    Node * last= NULL;
    do{
        Node * mid = Middle(start,last);
        if(mid==NULL) return NULL;
        if(strcmp(mid->phone.name,name)==0) return mid;
        else if(strcmp(mid->phone.name,name)<0) start= mid->Next;
        else last= mid;
    }while (last==NULL||last!=start);
    return NULL;
}
int main(){
    TOP * S= ListConstruct();
    FILE * fin,*fout;
    int n,irc;
    char name[20];
    int reval=SUCCESS;
    printf("How many contacts do you want to enter (<11)?");
    scanf("%d",&n);
    if((fin=fopen("phonebook.dat","rb"))==NULL){
        printf("Can not open %s.\n","phonebook.dat");
        reval = FAIL;
    }
    for(int i=1;i<=n;i++){
        phoneaddress *X;
        irc= fread(X,sizeof(phoneaddress),1,fin);
        push_back(S,X);
    }
    printf("\nLet me know the name you want to search :");
    scanf("%s",name);
    Node * find = BinSearch(S->top,name);
    if(find==NULL){
        printf("No contact match the criteria !");
        return -1;
    }
    printf("\n%s have the email address %s and telephone number : %s",find->phone.name,find->phone.email,find->phone.tel);
    if((fout=fopen("Ketqua_2.txt","w"))==NULL){
        printf("Can't create file to write.\n");
        reval= FAIL;
    }
    fprintf(fout,"%s have the email address %s and telephone number : %s",find->phone.name,find->phone.email,find->phone.tel);
    
    fclose(fout);
    fclose(fin);
    return reval;
}

