//Implementation Of Queue Using Array
#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int*q;
};
void create(struct Queue*que,int size){
    que->size=size;
    que->front=que->rear=-1;
    que->q=(int*)malloc(que->size*sizeof(int));
}
void enqueue(struct Queue*que,int x){
    if(que->rear==que->size-1) printf("Queue Overflow");
    else{
        que->rear++;
        que->q[que->rear]=x;
    }
}
int dequeue(struct Queue*que){
    int x=-1;
    if(que->front==que->rear) printf("Queue Underflow");
    else{
        que->front++;
        x=que->q[que->front];
    }
    return x;
}
void display(struct Queue que){
    for(int i=que.front+1;i<=que.rear;i++) printf("%d->",que.q[i]);
    printf("NULL\n");
}
int main(){
    struct Queue que;
    create(&que,5);
    enqueue(&que,10);
    enqueue(&que,20);
    display(que);
    return 0;
}
