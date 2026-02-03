//Implementation Of Circular Queue
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
    que->front=que->rear=0;
    que->q=(int*)malloc(que->size*sizeof(int));
}
void enqueue(struct Queue*que,int x){
    if((que->rear+1)%que->size==que->front) printf("Queue Overflow");
    else{
        que->rear=(que->rear+1)%que->size;
        que->q[que->rear]=x;
    }
}
int dequeue(struct Queue*que){
    int x=-1;
    if(que->front==que->rear) printf("Queue Underflow");
    else{
        que->front=(que->front+1)%que->size;
        x=que->q[que->front];
    }
    return x;
}
void display(struct Queue que){
    int i=que.front+1;
    do{
        printf("%d",que.q[i]);
        i=(i+1)%que.size;
    }
    while(i!=(que.rear+1)%que.size);
    printf("NULL\n");
}
int main(){
    return 0;
}
