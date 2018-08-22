#include <cstdio>
#include <stdlib.h>

typedef struct TNode{
    int data;
    struct TNode* lchild,*rchild;
}TNode;

//find 从mid中找出data所在的下标
int find(int mid[],int data,int n){
    for(int i=0;i<n;i++)
        if(mid[i]==data)
            return i;
    return -1;
}

//不妨认为数组中下标从0开始存储，根节点处于post[n-1]，
//树在数字中的下标范围[0…n-1](即0<=i<n)
TNode* createTree(int* mid,int* post,int n){
    if(n<=0)return NULL;
    TNode *T=(TNode*)malloc(sizeof(TNode));//新建根节点
    T->data=post[n-1];
    int fd=find(mid,post[n-1],n);//在mid数组中找到根节点的下标
    if(fd==-1)exit(0);//数组不正确
    //左子树范围mid[0…fd],post[0…fd]
    T->lchild=createTree(mid,post,fd);
    //右子树范围mid[fd+1…n],post[fd…n-1]
    T->rchild=createTree(mid+fd+1,post+fd,n-fd-1);
    return T;
}

void print(TNode* T){
    if(!T)return;
    printf("%d",T->data);
    if(T->lchild)printf(" l:%d ",T->lchild->data);
    if(T->rchild)printf(" r:%d ",T->rchild->data);
    putchar('\n');
    print(T->lchild);
    print(T->rchild);
}
int main(){
    int mid[]={4,2,7,8,5,1,3,6},post[]={4,8,7,5,2,6,3,1};
    TNode *T=createTree(mid,post,8);
    print(T);
    system("pause");
}
