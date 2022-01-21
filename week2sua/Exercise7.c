#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum{SUCCESS,FAIL};
void double_space(FILE*,FILE*);
void prn_info(char *);
int main(int argc,char* argv[]){
    int reval=SUCCESS;
    if(argc!=3){
        prn_info(argv[0]);
        exit(1);
    }
    FILE *fin,*fout;
    if((fin=fopen(argv[1],"r"))==NULL){
        printf("Cannot open %s\n",argv[1]);
        reval = FAIL;
    }else if((fout=fopen(argv[2],"w"))==NULL){
        printf("Cannot open %s\n",argv[2]);
        reval = FAIL;
    }
    double_space(fin,fout);
    fclose(fin);
    fclose(fout);
return reval;
}
void double_space(FILE * fin,FILE *fout){
    int c;
    while((c=fgetc(fin))!=EOF){
        fputc(c,fout);
        if(c=='\n'){
            fputc('\n',fout);
        }
    }
}
void prn_info(char *pgm_name){
    printf("\n%s%s%s\n\n%s%s\n\n","Usage:  ", pgm_name, 
    "  infile  outfile","The contents of infile will be double-spaced ","and written to outfile.");
}