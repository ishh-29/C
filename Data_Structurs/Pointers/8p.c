//To Show A Function Returning Pointer
#include<stdio.h>
int*find(int*,int*);
int main(){
    int a=0,b=0;
    int*res;
    scanf("%d",&a);
    scanf("%d",&b);
    res=find(&a,&b);
    printf("Larger Number :%d",*res);
}
int*find(int*n1,int*n2){
    if(*n1>*n2) return n1;
    else return n2;
}