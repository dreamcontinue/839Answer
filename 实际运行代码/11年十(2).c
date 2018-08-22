#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int steps[4][2]={0,1,0,-1,1,0,-1,0};

int dfs(int **a,int i,int j,int h,int w){
    a[i][j]=0;
    int sum=0;
    for(int k=0;k<4;k++){
        int ii=i+steps[k][0],jj=j+steps[k][1];
        if(ii>=0&&ii<h&&jj>=0&&jj<w&&a[ii][jj])
            sum+=dfs(a,ii,jj,h,w);
    }
    return sum+1;
}

int maxBlock(int **a,int h,int w){
    int maxn=0;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(a[i][j])
                maxn=fmax(maxn,dfs(a,i,j,h,w));
    return maxn;
}

int main(){
    int a[][10]={0,0,1,0,0,0,0,0,1,1, 0,1,1,0,0,1,1,1,1,1,
        0,1,0,0,0,1,0,0,0,0, 0,0,1,1,1,1,0,1,1,1, 0,0,1,1,1,1,0,1,1,1};
    int *b[]={a[0],a[1],a[2],a[3],a[4]};
    printf("%d\n",maxBlock(b, 5, 10));
}