// Cai dat hang doi theo thu tu vong tron 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000
int N=MAX;
int Q[MAX];
int f=0,r=0;    //f la chi so phan tu o dau hang doi ; r la chi so o ngay sau vi tri phan tu cuoi hang doi
bool isEmpty(){
    return (f==r);
}
int Size(){
    return (N-(f-r))%N;
}
int enqueue(int X){
    if(Size()==(N-1)) {
        printf("Full Queue\n");
        return -1;
    }else {
        Q[r]=X;
        r=(r+1)%N;
    }
}
int dequeue(){
    if(isEmpty()){
        printf("EmptyQueue\n");
        return -100000;
    }else{
        int X=Q[f];
        f=(f+1)%N;
        return X;
    }
}
int main(){
    int ch;
    while(1){
        printf("\n\n=====================\n");
        printf("CHUONG TRINH THU STACK\n");
        printf("======================\n");
        printf("   1.\n");
        printf("   2.Push\n");
        printf("   3.Pop\n");
        printf("   4.Display\n");
        printf("   5.Exit\n");
        printf("----------------------\n");
        printf("Chon chuc nang: ");
        scanf("%d",&ch);\
        printf("\n\n");
        switch(ch){
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            default:
                printf("Wrong choice\n");
                getchar();

        }
    }
    return 0;
}