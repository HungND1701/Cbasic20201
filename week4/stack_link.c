#include<stdio.h>
#include<stdlib.h>
typedef float Item;
typedef struct StackNode{
    Item Inf;
    struct StackNode * next;
}StackNode;
typedef struct Stack
{
    StackNode *top;
}Stack;
int StackEmpty(const Stack *s){
    return (s->top==NULL);
}
Stack *StackConstruct(){
    Stack * s;
    s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
    s->top=NULL;
    return s;   
}
int StackFull(){
    printf("\n No Memory, Stack is Full\n");
    getc(stdin);
    return 1;
}
void disp(Stack *s){
    StackNode * node;
    int ct=0;float m;
    printf("\n\n Danh Sach Cac phan tu cua Stack\n\n");
    if(StackEmpty(s)){
        printf("\n\n >>>>> EMPTY STACK <<<<<\n");
        getchar();
    }else{
        node = s->top;
        do{
            m=node->Inf;
            printf("%8.3f ",m); ct++;
            if(ct%9==0) printf("\n");
            node=node->next;
        }while(!(node==NULL));
        printf("\n");
    }
}
int StackPush(Stack *s, Item X){
    StackNode * node;
    node=(StackNode*)malloc(sizeof(StackNode));
    if(node==NULL){
        StackFull();
        return 1;
    }
    node->Inf=X;
    node->next=s->top;
    s->top=node;
    return 0;
}
Item StackPop(Stack *s){
    Item X;
    StackNode * node;
    if(StackEmpty(s)){
        return -1;
    }
    node=s->top;
    X=node->Inf;
    s->top=node->next;
    free(node);
    return X;
}
void StackDestroy(Stack *s){
    while(!StackEmpty(s)){
        StackPop(s);
    }
    free(s);

}
int main(){
    int ch,n,i;
    Item m;
    Stack* stackPtr;
    while(1){
        printf("\n\n=====================\n");
        printf("CHUONG TRINH THU STACK\n");
        printf("======================\n");
        printf("   1.Push back\n");
        printf("   2.front-back \n");
        printf("   3.Pop\n");
        printf("   4.Display\n");
        printf("   5.Exit\n");
        printf("----------------------\n");
        printf("Chon chuc nang: ");
        scanf("%d",&ch);\
        printf("\n\n");
        switch(ch){
            case 1:
                printf("Da khoi tao STACK");
                stackPtr=StackConstruct();
                break;
            case 2:
                printf("Vao gia tri phan tu: ");
                scanf("%f",&m);
                printf("Gia tri phan tu nhap vao : %8.3f\n",m);
                StackPush(stackPtr,m);
                break;
            case 3:
                m=StackPop(stackPtr);
                if(m!=-1){
                    printf("\n\n Gia tri phan tu lay ra la : %8.3f\n",m);
                    getchar();
                }
                else {
                    printf("\n\n 2 >>> Empty Stack, can't pop <<<\n");
                    getchar();
                }
                break;
            case 4:
                disp(stackPtr);
                break;
            case 5:
                printf("\n Bye ! Bye ! \n\n");
                getchar();
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                getchar();
        }
    }
   

}