#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct d_List{
	int num;
	struct d_List *next;
	struct d_List *prev;
}dList; 
dList * push(dList * First,int X){
    dList * temp,*pred=First;
    temp=(dList*)malloc(sizeof(dList));
    temp->num=X;
    if(First==NULL){
        First=temp;
        temp->next=NULL;
    }else{
        while(pred->next!=NULL){
              pred=pred->next;
        }
        pred->next=temp;
        temp->prev=pred;
        temp->next=NULL;
    }
    return First;
}
dList *erase(dList* First,dList* pred){
    dList* a=First;
    while(a->next!=NULL) a=a->next;
    if(pred==a){
        pred->prev->next=NULL;
        free(pred);
        return First;
    }
    if(pred==First){
        First=pred->next;
        free(pred);
        return First;
    }
    pred->prev->next=pred->next;
    pred->next->prev=pred->prev;
    free(pred);
    return First;
}
void Print(dList * First){
    dList* TempNode;
    TempNode=First;
    int count=0;
    while (TempNode)
    {
        printf("%6d ",TempNode->num);
        TempNode=TempNode->next;
        if(count%12==0) printf("\n");
    }
    printf("\n");
}
void Josephus (int n,int m){
    dList * List;
    dList * cur;
    for(int i=1;i<=n;i++) List=push(List,i);
    Print(List);
	cur=List;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m-1;j++){
			cur=cur->next;
			if(cur==NULL) cur=List;
		}
		printf("Xoa khach hang thu %d\n",cur->num);
        dList* a=List;
        while(a->next!=NULL) a=a->next;
		cur=cur->next;
        if(cur==NULL){
            List=erase(List,a);
            cur=List;
        }else List=erase(List,cur->prev);
	}
	printf("\n Khach hang thang cuoc la : %d",cur->num);
	free(cur);
    
}
int main(){
	int n,m;
	printf("Nhap so khach hang : ");
	scanf("%d",&n);
	srand(time(0));
	m=1+rand()%(n-1);
	printf("m=%d\n",m);
	Josephus(n,m);
    return 0;
}