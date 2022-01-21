// doc file phone.txt va ghi vao stack sau do pop_stack va ghi vao file phonecp.txt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phone    
{
    char phonenb[20];
    char name[30];
    char email[30];
}Item;
typedef struct StackNode{
    Item Inf;
    struct StackNode * next;
}StackNode;
typedef struct Stack
{
    StackNode *top;
}Stack;
StackNode * MakeNode(){
    StackNode * node;
    node=(StackNode*)malloc(sizeof(StackNode));
    node->next=NULL;
    return node;
}
int StackEmpty(const Stack *s){
    return (s->top==NULL);
}
Stack *StackConstruct(){
    Stack * s;
    s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
    s->top=NULL;
    return s;   
}
int StackFull(){
    printf("\n No Memory, Stack is Full\n");
    getc(stdin);
    return 1;
}
int StackPush(Stack *s, Item X){
    StackNode * node=MakeNode();
    if(node==NULL){
        StackFull();
        return 1;
    }
    strcpy(node->Inf.name,X.name);
    strcpy(node->Inf.phonenb,X.phonenb);
    strcpy(node->Inf.email,X.email);
    node->next=s->top;
    s->top=node;
    return 0;
}
Item StackPop(Stack *s){
    Item X;
    StackNode * node;
    if(StackEmpty(s)){
        return X;
    }
    node=s->top;
    strcpy(X.name,node->Inf.name);
    strcpy(X.phonenb,node->Inf.phonenb);
    strcpy(X.email,node->Inf.email);
    s->top=node->next;
    free(node);
    return X;
}
void StackDestroy(Stack *s){
    while(!StackEmpty(s)){
        StackPop(s);
    }
    free(s);
}
int read_file(FILE * f,Stack *s){
    int i = 0;
    f= fopen("phone.txt", "r");
    if(f==NULL){ 
		printf("Error load file or file not exist\n");
		return i;
	}
	else
	{
    	while (!feof(f))
		{   
            Item node;
            fgetc(f);
            fscanf(f,"%d%*c",&i);
            fgets(node.name,sizeof(node.name),f);
            node.name[strlen(node.name)-1]='\0';
			fgets(node.phonenb,sizeof(node.phonenb),f);
            node.phonenb[strlen(node.phonenb)-1]='\0';
            fgets(node.email,sizeof(node.email),f);
            node.email[strlen(node.email)-1]='\0';
            fgetc(f);
            StackPush(s,node);
            i++;
            printf("\n\n%4d%30s%20s%30s\n",i,node.name,node.phonenb,node.email);
            
		}
    }
	fclose(f);
	return i;
}
void write_file(FILE * f,Stack *s){
    int i=0;
    f=fopen("phonecp.txt","w+");
    if(f==NULL){ 
		printf("Error load file or file not exist\n");
		return ;
	}
	else
	{
        while (!StackEmpty(s))
        {
            Item node;
            node=StackPop(s);
            i++;
            fprintf(f,"\n%4d%30s%20s%30s\n",i,node.name,node.phonenb,node.email);
        }
        
    }
    fclose(f);
}
int main(){
    FILE * fin,*fout;
    Stack *s;
    s=StackConstruct();
    read_file(fin,s);
    write_file(fout,s);
    return 0;
}