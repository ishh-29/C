//Structure To A Pointer 
#include<stdio.h>
typedef struct Point{
    int x,y;
}p;
int main(){
    p t={10,20};
    p *ptr=&t;
    printf("%d %d",ptr->x,ptr->y);
    return 0;
}