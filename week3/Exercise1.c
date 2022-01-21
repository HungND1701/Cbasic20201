#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Address{
    char name[20];
    char phonenum[20];
    char email[20];
}Address_t;
typedef struct AddressList {
    struct AddressList *next;
    struct Address addr;
}AddressList_t;
void input_add(Address_t *add){
    for(int i=0;i<3;i++){
        printf("Name : ");scanf("%s",add[i].name);
        printf("Phone number : ");getchar();scanf("%s",add[i].phonenum);
        printf("Email : ");getchar();scanf("%s",add[i].email);
    }
}
void insert(AddressList_t * root,AddressList_t * cur,Address_t * add,int i){
    AddressList_t * new=NULL;
    new= (AddressList_t *)malloc(sizeof(AddressList_t));
    new->addr=add[i];
    new->next=NULL;
    if ( root == NULL ) {
        root = new;
        cur = root;
    } else {
        new->next=cur->next;
        cur->next=new;
        cur=cur->next;
    }
}
void push(AddressList_t * root, Address_t* add,int i) {
    AddressList_t * cur = root;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = (AddressList_t *) malloc(sizeof(AddressList_t));
    cur->next->addr = add[i];
    cur->next->next = NULL;
}
int main(){
    AddressList_t *root=NULL,*cur=NULL;
    Address_t add[3];
    input_add(add);
    root = (AddressList_t *) malloc(sizeof(AddressList_t));
    cur = (AddressList_t *) malloc(sizeof(AddressList_t));
    root->next=NULL;
    push(root,add,0);
    push(root,add,2);
    AddressList_t * prt; prt=root;
    for(prt;prt!=NULL;prt=prt->next){
        printf("%s\n",prt->addr.name);
        printf("%s\n",prt->addr.phonenum);
        printf("%s\n",prt->addr.email);
    }
    return 0;

}