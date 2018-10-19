#include <stdio.h>

void sort(int* p,int n){
    if(n<=1)return;
    int mini=0,tmp;
    for(int i=0;i<n;i++)//找到n个中最小数的下标
        if(p[mini]>p[i])
            mini=i;
    tmp=p[mini];
    p[mini]=p[0];
    p[0]=tmp;
    sort(p+1,n-1);
}

int main(){
    int p[9]={9,7,2,0,3,3,2,9,4};
    for(int i=0;i<9;i++)printf("%d ",p[i]);
    puts("");
    sort(p,9);
    
    for(int i=0;i<9;i++)printf("%d ",p[i]);
}
