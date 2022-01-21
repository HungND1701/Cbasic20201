#include<stdio.h>
#include<stdlib.h>
#define MAX 100
enum {SUCCESS, FAIL, MAX_ELEMENT = 20};
typedef struct phone_number
{
    char name[MAX];
    char phone[MAX];
    char email[MAX];

} phone_number;
int main(){
    int n;
    FILE *fp;
    int reval = SUCCESS;
    printf("Nhap so phan tu :\n");
    scanf("%d",&n);
    getchar();
    phone_number book_phone[n];
    for(int i=0;i<n;i++){
        printf("******** People %d********\n",i+1);
        printf("Name : "); fgets(book_phone[i].name,sizeof(book_phone[i].name),stdin);
        
        printf("phone : "); fgets(book_phone[i].phone,sizeof(book_phone[i].phone),stdin);
         
        printf("email : "); fgets(book_phone[i].email,sizeof(book_phone[i].email),stdin);
    }
    if ((fp = fopen("phonebook.dat","w+b")) == NULL){
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    } 
    int irc = fwrite(book_phone, sizeof(phone_number), n, fp);
    printf(" fwrite return code = %d\n", irc); fclose(fp);
    return 0;
}
