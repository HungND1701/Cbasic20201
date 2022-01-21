#include <stdio.h>
#include<stdlib.h>./b
enum {SUCCESS, FAIL, MAX_LEN = 80};
void BlockReadWrite(FILE *fin, FILE *fout);
int main(int agrc,char* agrv[]) {
    if(agrc!=3){
         printf("%s <file1> <file2>\n",agrv[0]); 
         exit(1);
    }
    FILE *fptr1, *fptr2;
    int reval = SUCCESS;
    if ((fptr1 = fopen(agrv[1], "w+")) == NULL){
        printf("Cannot open %s.\n", agrv[1]);
        reval = FAIL;} 
    else if ((fptr2 = fopen(agrv[2], "r")) == NULL){
        printf("Cannot open %s.\n", agrv[2]);
        reval = FAIL;} 
        else {
            BlockReadWrite(fptr2, fptr1);
            fclose(fptr1);
            fclose(fptr2);
            }    
    return reval; 
}
void BlockReadWrite(FILE *fin, FILE *fout) {
    int num;
    char buff[MAX_LEN + 1];
    while (!feof(fin)){
        num = fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num * sizeof(char)] = '\0';
        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
        }
    }