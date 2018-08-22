#include <cstdio>
#include <stdlib.h>
#include <string.h>

int Reduce(char s[]){
    int i=0,offset=0;
    while (s[i+offset]) {
        if(s[i]!=s[i+1+offset]){//当前值不等于下一个，那么复制过来
            s[i+1]=s[i+1+offset];
            ++i;
        }else
            offset++;
    }
    return offset;
}
int main(){
    char s[]="Press***12225525";
    printf("%d %s",Reduce(s),s);
}