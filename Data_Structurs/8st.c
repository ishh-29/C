//Nested Structures
#include<stdio.h>
struct child{
    int x;
    char c;
};
struct parent{
    int a;
    struct child b;
};
int main(){
    struct parent p1;
    p1.a=2;
    p1.b.x=1;
    p1.b.c='a';
    printf("%d %d %c",p1.a,p1.b.x,p1.b.c);
    return 0;
}