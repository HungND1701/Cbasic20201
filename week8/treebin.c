#include<stdio.h>
#include<stdlib.h>

typedef struct BNode
{
    int Inf;
    struct BNode *ChildLeft;
    struct BNode *ChildRight;
} BNode;

BNode * MakeNote(int X){
    BNode * Node;
    Node=(BNode*)malloc(sizeof(BNode));
    if(Node==NULL){
        printf("Out of memory!\n");
        exit(1);
    }
    else{
    Node->Inf=X;
    Node->ChildLeft=NULL;
    Node->ChildRight=NULL;
    }
    return Node;
}
void insert(BNode * r,int X){
    BNode * newNode= MakeNote(X);
    if(r==NULL){
        r=newNode;
        return;
    }
    else{
        if(r->ChildLeft==NULL){
            insert(r->ChildLeft,X);
        }
        else{
            if(r->ChildRight==NULL){
                insert(r->ChildRight,X);
            }
            else{
                insert(r->ChildLeft,X);
            }
            }
    }
}
BNode * find(BNode * r,int X)
{ 
    if(r==NULL) return NULL;
    if(r->Inf==X) return r;
    else if(r->ChildLeft!=NULL) find(r->ChildLeft,X);
         else if(r->ChildRight!=NULL) find(r->ChildRight,X);
    
    return NULL;
}
int CountNodes(BNode * Node){
     if(Node==NULL) return 0;
     else{
         int ld=CountNodes(Node->ChildLeft);
         int rd=CountNodes(Node->ChildRight);
         return 1+ld+rd;
     }
}

int Depth(BNode * first){
    if(first==NULL) return 0;
    int ld=Depth(first->ChildLeft);
    int rd=Depth(first->ChildRight);
    return 1+ (ld>rd ? ld : rd);
}

void freeTree(BNode * tree)
{
    if(tree==NULL) return;
    freeTree(tree->ChildLeft);
    freeTree(tree->ChildRight);
    free(tree);
    return;
}
void printPreOrder(BNode * tree)
{
    if(tree!=NULL){
        printf("%d\n",tree->Inf);
        printPreOrder(tree->ChildLeft);
        printPreOrder(tree->ChildRight);
    }
}
void Preorder_non(BNode * tree)
{
    if(tree!=NULL) {
        printf("%d\n",tree->Inf);
        while(tree->ChildLeft!=NULL)
        {
            tree=tree->ChildLeft;
            printf("%d\n",tree->Inf); 
        }
        
    }
    else return;
}
void printInorder(BNode * tree)
{
    if(tree!=NULL){
        printInorder(tree->ChildLeft);
        printf("%d\n",tree->Inf);
        printInorder(tree->ChildRight);
    }
}
void printPostorder(BNode * tree){
    if(tree!=NULL){
        printPostorder(tree->ChildLeft);
        printPostorder(tree->ChildRight);
        printf("%d\n",tree->Inf);
    }
}
BNode * RandomInsert(BNode * tree, int X)
{
    BNode * newNode, *p;
    newNode=MakeNote(X);
    if(tree==NULL) return newNode;
    if(rand()%2==0){
        p=tree;
        while (p->ChildLeft!=NULL) p=p->ChildLeft;
        p->ChildLeft=newNode;
        printf("Node %d is left child of %d \n",X,p->Inf);
    }
    else
    {
        p=tree;
        while (p->ChildRight!=NULL) p=p->ChildRight;
        p->ChildRight=newNode;
        printf("Node %d is right child of %d \n",X,p->Inf);
    }
    return tree; 
}
int main(){
    BNode * root;
    BNode * pred;
    root=(BNode*)malloc(sizeof(BNode));
    root->ChildLeft=NULL;
    root->ChildRight=NULL;
    insert(root,2);
    insert(root,4);
    insert(root,5);
    insert(root,7);
    insert(root,3);
    insert(root,1);
    insert(root,9);
    pred= find(root,3);
    insert(pred,6);
    pred= find(root,5);
    insert(pred,10);
    insert(pred,8);
    pred= find(root,8);
    insert(pred,11);
    
    printf("\nprintInorder: \n");
    printInorder(root);
    printf("\nprintPostorder: \n");
    printPostorder(root);
    printf("\nprintPreOrder: \n");
    printPreOrder(root);    
    return 0;
}