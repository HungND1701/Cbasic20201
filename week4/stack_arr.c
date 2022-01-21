#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define Nmax 1000
typedef int Item;
Item *Stack;
int N;
void StackInit(){
    Stack=(Item*)malloc(Nmax*sizeof(Item));
    N=0;
}
Item push(Item X){
    N=N+1;
    Stack[N-1]=X;
    return X;
}
bool isEmpty(){
    if(N==0) return true;
    else return false;
}
Item pop(){
    if(isEmpty()){
        printf("Empty stack\n");
        return -1;
    }else{
        N=N-1;
        return Stack[N];
    }
}
Item top(){
    return Stack[N-1];
}
int size(){
    return N;
}
int main(){
    srand(time(0));
    StackInit();
    int x=rand()%10,j;
    printf("%d\n\n",x);
    for(int i=0;i<x;i++){
        int j=rand()%100;
        push(j);
        printf("%d\n",j);
    }
    printf("=============\n");
    while(N!=0)
    {
        printf("%d\n",pop());
    }
    return 0;
}