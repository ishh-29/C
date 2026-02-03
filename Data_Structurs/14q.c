//Implementation Of Queue Using Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*front=NULL,*rear=NULL;
void enqueue(int x){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    if(!t) printf("Queue Overflow");
    else{
        t->data=x;
        t->next=NULL;
        if(!front) front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue(){
    int x=-1;
    struct Node*t;
    if(!front) printf("Queue Underflow");
    else{
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}
void display(){
    struct Node*p=front;
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
int main(){
    return 0;
}