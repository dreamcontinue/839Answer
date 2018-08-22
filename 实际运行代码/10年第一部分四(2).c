#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//a[0...n-1]的m个组合排列,当前处于第i个下标,组合排列中已有k个,b储存组合排列,b[0...k-1]
void comb(char a[],int n,int m,int i,int k,char b[]){
    if(k==m){//完成组合排列
        b[k]='\0';
        puts(b);
        return;
    }
    if(n-i+1<=m-k)return;//剩余元素过少，不能完成排列
    
    b[k]=a[i];
    comb(a,n,m,i+1,k+1,b);//a[i]加入组合后递归
    comb(a,n,m,i+1,k,b);//a[i]不加入组合后递归
}

int main(){
    printf("输入n,m和s:\n");
    char a[100],b[100];int n,m;
    scanf("%d%d%s",&n,&m,a);
    comb(a,n,m,0,0,b);
}