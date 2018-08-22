#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int f(int a[],int n,int* count){
    *count=0;int ans,frqNum;
    for(int i=0;i<n;i++){
        ans=0;
        for(int j=i;j<n;j++)
            if(a[i]==a[j])ans++;
        if(ans>*count){
            *count=ans;
            frqNum=a[i];
        }
    }
    return frqNum;
}

int main(){
    int a[]={9,7,2,0,3,3,2,9,4},count;
    printf("%d %d",f(a,sizeof(a)/sizeof(a[0]),&count),count);
}