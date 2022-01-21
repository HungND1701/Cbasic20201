#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *my_strcat(char * str1,char *str2){
    int len1,len2;
    char * result;
    len1=strlen(str1);
    len2=strlen(str2);
    result=(char*) malloc ((len1+len2+1)*sizeof(char));
    if(result==NULL){
        printf("Allocation failed! Check memory\n");
        return NULL;
    }
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;

}
int main(){
    char str1[100],str2[100];
    printf("Please Enter frist string now : ");
    scanf("%100s", str1);
    printf("Please Enter second string now : ");
    scanf("%100s", str2);
    printf("%s",str1);
    printf("%s",str2);
    char *cat_str=my_strcat(str1,str2);
    if (cat_str == NULL){
        printf("Problem allocating memory!\n");
        return 1;
    }
    puts(cat_str);
    free(cat_str);
    return 0;
}