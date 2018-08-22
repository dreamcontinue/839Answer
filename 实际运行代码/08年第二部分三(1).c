#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct LINK{
    int data;
    struct LINK* next;
}LINK;

//不妨认为该线性不带头结点
void RemoveDuplicates(LINK* head){
    if(!head)return;
    LINK* tmp;
    while (head->next) {
        if(head->next->data==head->data){
            tmp=head->next;
            head->next=tmp->next;
            free(tmp);
        }else head=head->next;
    }
}

int main(){
    LINK* Head=(LINK*)malloc(sizeof(LINK)),*node=Head;
    Head->next=NULL;
    Head->data=0;
    
    node->next=(LINK*)malloc(sizeof(LINK));
    node=node->next;
    node->data=0;
    node->next=NULL;
    node->next=(LINK*)malloc(sizeof(LINK));
    node=node->next;
    node->data=0;
    node->next=NULL;
    node->next=(LINK*)malloc(sizeof(LINK));
    node=node->next;
    node->data=1;
    node->next=NULL;
    node->next=(LINK*)malloc(sizeof(LINK));
    node=node->next;
    node->data=1;
    node->next=NULL;
    
    node=Head;
    while (node) {
        printf("%d-->",node->data);
        node=node->next;
    }
    puts("end");
    
    RemoveDuplicates(Head);
    
    node=Head;
    while (node) {
        printf("%d-->",node->data);
        node=node->next;
    }
    puts("end");
    
}
