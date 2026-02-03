//Polynomial Representation Using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
    int coeff;
    int exp;
    struct Node*next;
}*poly=NULL;
void create(){
    struct Node*t,*last=NULL;
    int num;
    printf("Enter Number Of Terms:");
    scanf("%d",&num);
    printf("Enter Coefficients And Exponents:");
    for(int i=0;i<num;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d",&t->coeff,&t->exp);
        t->next=NULL;
        if(!poly) poly=last=t;
        else{
            last->next=t;
            last=t;
        }
    }
}
long eval(struct Node*p,int x){
    long val=0;
    while(p){
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}
void display(struct Node*p){
    while(p){
        printf("%dx%d+",p->coeff,p->exp);
        p=p->next;
    }
    printf("\n");
}
int main(){
    create();
    display(poly);
    printf("%ld",eval(poly,1));
    return 0;
}