#include<stdio.h>
#include<string.h>
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
void Bubble_sort(phoneaddress phonebook[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(strcmp(phonebook[j].name,phonebook[j-1].name)<0){
                phoneaddress tmp=phonebook[j];
                phonebook[j]=phonebook[j-1];
                phonebook[j-1]=tmp;
            }
        }
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
    Bubble_sort(phonebook,10);
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
