#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//s:原字符串
//c:作为分隔的字符
//result:储存分隔完成后的字符串数组 是char*[]的地址,为了当result数组为空时不出异常
//return:分隔后的数组元素个数,result[0...n-1]
int split(char* s,char c,char ***result){
    if(!*result)*result=(char**)malloc(sizeof(char*)*500);
    char tmp[1001];
    int i=0,j=0,n=0;
    while (s[i]) {
        if(s[i]!=c){
            tmp[j++]=s[i++];
            continue;
        }
        if(j){
            tmp[j++]=0;
            (*result)[n]=(char*)malloc(sizeof(char)*j);
            strcpy((*result)[n++], tmp);
            j=0;
        }
        ++i;
    }
    if(j){
        tmp[j++]=0;
        (*result)[n]=(char*)malloc(sizeof(char)*j);
        strcpy((*result)[n++], tmp);
    }
    return n;
}
int main(){
    char s[]="TensorFlow is an open source software library for numerical computation using data flow graphs. The graph nodes represent mathematical operations, while the graph edges represent the multidimensional data arrays (tensors) that flow between them. This flexible architecture enables you to deploy computation to one or more CPUs or GPUs in a desktop, server, or mobile device without rewriting code. TensorFlow also includes TensorBoard, a data visualization toolkit. TensorFlow was originally developed by researchers and engineers working on the Google Brain team within Google's Machine Intelligence Research organization for the purposes of conducting machine learning and deep neural networks research. The system is general enough to be applicable in a wide variety of other domains, as well. TensorFlow provides stable Python API and C APIs as well as without API backwards compatibility guarantee like C++, Go, Java, JavaScript and Swift. Keep up to date with release announcements and security updates by subscribing to announce@tensorflow.org.";
    char **str;
    int n=split(s, ',',&str);
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        puts(str[i]);
}
