/* Tao mang 100 ptu 1->100
Doc ki tu dau vao input
In ra Not Found neu ko tim thay
In ra chi so mang va so phep so sanh cho den khi tim thay 
*/
#include <stdio.h>
#define MAX 100
int dem=0;
int BinarySearch(int *A,int X, int Low,int High)
{
    if(Low>High){
        dem++;
        return -1;
    }
    int Mid;
    Mid=(High+Low)/2;
    if(A[Mid]==X){
        dem++;
        return Mid;
    }
    if(A[Mid]<X){
        dem++;
        return BinarySearch(A,X,Mid+1,High);
    }
    else{
        dem++;
        return BinarySearch(A,X,Low,Mid-1);
    }
    return -1;
}
int main()
{
    int A[MAX],X;
    for(int i=0;i<100;i++) A[i]=i+1;
    printf("Nhap so can tim kiem : ");
    scanf("%d",&X);
    if(BinarySearch(A,X,0,99)==-1) printf("Not found \n");
    else{
        printf("vi tri : %d ",BinarySearch(A,X,0,99));
        printf("so phep so sanh : %d",dem);
    }
    return 0;
}