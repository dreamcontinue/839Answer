#include <stdio.h>


void F10to16(int n){
    if(n){
        F10to16(n/16);
        putchar(n%16>9?n%16+'A'-10:n%16+'0');
    }
}

int main(){
    for(int i=1;i<101;i++){
        printf("%d:",i);
        F10to16(i);
        putchar('\n');
    }
}