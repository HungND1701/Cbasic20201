#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertion_sort(int A[],int n){
    int i,j;
    int next;
    for(i=1;i<n;i++){
        next= A[i];
        for(j=i-1;j>=0 && next<A[j];j--){
            A[j+1]=A[j];
        }
        A[j+1]=next;
    }
}
int main(){
    int n;
    printf("Nhap n : ");
    scanf("%d",&n);
    int A[n];
    srand(time(NULL));
    for(int i=0;i<n;i++){
        A[i]=rand()%100;
    }
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    insertion_sort(A,n);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}