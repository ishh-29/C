//Implementing Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}*head=NULL;
void create(int A[],int n){
    struct Node*t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->prev=head->next=NULL;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display(struct Node*p){
    while(p){
        printf("%d<->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
int count(struct Node*p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct Node*p,int index,int x){
    struct Node*t;
    if(index<0 || index>count(p)) return;
    if(index==0){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=head;
        if(head) head->prev=t;
        head=t;
    }
    else{
        for(int i=0;i<index-1;i++) p=p->next;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
}
int del(struct Node*p,int index){
    struct Node*q;
    int x=-1;
    if(index<1 || index>count(p)) return -1;
    if(index==1){
        q=head;
        head=head->next;
        if(head) head->prev=NULL;
        x=q->data;
        free(q);
    }
    else{
        for(int i=0;i<index-1;i++) p=p->next;
        q=p->next;
        p->next=q->next;
        if(q->next) q->next->prev=p;
        x=q->data;
        free(q);
    }
    return x;
}
void reverse(struct Node*p){
    struct Node*temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p && p->next==NULL){
            head=p;
        }
    }
}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    display(head);
    insert(head,0,5);
    display(head);
    insert(head,3,25);
    display(head);
    printf("Deleted element: %d\n",del(head,3));
    display(head);
    reverse(head);
    display(head);
    return 0;
}