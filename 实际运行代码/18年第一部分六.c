#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void split(int a[],int n){
    int h=0,r=n-1,t;
    while (h<=r)
        if(a[h]&1)h++;
        else {
            t=a[h];
            a[h]=a[r];
            a[r]=t;
            r--;
        }
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    split(a, 9);
    for(int i=0;i<9;i++)
        printf("%d ",a[i]);
}