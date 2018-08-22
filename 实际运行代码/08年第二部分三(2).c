#include <stdio.h>
//不妨认为T的数组从下标1开始存储,即T[0]内不存放数据,范围T[1...n]
void midTraverse(int T[],int cur,int n){
    if(cur>n)return;
    midTraverse(T, cur*2, n);
    printf("%d ",T[cur]);
    midTraverse(T, cur*2+1, n);
}



int main(){
    int T[]={0,1,2,3,4,5,6,7,8,9,10};//T[0]无数据
    midTraverse(T, 1, 10);
}