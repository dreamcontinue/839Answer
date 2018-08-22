#include <stdio.h>
#include <stdlib.h>
//不妨认为该线性表带头结点
//L、L1、L2分别是指向线性表头结点的指针，L1和L2初始时为NULL
typedef struct LNode{
    int data;
    LNode* next;
}LNode;

void split(LNode* L,LNode** L1,LNode** L2){
    *L1=(LNode*)malloc(sizeof(LNode));
    (*L1)->next=NULL;
    *L2=(LNode*)malloc(sizeof(LNode));
    (*L2)->next=NULL;
    LNode* LN1=*L1,*LN2=*L2;
    int index=0;
    while(L){
        if(L->data<index++){
            LN1->next=(LNode*)malloc(sizeof(LNode));
            LN1=LN1->next;
            LN1->data=L->data;
            LN1->next=NULL;
        }else{
            LN2->next=(LNode*)malloc(sizeof(LNode));
            LN2=LN2->next;
            LN2->data=L->data;
            LN2->next=NULL;
        }
        L=L->next;
    }
}

int main(){
    LNode *Head=(LNode*)malloc(sizeof(LNode));
    Head->next=NULL;
    LNode *node=Head;
    for(int i=0;i<10;i++){
        node->next=(LNode*)malloc(sizeof(LNode));
        node=node->next;
        node->data=rand()%1000-500;
        node->next=NULL;
    }
    LNode *L1,*L2;
    split(Head,&L1,&L2);
    Head=Head->next;
    L1=L1->next;
    L2=L2->next;
    while(Head){
        printf("%d-->",Head->data);
        Head=Head->next;
    }
    printf("END");

    printf("\nL1:\n");
    while(L1){
        printf("%d-->",L1->data);
        L1=L1->next;
    }
    printf("END");
    printf("\nL2:\n");
    while(L2){
        printf("%d-->",L2->data);
        L2=L2->next;
    }
    printf("END");
}
