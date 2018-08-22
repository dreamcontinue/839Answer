
#include <cstdio>
#include <stdlib.h>
#include <string.h>

enum color{
    red,yellow,blue
};
color c[3]={red,yellow,blue};

void swap(color** a,color** b){//元素为指向color的指针的指针
    color *c=*a;
    *a=*b;
    *b=c;
}

color inspect(color* elem){
    return *elem;
}

void holland(color* pc[],int n){
    //rr:已分为红色块的最后一块下标 bh:已分为蓝色块的第一块下标
    int rr=-1,bh=n,i=0;
    while (i<bh) {
        switch (inspect(pc[i])) {
            case red: swap(pc+i++, pc+(++rr)); break;
            case blue: swap(pc+i, pc+--bh); break;
            case yellow: i++; break;
        }
    }
}

int main(){
    color* pc[]={&c[1],&c[0],&c[0],&c[2],&c[1],&c[2],&c[0],&c[2]};
    //for(int i=0;i<100;i++)pc[i]=&c[rand()%3];
    holland(pc, sizeof(pc)/sizeof(pc[0]));
    for(int i=0;i<sizeof(pc)/sizeof(pc[0]);i++)
        printf("%d ",inspect(pc[i]));
}