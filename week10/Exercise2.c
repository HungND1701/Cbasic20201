#include<stdio.h>
#include<string.h>
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
void Selection_sort(phoneaddress phonebook[],int n){
    int i,j,min;
    phoneaddress tmp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<=n-1;j++){
            if(strcmp(phonebook[j].name,phonebook[min].name)<0)
            min=j;
        }
        tmp=phonebook[i];
        phonebook[i]=phonebook[min];
        phonebook[min]=tmp;
    }
}
int main(){
    phoneaddress phonebook[100];
    FILE * rfile;
    if((rfile= fopen("phonebook.dat","r"))==NULL){
        printf("Cannot open file : %s\n","phonebook.dat");
        return 0;
    }
    int irc1=fread(phonebook,sizeof(phoneaddress),10,rfile);
    printf("fread return %d\n",irc1);
    fclose(rfile);
    Selection_sort(phonebook,10);
    for(int i=0;i<10;i++){
        printf("%s-",phonebook[i].name);
        printf("%s-",phonebook[i].tel);
        printf("%s\n",phonebook[i].email);
    }
    FILE * wfile;
    if((wfile=fopen("Exercise_1.dat","w+"))==NULL){
        printf("Cannot open file %s \n","Exercise_1.txt");
        return 0;
    }
    int irc2= fwrite(phonebook,sizeof(phonebook),10,wfile);
    printf("fwrite return %d\n",irc2);
    fclose(wfile);
    return 0;
}
