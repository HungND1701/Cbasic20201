#include<stdio.h>
#include<stdlib.h>
enum{SUCCESS,FAIL};
void reverse_num(FILE *,int *,int ,int );
int main(int argc,char*argv[]){
    if(argc!=2){
        printf("Usage: %s <file1> \n",argv[0]);
        exit(1);
    }
    int reval = SUCCESS;
    FILE *fout;
    if((fout=fopen(argv[1],"w+"))==NULL){
        printf("Canoot open file %S",argv[1]);
        reval=FAIL;
    }
    int *p,n,sum=0;
    printf("Enter a list of numbers with the first is the size of list: \n");
    scanf("%d", &n);
    p=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        sum+=p[i];
    }
    reverse_num(fout,p,sum,n);
    fclose(fout);
    return reval;
}
void reverse_num(FILE*fout,int *p,int sum,int n){
   for(int i=0;i<n;i++){
       fprintf(fout,"%d ",p[i]);
   }
    fprintf(fout,"%d \n",sum);
}