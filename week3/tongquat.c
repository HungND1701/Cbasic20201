#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
typedef int ElementType;
typedef struct Pointer_Type{
    ElementType Inf;
    struct Pointer_Type *next;
}PointerType;
PointerType * MakeNote(ElementType X){
     PointerType * Note;
     Note=(PointerType* )malloc(sizeof(PointerType));
     Note->Inf=X;
     return Note;
}
PointerType *Insert_Middle(PointerType * Pred,ElementType X){
    PointerType* TempNode;
    TempNode=(PointerType*)malloc(sizeof(PointerType));
    TempNode->Inf=X;
    TempNode->next=Pred->next;
    Pred->next=TempNode;
    return TempNode;
}
ElementType Delete(PointerType * Pred){
    ElementType X;
    PointerType * TempNode;
    TempNode=Pred->next;
    Pred->next=Pred->next->next;
    X=TempNode->Inf;
    free(TempNode);
    return X;
}
PointerType * Insert_toHead(PointerType * First , ElementType X){
    PointerType * TempNode;
    TempNode=(PointerType* )malloc(sizeof(PointerType));
    TempNode->Inf=X;
    TempNode->next=First;
    First=TempNode;
    return First;
}
PointerType * Insert_toLast(PointerType * First, ElementType X){
    PointerType * TempNode; PointerType*NewNode;
    NewNode=(PointerType*)malloc(sizeof(PointerType));\
    NewNode->Inf=X;
    TempNode=First;
    while (TempNode->next!=NULL)
    {
        TempNode=TempNode->next;
    }
    TempNode->next=NewNode;
    NewNode->next=NULL;
    return First;
}
PointerType * Delete_Head(PointerType * First){
    PointerType *TempNode;
    TempNode=First->next;
    free(First);
    return TempNode;
}
PointerType * Delete_Last(PointerType* First){
    PointerType *TempNode1;
    PointerType *TempNode2;
    TempNode1=First;
    while (TempNode1->next!=NULL)
    {   
        TempNode2=TempNode1;
        TempNode1=TempNode1->next;
    }
    TempNode2->next=NULL;
    free(TempNode1);
    return First;
}
int IsEmpty(PointerType * First){    //kiem tra list rong
    return !First;
}
PointerType *MakeNULL(PointerType* First){  //Xoa List
    while (IsEmpty(First)){
        First=Delete_Head(First);
        return First;
    }    
}
void Print(PointerType * First){
    PointerType* TempNode;
    TempNode=First;
    int count=0;
    while (TempNode)
    {
        printf("%6d ",TempNode->Inf);
        TempNode=TempNode->next;
        if(count%12==0) printf("\n");
    }
    printf("\n");
}
int main(){
    PointerType *S1,*S2,*S3,*V1,*V2,*V3,*pred;
    ElementType a;
    int i,n;
    S1=NULL;
    //Tao Phan tu dau tien 
    srand(time(0));
    a=-100+rand()%200;
    S1=Insert_toHead(S1,a);
    printf("Nhap so phan tu : ");
    scanf("%d",&n);
    // tao ngau nhien danh sach va dua ra man hinh 
    V1=S1;
    for(i=2;i<=n;i++){
        a=-100+rand()%200;
        V1=Insert_toLast(V1,a);
    }
    pred=V1;
    int count=0;
    while(count==2){
    	pred=pred->next;
        count++;
	};
	Insert_Middle(pred,100);
    printf("====> Danh sach Ban dau \n");
    Print(V1); printf("\n");
    V1=S1;S2=NULL;S3=NULL;
    while(V1){
    	if(V1->Inf>0){
    		if(!S2){
    			S2=Insert_toHead(S2,V1->Inf);
    			V2=S2;
			}else{
				V2=Insert_toLast(V2,V1->Inf);
			}
		}
		if(V1->Inf<0){
			if(!S3){
				S3=Insert_toHead(S3,V1->Inf);
				V3=S3;
			}else{
				V3=Insert_toLast(V3,V1->Inf);
			}
		}
		V1=V1->next;
	}
	printf("====> Danh sach so nguyen Duong \n");
    Print(V2); printf("\n");
    printf("====> Danh sach So nguyen Am \n");
    Print(V3); printf("\n");
    
    S1=MakeNULL(S1);S2=MakeNULL(S2);S3=MakeNULL(S3);
    getchar();
    return 0;
}