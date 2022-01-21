#include<stdio.h>
#define MAX_SIZE 1000
typedef struct{
    int key;
}element;
element list[MAX_SIZE];

int binsearch(element list[],int searchnum,int n){
    int left=0, right=n-1,middle;
    while (left<=right)
    {
        middle =(left+right)/2;
        switch(COMPARE(list[middle].key,searchnum)){
            case -1: 
                left=middle+1;
                break;
            case 0:
                return middle;
            case 1:
                right=middle-1;
        }
        return -1;
    }
    
}