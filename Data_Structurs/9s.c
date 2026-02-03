//Implementation Of Stack Using Linked List 
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*top=NULL;
void push(int x){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    if(!t) printf("Stack Overflow");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop(){
    struct Node*t;
    int x=-1;
    if(!t) printf("Stack Underflow");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}
void display(){
    struct Node*p;
    p=top;
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
int main(){
    int num;
    printf("Enter The Number Elements:");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int x;
        scanf("%d",&x);
        push(x);
    }
    display();
    printf("%d",pop());
    return 0;
}