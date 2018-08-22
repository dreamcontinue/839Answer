#include <stdio.h>
#include <stdlib.h>

int replace(char s[],char ch,char str[],char t[]){
    
    int i=0,j=0,k,sum=0;
    while(s[i]){
        if(s[i]-ch){
            t[j++]=s[i++];
            continue;
        }
        k=0;
        while(str[k])
            t[j++]=str[k++];
        sum++;
        i++;
    }
    return sum;
}

int main(){
    char str1[]="p12/p25",str2[100];
    int n=replace(str1, 'p', "No.", str2);
    printf("str2=%s\nn=%d\n",str2,n);
}