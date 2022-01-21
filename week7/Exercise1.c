#include <stdio.h>
#define NotFound -1
typedef int ElementType;
int BinarySearch (ElementType *A,ElementType X, int Low,int High)
{
    if(Low>High) return NotFound;
    int Mid;
    Mid=(High+Low)/2;
    if(A[Mid]==X) return Mid;
    if(A[Mid]<X) return BinarySearch(A,X,Mid+1,High);
    else return BinarySearch(A,X,Low,Mid-1);
    return NotFound;
}
int main(){
    int A[100];
    for(int i=1;i<=100;i++){
        A[i-1]=i;
    }
    int SizeofA=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<20;i++){
        printf("BinarySearch of %d return %d \n", i, BinarySearch(A,i,0,SizeofA - 1));
    }
    return 0;
}