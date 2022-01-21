// tim kiem hoc sinh dua vao diem va ten
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct Student_t{
    char name[20];
    char id[11];
    int grade;
}Student;
typedef struct list_Student{
    Student student;
    int stt;
    struct list_Student * next;
    struct list_Student * pre;
}List;
typedef struct Root{
    List * next;
}Root;
typedef struct Last{
    List * pre;
}Last;
Root * root;
Last * last;
int stt=0;
List* makenode(Student A){
    List * Node=(List*)malloc(sizeof(List));
    strcpy(Node->student.name,A.name);
    strcpy(Node->student.id,A.id);
    Node->student.grade=A.grade;
    Node->next=NULL;
    Node->pre=NULL;
    return Node;
}
void push(List * NewNode){
    if(root->next== NULL){
        root->next=NewNode;
        last->pre=NewNode;
        NewNode->next=last;
        NewNode->pre=root;
        return;
    }
    else{
        last->pre->next=NewNode;
        NewNode->pre=last->pre;
        last->pre=NewNode;
        NewNode->next=last;
        return;
    }
}
int BinSearch_name(Root * first, char name[],Last * last){
    if(first->next==NULL){
        return -1;
    }
    else {

    }
}
int main(){


    return 0;

}