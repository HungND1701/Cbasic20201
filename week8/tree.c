#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int id;
    struct Node * LeftChild;
    struct Node * Rightsibling;
}Node;
Node * root;
Node * find(Node * r,int v){
    if(r==NULL) return NULL;
    if(r->id==v) return r;
    Node * p = r->LeftChild;
    while(p!=NULL){
        Node * h = find(p,v);
        if(h!=NULL ) return p;
        p=p->Rightsibling;
    }
    return NULL;
}
void preOrder(Node * r){
    if(r==NULL) return;
    printf("%d",r->id);
    Node * p =r->LeftChild;
    while (p!=NULL){
        preOrder(p);
        p=p->Rightsibling;
    }
}
void inOrder(Node * r){
    if(r==NULL) return;
    Node * p = r->LeftChild;
    inOrder(p);
    printf("%d",r->id);
    if(p!=NULL) p = p->Rightsibling;
    while(p!=NULL){
        inOrder(p);
        p=p->Rightsibling;
    }
}
void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->LeftChild;
    while(p != NULL){
        postOrder(p);
        p = p->Rightsibling;
    }
    printf("%d ",r->id);
}
int count(Node* r){
    if(r == NULL) return 0;
    int s = 1;
    Node* p = r->LeftChild;
    while(p != NULL){
        s += count(p);
        p = p->Rightsibling;
    }
    return s;
}
int countLeaves(Node* r){
    if(r == NULL) return 0;
    int s = 0;
    Node* p = r->LeftChild;
    if(p == NULL) s = 1;
    while(p != NULL){
        s += countLeaves(p);
        p = p->Rightsibling;
    }
    return s;
}
int height(Node* p){
    if(p == NULL) return 0;
    int maxh = 0;
    Node* q = p->LeftChild;
    while(q != NULL){
        int h = height(q);
        if(h > maxh) maxh = h;
        q = q->Rightsibling;
    }
    return maxh + 1;
}
int depth(Node* r, int v, int d){
    if(r == NULL) return -1;
    if(r->id == v) return d;
    Node* p = r->LeftChild;
    while(p != NULL){
        if(p->id == v) return d+1;
        int dv = depth(p,v,d+1);
        if(dv > 0) return dv;
        p = p->Rightsibling;
    }
    return -1;
}
int Depth(Node* r, int v){
    return depth(r,v,1);
}
Node* parent(Node* p, Node* r){
    if(r == NULL) return NULL;
    Node* q = r->LeftChild;
    while(q != NULL){
        if(p == q) return r;
        Node* pp = parent(p, q);
        if(pp != NULL) return pp;
        q = q->Rightsibling;
    }
    return NULL;
}
void insert(Node * r, Node * p , int id){
    Node * q;
    q->id=id;
    q->LeftChild=NULL;
    q->Rightsibling=NULL;
    if(r==NULL){
        r=q;
        return;
    }
    if(p->LeftChild== NULL){p->LeftChild = q; return;}
    Node *t = p->LeftChild;
    while (t!=NULL)
    {
        t=t->Rightsibling;
    }
    t->LeftChild= q;
    return;
}