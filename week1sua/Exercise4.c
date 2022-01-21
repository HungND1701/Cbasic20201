#include<stdio.h>
#include<string.h>
void replace(char *str,char a,char b){
    while (*str!='\0')
    {
        if(*str==a) *str=b;
        str++;
    }
    
}
int main(){
    char str[100],a,b;
    printf("input string : ");
    gets(str);
    printf("input 1st char :"); 
    scanf("%c",&a);
    getchar();
    printf("input 2nt char :"); 
    scanf("%c",&b);
    getchar();
    printf("%s %c %c ",str,a,b);
    replace(str,a,b);
    printf("\n%s",str);
    return 0;
}