#include<stdio.h>
typedef struct element_t{
    int key;
}element;
void Swap(element A[],int a,int b){
    element tmp;
    tmp= A[a];
    A[a]=A[b];
    A[b]=tmp;
}
void Max_Heapify(element A[],int i,int n){
    int left= 2*i+1;
    int right= 2*i+2;
    int largest;
    if(left<n && A[left].key>A[i].key) largest = left;
    else largest= i;
    if(right<n&& A[right].key>A[largest].key) largest= right;
    if(largest!=i){
        Swap(A,i,largest);
        Max_Heapify(A,largest,n);
    }
}
void Build_Max_Heap(element A[],int n){
    for(int i=n/2-1;i>=0;i--){
        Max_Heapify(A,i,n);
    }
}
void HeapSort(element A[],int n){
    Build_Max_Heap(A,n);
    for(int i=n-1;i>=1;i--){
        Swap(A,i,0);
        Max_Heapify(A,0,i);
    }
}
int main(){
    element A[5];
    A[0].key=7;
    A[1].key=4;
    A[2].key=3;
    A[3].key=1;
    A[4].key=2;
    HeapSort(A,5);
    for(int i=0;i<=4;i++){
        printf("%d ",A[i].key);
    }
    printf("\n");
    return 0;
}