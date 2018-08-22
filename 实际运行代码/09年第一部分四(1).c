#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char* argv[]){
    if(argc<2)exit(0);
    FILE* fp=fopen(argv[1],"r");
//    测试时可指定某一文件进行测试
//    FILE* fp=fopen("t.txt","r");
    if(fp==NULL)exit(0);
    char buf[17];
    long offset=ftell(fp);
    while (fgets(buf, 17, fp)!=NULL) {
        printf("%08x ",offset);
        offset=ftell(fp);
        for(int i=0;i<strlen(buf);i++)
            printf("%02x ",buf[i]);
        for(int i=strlen(buf);i<17;i++)
            printf("   ");
        
        for(int i=0;i<strlen(buf);i++)
            putchar(isprint(buf[i])?buf[i]:'.');
        putchar('\n');
    }
}
