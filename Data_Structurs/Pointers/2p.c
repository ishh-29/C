//To Find The Largest Element Of An Array Using Pointer
#include<stdio.h>
#include<stdlib.h>
void find(int*arr,int N){
    for(int i=1;i<N;i++){
        if(*arr<*(arr+i)) *arr=*(arr+i);
    }
    printf("%d ",*arr);
}
int main(){
    int n=4;
    int*arr;
    arr=(int*)calloc(n,sizeof(int));
    if(arr==NULL){
        printf("No Memory Allocated");
        exit(0);
    }
    *(arr+0)=14,*(arr+1)=12,*(arr+2)=19,*(arr+3)=20;
    find(arr,n);
    return 0;
}