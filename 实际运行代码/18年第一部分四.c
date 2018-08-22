#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//可以通过二分法,注意正负以及0...1和1...n的情况
//以下通过牛顿迭代法
double cub(double n){
    double eps=1e-4,r=n;
    while (abs(r*r*r-n)>eps) {
        r=2*r/3+n/3/r/r;
    }
    return r;
}

double cub2(double n){
    double eps=1e-4,low,high,mid;
    int flag=n>0?1:-1;
    n=abs(n);
    
    if(n>1)low=1,high=n;
    else low=n,high=1;
    mid=(low+high)/2;
    while (abs(mid*mid*mid-n)>eps) {
        mid*mid*mid>n?high=mid:low=mid;
        mid=(low+high)/2;
    }
    return mid*flag;
}


int main(){
    for(int i=-100;i<100000;i++)
        printf("%d %f\n",i,cub(i));
}