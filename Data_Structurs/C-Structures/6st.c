//Passing Structure To A Function
struct A{
    int x;
};
void inc(struct A a,struct A *b){
    a.x++;
    b->x++;
}
#include<stdio.h>
int main(){
    struct A a={10},b={10};
    inc(a,&b);
    printf("a.x=%d\n",a.x);
    printf("b.x=%d\n",b.x);
    return 0;
}