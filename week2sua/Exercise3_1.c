#include<stdio.h>
#include<string.h>
enum {SUCCESS,FAIL,MAX_LEN=80};
void blockcat(FILE * fin);
int main(int agrc,char* agrv[]){
    FILE * file1, *file2;
    int reval = SUCCESS;
    if(agrc!=2){
        printf("The correct syntax should be : cat1 filename \n");
        reval = FAIL;
    }
    if((file1=fopen(agrv[1],"r"))==NULL){
        printf("Cannot open %s.\n",agrv[1]);
        reval = FAIL;   
    }else {
        blockcat(file1);
        fclose(file1);
    }
    return reval;
}
void blockcat(FILE * fin){
    int num;
    char buff[MAX_LEN+1];
    while (!feof(fin))
    {
        num=fread(buff,sizeof(char),MAX_LEN,fin);
        buff[num*sizeof(char)]='\0';
        printf("%s",buff);
    }
    
}