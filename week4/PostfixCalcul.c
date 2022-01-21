#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int stack[1000];
int top;
//tinh gia tri bieu thuc 
int eval(char *s);
//kiem tra co phai phep toan
int isop(char op);
//day ra
int pop(void);
//day vao 
void push (int a);
//thuc hien phep toan
int do_op(int a ,int b,char op);

int main(void){

    char expression[80];
    int value;
    printf("Nhap vao xau bieu thuc: ");
    gets(expression);
    printf("Bieu thuc nhap vao la : %s\n",expression);
    value=eval(expression);
    printf("Gia tri cua bieu thuc la : %d \n",value);
    getchar();
    return 0;
}

int eval(char *s){
    char *ptr;
    int first,second,c;
    ptr=strtok(s," ");
    top=-1;
    while (ptr)
    {
        if(isop(*ptr)){
            second = pop();
            first=pop();
            c=do_op(first,second,*ptr);
            push(c);
        }
        else{
            c=atoi(ptr);push(c);
        }
        ptr=strtok(NULL," ");
    }
    return (pop());
}
int do_op(int a,int b,char op){
    int ans;
    switch (op)
    {
    case '+':
        ans=a+b;
        break;
    case '-':
        ans=a-b;
        break;
    case '*':
        ans=a*b;
        break;
    case '/':
        ans=a/b;
        break;
    default:
        break;
    }
    return ans;
}
int pop(void){
    int ret;
    ret=stack[top];
    top --;
    return ret;
}
void push(int a){
    top ++;
    stack[top]=a;
}
int isop(char op){
    if(op=='+'||op=='-'||op=='*'||op=='/') return 1;
    else return 0;
}