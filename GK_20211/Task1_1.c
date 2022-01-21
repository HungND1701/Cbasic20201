/*file phonebook.dat chưa 10 phan tu 
file phonebook.dat chua cac phan tu cua file phonebook.txt
nhap ten can tim (nam trong file phonebook.txt)*/
#include<stdio.h>
#include<string.h>
#define NotFound -1
enum{SUCCESS, FAIL, MAX_ELEMENT =100};
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int BinarySearch(phoneaddress A[], char name[],int N){
    int Low,Mid,High;
    Low=0;High=N-1;
    while (Low<=High)
    {
        Mid=(High+Low)/2;
        if(strcmp(A[Mid].name,name)<0) Low=Mid+1;
        else if(strcmp(A[Mid].name,name)>0) High=Mid-1;
        else return Mid;
    }
    return NotFound;
}
int main(){
    FILE *fp,*fpout;
    phoneaddress phonearr[MAX_ELEMENT];
    int i,n,irc;
    char name[20];
    int reval=SUCCESS;
    printf("How many contacts do you want to enter (<100)?");
    scanf("%d",&n);
    if((fp=fopen("phonebook.dat","rb"))==NULL){
        printf("Can not open %s.\n","phonebook.dat");
        reval = FAIL;
    }
    irc= fread(phonearr,sizeof(phoneaddress),n,fp);
    printf("fread return code = %d \n ",irc);
    fclose(fp);
    if(irc<0){
        printf("Can not read from file !");
        return -1;
    }
    printf("\nLet me know the name you want to search :");
    scanf("%s",name);
    irc=BinarySearch(phonearr,name,n);
    if(irc<0){
        printf("No contact match the criteria !");
        return -1;
    }
    if((fpout=fopen("Ketqua_1.txt","w"))==NULL){
        printf("Can't create file to write.\n");
        reval= FAIL;
    }
    else{
        fprintf(fpout, "%s have the email address %s and telephone number : %s",phonearr[irc].name,phonearr[irc].email,phonearr[irc].tel);
        printf("\n%s have the email address %s and telephone number : %s",phonearr[irc].name,phonearr[irc].email,phonearr[irc].tel);
    }
    fclose(fpout);
    return reval;
}