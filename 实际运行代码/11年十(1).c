#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* i2ba(int n,unsigned char* s){
    for(int i=0;i<sizeof(n)/sizeof(s[0]);i++,n>>=8)
        s[i]=n&(unsigned char)-1;//(unsigned char)-1-->(0xff)
    return s;
}
int main(){
    unsigned char s[sizeof(int)/sizeof(unsigned char)];
    i2ba(-2,s);
    for(int i=0;i<sizeof(int)/sizeof(unsigned char);i++)
        printf("%d,",s[i]);
}
