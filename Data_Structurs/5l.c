//Implementing Circular Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*head=NULL;
void create(int A[],int n){
    struct Node*t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
int count(struct Node*p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
void display(struct Node*p){
    do{
        printf("%d->",p->data);
        p=p->next;
    }while(p!=head);
    printf("NULL\n");
}
void recurrsive_display(struct Node*p){
    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d->",p->data);
        recurrsive_display(p->next);
    }
    flag=0;
}
void insert(struct Node*p,int index,int x){
    struct Node*t;
    if(index<0 || index>count(p)) return;
    if(index==0){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            struct Node*temp=head;
            while(temp->next!=head) temp=temp->next;
            temp->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for(int i=0;i<index-1;i++) p=p->next;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int delete(struct Node*p,int index){
    struct Node*q;
    int x;
    if(index<0 || index>count(head)) return -1;
    if(index==1){ //Deleting At The Begining
        while(p->next!=head) p=p->next;
        x=head->data;
        if(head==p){ //Single Node
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        for(int i=0;i<index-2;i++) p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    display(head);
    recurrsive_display(head);
    printf("\n");
    insert(head,0,5);
    display(head);
    insert(head,3,25);
    display(head);
    printf("Deleted Element: %d\n",delete(head,1));
    display(head);
    printf("Deleted Element: %d\n",delete(head,4));
    display(head);
    return 0;
}