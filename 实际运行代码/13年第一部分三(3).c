#include <stdio.h>

void* bsearch(void* key,void* base,size_t num,size_t width,
              int (*compare)(const void* elem1,const void* elem2)){
    size_t low=0,high=num-1,mid;
    while(low<=high) {
        mid=(low+high)>>1;
        if(compare(key,(char*)base+mid*width)==0)
            return (char*)base+mid*width;
        else if(compare(key,(char*)base+mid*width)<0)
            high = mid-1;
        else
            low = mid+1;
    }
    return NULL;
}
int compare_int(const void *elem1, const void *elem2) {
    return *(int *)elem1 - *(int *)elem2;
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 9;
    
    int *p = (int *)bsearch(&key, a, 10, sizeof(int), compare_int);
    if (p != NULL) {
        printf("find key in a: %d\n", *p);
    }
    else {
        printf("error");
    }
    
    return 0;
}