#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ui2n(unsigned value,int n){//十进制转换为n进制(n=2,8,10,16)
    if (value) {
        ui2n(value/n, n);
        putchar(value%n>9?value%n-10+'a':value%n+'0');
    }
}

void PRINT(char fmt[],unsigned value){
    int i=0;
    while (fmt[i]) {
        if(fmt[i]!='%'){
            putchar(fmt[i++]);
            continue;
        }
        switch (fmt[++i]) {
            case 'b': ui2n(value, 2); break;
            case 'u': ui2n(value, 10); break;
            case 'x': ui2n(value, 16); break;
            case 'o': ui2n(value, 8); break;
        }
        ++i;
    }
}
int main(){
    PRINT("vdsv我%b\n", 12);
    PRINT("vdsv我%u\n", 12);
    PRINT("vdsv我%x\n", 12);
    PRINT("vdsv我%o\n", 12);
}