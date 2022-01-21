#include<stdio.h>
#include<string.h>
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
void SWAP(phoneaddress phonebook[],int i,int j){
    phoneaddress temp;
    temp=phonebook[i];
    phonebook[i]=phonebook[j];
    phonebook[j]=temp;
}
void QuickSort(phoneaddress phonebook[],int left,int right){
    int  i, j;
    char pivot[20];
    phoneaddress temp;
    if (left < right) {
        i = left;    
        j = right+1;
        strcpy(pivot,phonebook[left].name);
        do {
            do i++; while (strcmp(phonebook[i].name,pivot)<0);
            do j--; while (strcmp(phonebook[j].name,pivot)>0);
            if (i < j) SWAP(phonebook,i,j);
            } while (i < j);
        SWAP(phonebook,left,j);
        QuickSort(phonebook, left, j-1);
        QuickSort(phonebook, j+1, right);
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
    QuickSort(phonebook,0,9);
    for(int i=0;i<10;i++){
        printf("%s-",phonebook[i].name);
        printf("%s-",phonebook[i].tel);
        printf("%s\n",phonebook[i].email);
    }
    FILE * wfile;
    if((wfile=fopen("Quick_Sort.dat","w+"))==NULL){
        printf("Cannot open file %s \n","Quick_Sort.dat");
        return 0;
    }
    int irc2= fwrite(phonebook,sizeof(phonebook),10,wfile);
    printf("fwrite return %d\n",irc2);
    fclose(wfile);
    return 0;
}
