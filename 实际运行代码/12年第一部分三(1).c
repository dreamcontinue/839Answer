#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;

NODE* Insert(NODE *head,NODE *p){
    if(!head||head->data>p->data){
        p->next=head;
        return p;
    }
    
    NODE* node=head;
    while (node){
        if(!node->next||node->next->data>p->data){
            p->next=node->next;
            node->next=p;
            break;
        }
        node=node->next;
    }
    return head;
}

int main(){
    NODE* p1=(NODE*)malloc(sizeof(NODE));p1->data=1;
    NODE* p5=(NODE*)malloc(sizeof(NODE));p5->data=5;
    NODE* p3=(NODE*)malloc(sizeof(NODE));p3->data=3;
    NODE* p0=(NODE*)malloc(sizeof(NODE));p0->data=0;
    NODE* p1_2=(NODE*)malloc(sizeof(NODE));p1_2->data=1;
    NODE* p6=(NODE*)malloc(sizeof(NODE));p6->data=6;
    NODE* p7=(NODE*)malloc(sizeof(NODE));p7->data=7;
    NODE* head=NULL,*node;
    
    head=Insert(head, p1);
    head=Insert(head, p5);
    head=Insert(head, p3);
    head=Insert(head, p0);
    head=Insert(head, p1_2);
    head=Insert(head, p6);
    head=Insert(head, p7);
    node=head;
    while (node) {
        printf("%d--->",node->data);
        node=node->next;
    }
    puts("end");
}