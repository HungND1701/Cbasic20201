#include<stdio.h>
int main(){
    int A[10];
    printf("please enter 10 numbers:\n");
    for(int i=0; i<10; i++) scanf("%d", &A[i]);
    printf("\n");
    int x=0,B[10];
    B[0]=A[0];
    for(int i=1;i<10;i++){
        int dem=0;
        for(int j=0;j<i;j++){
            if(A[i]==A[j]) dem++;
        }
        if(dem==0){
        x++;
        B[x]=A[i];
        } 
    }
    for(int i=0;i<=x;i++) printf("%d ",B[i]);
    return 0;
}