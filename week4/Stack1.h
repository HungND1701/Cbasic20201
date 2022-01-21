#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node * link;
};
struct node *push(struct node * p,int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("No Memory available Error \n");
        exit(0);
    }
    temp->data=value;
    p=temp;
    return(p);
}
struct node * pop(struct node * p, int * value){
    struct node * temp;
    if(p=NULL){
        printf("The stack is empty can not pop Error\n");
        exit(0);
    }
    *value= p->data;
    temp=p;
    p=p->link;
    free(temp);
    return(p);
}