//typedef For Structure
struct A{
    int x;
};
typedef struct A a;
#include <stdio.h>
int main(){
    a x;
    x.x=10;
    printf("%d\n", x.x);
    return 0;
}