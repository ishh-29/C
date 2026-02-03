//Implementation Of Binary Tree
#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;
struct Queue{
    int size;
    int front;
    int rear;
    struct Node**q;
};
void create(struct Queue*que,int size){
    que->size=size;
    que->front=que->rear=0;
    que->q=(struct Node**)malloc(que->size*sizeof(struct Node*));
}
void enqueue(struct Queue*que,struct Node*x){
    if((que->rear=1)%que->size==que->front) printf("Queue Overflow\n");
    else{
        que->rear=(que->rear+1)%que->size;
        que->q[que->rear]=x;
    }
}
struct Node*dequeue(struct Queue*que){
    struct Node*x=NULL;
    if(que->front==que->rear) printf("Queue Underflow\n");
    else{
        que->front=(que->front+1)%que->size;
        x=que->q[que->front];
    }
    return x;
}
int isempty(struct Queue que){return que.front==que.rear;}
void tcreate(){
    struct Node*p,*t;
    int x;
    struct Queue que;
    create(&que,100);
    printf("Enter Root Value:");
    scanf("%d",&x);
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&que,root);
    while(!isempty(que)){
        p=dequeue(&que);
        printf("Enter Left Child Of The Node:\n");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&que,t);
        }
        printf("Enter Right Child Of The Node: %d\n");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&que,t);
        }
    }
}
void Preord(struct Node*p){
    if(p){
        printf("%d->",p->data);
        Preord(p->lchild);
        Preord(p->rchild);
    }
}
void Inord(struct Node*p){
    if(p){
        Inord(p->lchild);
        printf("%d->",p->data);
        Inord(p->rchild);
    }
}
void Postord(struct Node*p){
    if(p){
        Postord(p->lchild);
        Postord(p->rchild);
        printf("%d->",p->data);
    }
}
int main(){
    tcreate();
    Preord(root);
    Inord(root);
    Postord(root);
    return 0;
}