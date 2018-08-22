#include <cstdio>
#include <stdlib.h>
#include <string.h>

#define L 128
typedef struct{
    int length;
    char value[L];
}LNUM;
int add(LNUM a,LNUM b,LNUM *c){
    int i;
    for(i=0;i<L;i++)
        c->value[i]=a.value[i]+b.value[i];
    for(i=L-1;i>0;i--)
        if(c->value[i]>9){
            c->value[i-1]++;//进位
            c->value[i]%=10;
        }
    if(c->value[0]>9)return 1;//溢出
    i=0;
    while(!c->value[i])i++;//第一个不为0的数字的下标
    c->length=L-i>0?L-i:1;//考虑c=0时的特殊情况
    return 0;
}

//输入两个<128位的数
int main(){
    LNUM a,b,c;
    char sa[L+1],sb[L+1];
    scanf("%s%s",sa,sb);
//     异常情况
//     printf("\n\n");
//     a.length=b.length=128;
//     for(int i=0;i<L;i++)
//         sa[i]=sb[i]='6';
    
    a.length=strlen(sa);
    for(int i=0;i<L-a.length;i++)
        a.value[i]=0;
    for(int i=L-a.length;i<L;i++)
        a.value[i]=sa[i-L+a.length]-'0';
    
    b.length=strlen(sb);
    for(int i=0;i<L-b.length;i++)
        b.value[i]=0;
    for(int i=L-b.length;i<L;i++)
        b.value[i]=sb[i-L+b.length]-'0';
    int r=add(a,b,&c);
    for(int i=L-a.length;i<L;i++)
        printf("%d",a.value[i]);
    printf("\n+\n");
    for(int i=L-b.length;i<L;i++)
        printf("%d",b.value[i]);
    printf("\n=\n");
    if(r==0){
        for(int i=L-c.length;i<L;i++)
            printf("%d",c.value[i]);
        printf("\n");
        printf("c的长度%d\n\n",c.length);
    }else{
        printf("异常\n\n");
    }
    
    system("pause");
}