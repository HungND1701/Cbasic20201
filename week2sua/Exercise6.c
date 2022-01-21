#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{SUCCESS,FAIL,MAX_ELEMENT= 20};
typedef struct phoneaddress{
    char name[20];
    char tel[20];
    char email[25];
}phoneaddress;
int main(void){
    FILE *fp;
    phoneaddress *phonearr;
    int i,n, irc;
    int reval = SUCCESS;
    printf("Read from 2sd data to 3rd data \n");
    if((fp=fopen("phonebook.dat","r+b"))==NULL){
        printf("Can not open %s\n","phonebook.dat");
        reval = FAIL;
    }
    phonearr = (phoneaddress *)malloc(2*sizeof(phoneaddress));
    if(phonearr=NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if(fseek(fp,1*sizeof(phoneaddress),SEEK_SET)!=0){
        printf("Fseek failed \n");
        return FAIL;
    }
    irc= fread(phonearr,sizeof(phoneaddress),2,fp);
    for(int i=0;i<2;i++){
        printf("%s-",phonearr[i].name);
        printf("%s-",phonearr[i].tel);
        printf("%s\n",phonearr[i].email);
    }
    strcpy(phonearr[1].name,"Lan Hoa");
    strcpy(phonearr[1].tel,"0923456");
    strcpy(phonearr[1].email,"asfhdjsh");

    fseek(fp,1*sizeof(phoneaddress),SEEK_SET);
    irc=fwrite(phonearr,sizeof(phoneaddress),2,fp);
    printf("fwrite return code = %d\n",irc);
    fclose(fp);
    free(phonearr);
    return reval;
}