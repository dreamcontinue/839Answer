#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct LINK{
    int data;
    struct LINK* next;
}LINK;

//不妨认为该线性带头结点
void RemoveDuplicates(LINK* head){
    if(!head||!(head->next))return;
    head=head->next;
    LINK* work,*tmp;
    while (head) {//删除所有和head值相等后续的结点
        work=head;//work为待判断结点的前驱
        while (work->next)
            if(work->next->data==head->data){
                //work->next和head值一样，那么删除work->next
                tmp=work->next;
                work->next=tmp->next;
                free(tmp);
            }else work=work->next;
        head=head->next;
    }
}

int main(){
    LINK* Head=(LINK*)malloc(sizeof(LINK)),*node=Head;
    Head->next=NULL;
    
    for(int i=0;i<100;i++){
        node->next=(LINK*)malloc(sizeof(LINK));
        node=node->next;
        node->data=i%10;
        node->next=NULL;
    }
    
    node=Head->next;
    while (node) {
        printf("%d-->",node->data);
        node=node->next;
    }
    puts("end");
    
    RemoveDuplicates(Head);
    
    node=Head->next;
    while (node) {
        printf("%d-->",node->data);
        node=node->next;
    }
    puts("end");
}

