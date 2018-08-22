#include <stdio.h>
#include <stdarg.h>//可变参数头文件

void ui2n(unsigned value,int n){ //无符号十进制转换为n进制(n=2,8,16)
    if (value) {
        ui2n(value/n, n);
        putchar(value%n>9?value%n-10+'a':value%n+'0');
    }
}

void MYprintf(char fmt[],...){
    va_list ap;//1 声明可变参数类型ap
    va_start(ap,fmt);//2 初始化ap
    int i=0;
    while (fmt[i]) {
        if(fmt[i]!='%'){
            putchar(fmt[i++]);
            continue;
        }
        switch (fmt[++i]) {
            case 'd':  printf("%d",va_arg(ap,int)); break;//3 从ap中取值
            case 'b':  ui2n(va_arg(ap, unsigned),2);break;
            case 'o':  ui2n(va_arg(ap, unsigned),8);break;
            case 'x':  ui2n(va_arg(ap, unsigned),16);break;
            case 'c':  putchar(va_arg(ap, char)); break;
            case 's':{
                char* s=va_arg(ap, char*);
                int j=0;
                while (s[j])
                    putchar(s[j++]);
                break;
            }
            default:  putchar(fmt[i]);
                break;
        }
        ++i;
    }
    va_end(ap);//4 销毁ap
}
int main(){
    MYprintf("%d %b %o %x %c %s\n",97,20,33,294,'a',"jerika");
}