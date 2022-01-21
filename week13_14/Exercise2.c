#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int min(int a, int b){
    return a < b ? a : b  ;
}

int * lastOccurenceFunction (char P[], char E[]){
    static int R[5];
    for(int i=0;i<strlen(E);i++){
        int j=strlen(P)-1;
        while (P[j]!=E[i])
        {
            j--;
        }
        R[i]=j;
    }
    return R;
}

int Boyer_Moore_Matching(char T[],char P[] , char E[]){
    int *L;
    L = lastOccurenceFunction(P,E);
    int m = strlen(P);
    int n = strlen(T);
    int i=m-1;
    int j=m-1;
    while (i<=n-1)
    {
        if(T[i]==P[i]){
            if(j==0) return i;
            else{
                i=i-1;
                j=j-1;
            }
        }
        else{
            int l = L[(int)(T[i])-'a'];
            i=i + m - min(j,l+1);
            j= m - 1;
        }
    }
    return -1;
    
}
int main(){
    char E[]="abcdf";
    char T[]="abcadacaeeeffaadbfacddedcedfbeccae";
    char P[]="aadbf";
    char L[strlen(E)];
    printf("%d",Boyer_Moore_Matching(T,P,E));
    return 0;
}