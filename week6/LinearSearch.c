#include<stdio.h>
#define MAX 11
int M[11];
int LinearSearch(int * M){
    int X=M[10],k=0;
    while (M[k]!=X)
    {
        k++;
    }
    if(k!=10) return k;
    return -1;
}
void input(){
    printf("Nhap 11 phan tu cua mang: \n");
    for(int i=0;i<=10;i++){
        scanf("%d",&M[i]);
    }
}
int main(){
    input();
    if(LinearSearch(M)==-1) printf("Khong tim thay phan tu %d\n",M[10]);
    else printf("phan tu %d dung o vi tri thu %d trong day \n",M[10],LinearSearch(M)+1);
    return 0;
}