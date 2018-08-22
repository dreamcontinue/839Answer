#include <stdio.h>
int p(int* a,int* b,int n){
    int sum=0;
    for(int i=0;i<n;i++)
        if(a[i]==b[i])
            sum++;
    return sum;
}

int main(){
    int a[10]={0,1,1,1,0,1,0,0,1,0},
    b[10]={0,0,1,1,1,0,1,1,0,0},
    c[10]={1,0,1,0,1,1,1,0,1,1};
    
    for(int i=0;i<10;i++){
        a[i]=!a[i];
        for(int j=i+1;j<10;j++){
            a[j]=!a[j];
            for(int k=j+1;k<10;k++){
                a[k]=!a[k];
                if(p(a,b,10)==7&&p(a,c,10)==7){
                    printf("Answer:\n");
                    for(int m=0;m<10;m++){
                        printf("%d ",a[m]);
                    }
                    return 0;
                }
                a[k]=!a[k];
            }
            a[j]=!a[j];
        }
        a[i]=!a[i];
    }
}