#include<stdio.h>
void split(double a,int *integer,double *frac){
    *integer = (int)a;
    *frac= a-*integer;
}
int main(){
    double a,frac;
    int integer;
    printf("input double number : ");
    scanf("%lf",&a);
    printf("double number : %lf ",a);
    split(a,&integer,&frac);
    printf("integer path : %d\n",integer);
    printf("fraction path : %lf\n",frac);

    return 0;
}