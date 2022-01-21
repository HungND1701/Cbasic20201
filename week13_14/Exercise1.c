#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int BruteForceMatch(char T[],char P[]){
    int n= strlen(T);
    int m = strlen(P);
    for(int i=0 ; i<=n-m;i++){
        int j=0;
        while (j<m && T[i+j]==P[j]) j++;
        if(j==m) return i;
    }
    return -1;
}
int main(){
    char T[]="bcadacaeeeffaadbfacddedcedfbeccae";
    char P[]="aadbf";
    printf("%d",BruteForceMatch(T,P));
    return 0;
}