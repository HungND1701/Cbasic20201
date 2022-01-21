#include<stdio.h>
void CharReadWrite(FILE *fptr1,FILE *fptr2){
    int c;
    while ((c=fgetc(fptr2))!=EOF)
    {
        fputc(c,fptr1);
        putchar(c);
    }
    
}
enum{SECCESS,FAIL};

int main(){
    FILE *fptr1,*fptr2;
    char filename1[]="lab1a.txt";
    char filename2[]="lab1.txt";
    int reval=SECCESS;
    if((fptr1=fopen(filename1,"w+"))==NULL){
        printf("Cannot open %s\n",filename1);
        reval=FAIL;
    }else if((fptr2=fopen(filename2,"r"))==NULL){
        printf("Cannot open %s \n",filename2);
        reval=FAIL;
    }else {
        CharReadWrite(fptr1,fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}