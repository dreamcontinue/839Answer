#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ui2n(unsigned value,int n){ //十进制转换为n进制(n=2,8,10,16)
    if (value) {
        ui2n(value/n, n);
        putchar(value%n>9?value%n-10+'a':value%n+'0');
    }
}

char* p2q(unsigned n,int p,int q){
    char* s=(char*)malloc(sizeof(char)*(q-p+2));
    int i=q;
    while (i>=p) {
        s[q-i]=((n>>i)&1)+'0';
        i--;
    }
    s[q-i]=0;
    return s;
}

int main(){
    ui2n(0xfedcba98, 2);
    puts("");
    puts(p2q(0xfedcba98, 1, 31));
}