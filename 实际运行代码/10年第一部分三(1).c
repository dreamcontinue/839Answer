#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char* ui2hex(unsigned n,char *s){
    if(n==0){s="0";return s;}
    int i=0;
    while (n) {//逆序的hex
        s[i++]=n%16>9?n%16-10+'a':n%16+'0';
        n/=16;
    }
    for (int j=0;j<i/2;j++) {//逆置数组
        s[i]=s[j];
        s[j]=s[i-j-1];
        s[i-j-1]=s[i];
    }
    s[i]='\0';
    return s;
}

int main(){
    char s[100];
    for(int i=0;i<1000;i++)
        printf("%d: %s\n",i,ui2hex(i, s));
}