#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct dathuc   
{
    ElementType coeff;
    ElementType pow;
    struct dathuc *link;
}dathuc;
dathuc * Poly1,*Poly2;
dathuc * Polysum;
dathuc*node,*ptr1,*ptr2,*ptr;
void SumTwoPol(){
    node=(dathuc *)malloc(sizeof(dathuc));
    Polysum=node;
    ptr1=Poly1;
    ptr2=Poly2;
    while (ptr1!=NULL&&ptr2!=NULL)
    {   
        ptr=node;
        if(ptr1->pow>ptr2->pow){
            node->coeff=ptr2->coeff;
            node->pow=ptr2->pow;
            ptr2=ptr2->link;    
        }else if(ptr1->pow<ptr2->pow){
            node->coeff=ptr1->coeff;
            node->pow=ptr1->pow;
            ptr1=ptr1->link;
        }else{
            node->coeff=ptr1->coeff+ptr2->coeff;
            node->pow=ptr1->pow;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        node=(dathuc *)malloc(sizeof(dathuc));
        ptr->link=node;
    }
    if(ptr1==NULL){
        while (ptr2!=NULL)
        {
            node->coeff=ptr2->coeff;
            node->pow=ptr2->pow;
            ptr2=ptr2->link;
            ptr=node;
            node=(dathuc*)malloc(sizeof(dathuc));
            ptr->link=node;
        }
    }
    else if(ptr2==NULL)
    {
        while (ptr1!=NULL)
        {
            node->coeff=ptr1->coeff;
            node->pow=ptr1->pow;
            ptr1=ptr1->link;
            ptr=node;
            node=(dathuc*)malloc(sizeof(dathuc));
            ptr->link=node;
        }
    }
    node=NULL;
    ptr->link=node;
}
dathuc * Insert_toLast(dathuc * First, ElementType X, ElementType Y){
    dathuc * TempNode; dathuc*NewNode;
    NewNode=(dathuc*)malloc(sizeof(dathuc));
    NewNode->coeff=X;
    NewNode->pow=Y;
    TempNode=First;
    while (TempNode->link!=NULL)
    {
        TempNode=TempNode->link;
    }
    TempNode->link=NewNode;
    NewNode->link=NULL;
    return First;
}
dathuc * Insert_toHead(dathuc * First , ElementType X,ElementType Y){
    dathuc * TempNode;
    TempNode=(dathuc* )malloc(sizeof(dathuc));
    TempNode->coeff=X;
    TempNode->pow=Y;
    TempNode->link=First;
    First=TempNode;
    return First;
}
void Print(dathuc * First){
    dathuc* TempNode;
    TempNode=First;
    printf("SUM= ");
    while (TempNode)
    {   
        if(TempNode->link==NULL){
           printf("%d.x^%d.",TempNode->coeff,TempNode->pow);
           TempNode=TempNode->link;
        }else{
           printf("%d.x^%d+",TempNode->coeff,TempNode->pow);
           TempNode=TempNode->link;
        }
    }
    printf("\n");
}
int main(){
    Poly1=NULL;Poly2=NULL;Polysum=NULL;
    Poly1=Insert_toHead(Poly1,-1,1);
    Poly1=Insert_toLast(Poly1,1,100);
    Print(Poly1);
    Poly2=Insert_toHead(Poly2,1,2);
    Poly2=Insert_toLast(Poly2,1,3);
    Print(Poly2);
    SumTwoPol();
    Print(Polysum);
    return 0;
}