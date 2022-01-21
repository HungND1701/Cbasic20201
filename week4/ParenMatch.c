#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct  ParenMatch
{
    struct ParenMatch *next;
    char Paren;
}ParenMatch;
typedef struct StackParen
{
    ParenMatch * top;
}StackParen;
char X[]={'(',')','(','(',')',')','{','(','[','(',')',']',')','}'};
char Y[]={')','{','(',')','}','{','(','[','(',')',']',')','}'};
bool isEmpty(const StackParen *s){
    return (s->top==NULL);
}
StackParen * StackConstruct(){
    StackParen * s;
    s=(StackParen*)malloc(sizeof(StackParen));
    if(s==NULL) return NULL;
    s->top=NULL;
    return s;
}
int StackPush(StackParen *s,char X){
    ParenMatch * node;
    node=(ParenMatch*)malloc(sizeof(ParenMatch));
    if(node==NULL){
        printf("Stack full memory!\n");
        return 1;
    }
    node->Paren=X;
    node->next=s->top;
    s->top=node;
    return 0;
}
char StackPop(StackParen *s){
    char X;
    ParenMatch * node;
    if(isEmpty(s)){
        return -1;
    }
    node=s->top;
    X=node->Paren;
    s->top=node->next;
    free(node);
    return X;
}
bool NgoacMo(char X){
    if(X=='('||X=='['||X=='{') return true;
    else return false;
}
bool NgoacDong(char X){
    if(X==')'||X==']'||X=='}') return true;
    else return false;
}
bool KiemTra(StackParen *s,char X){
    if(X==')') X='(';
    if(X=='}') X='{';
    if(X==']') X='[';
    if(StackPop(s)==X) return true;
    else return false;
}
bool ParenMatching(char * X,int n){
    StackParen * S;
    S=StackConstruct();
    for(int i=0; i<n;i++){
        if(NgoacMo(X[i])) StackPush(S,X[i]);
        else if(NgoacDong(X[i])){
                if(isEmpty(S)) return false;
                if(!KiemTra(S,X[i])) return false;
              }
    }
    if(isEmpty(S)) return true;
    else return false;
}
int main(){
    if(ParenMatching(X,14)) printf("True\n");
    else printf("False\n");
    if(ParenMatching(Y,13)) printf("True\n");
    else printf("False\n");
    return 0;
}