//Implementing Linked List 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{ //A Self-referential Structure
    int data;
    struct Node*next;
}*head=NULL; //Global Declaration
void create(int A[],int n){
    struct Node*t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node*p){
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
void recurrsive_display(struct Node*p){
    if(p){
        //In Normal Order
        printf("%d",p->data);
        recurrsive_display(p->next);
        //In Reverse Order
        //recurrsive_display(p->next);
        //printf("%d",p->data);
    }
}
int count(struct Node*p){
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
int sum(struct Node*p){
    int s=0;
    while(p){
        s+=p->data;
        p=p->next;
    }
    return s;
}
int recurrsive_sum(struct Node*p){
    if(p) return recurrsive_sum(p->next)+p->data;
    return 0;
}
int recurrsive_count(struct Node*p){
    if(p) return recurrsive_count(p->next)+1;
    return 0;
}
int max_elem(struct Node*p){
    int m=INT_MIN;
    while(p){
        if(p->data>m){
            m=p->data;
            p=p->next;
        }
    }
    return m;
}
int recurrsive_max_elem(struct Node*p){
    int x=0;
    if(p==0) return INT_MIN;
    x=recurrsive_max_elem(p->next);
    return x>p->data?x:p->data;
}
struct Node*search(struct Node*p,int key){
    while(p){
        if(key==p->data) return p;
        p=p->next;
    }
}
struct Node*recurrsive_search(struct Node*p,int key){
    if(p==NULL) return NULL;
    if(key==p->data) return p;
    return recurrsive_search(p->next,key);
}
void insert(struct Node*p,int index,int x){
    struct Node*t;
    if(index<0 || index>count(p)) return;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0){ //Insert At Beginning
        t->next=head;
        head=t;
    }
    else{ //Insert At Given Index
        for(int i=0;i<index;i++) p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
void append(int x){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(head==NULL) head=t;
    else{
        struct Node*p=head;
        while(p->next) p=p->next;
        p->next=t;
    }
}
int delete(struct Node*p,int index){
    struct Node*q=NULL;
    int x=-1;
    if(index<1 || index>count(p)) return -1;
    if(index==1){ //Delete First Node
        q=head;
        x=head->data;
        head=head->next;
        free(q);
        return x;
    }
    else{ //Delete At Given Index
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
void reverse(struct Node*p){
    struct Node*q=NULL,*r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
void recursive_reverse(struct Node*q,struct Node*p){
    if(p){
        recursive_reverse(p,p->next);
        p->next=q;
    }
    else head=q;
}
void concat(struct Node*p,struct Node*q){
    struct Node*temp=p;
    while(temp->next) temp=temp->next;
    temp->next=q;
}
int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    display(head);
    printf("\nCount:%d\n",count(head));
    printf("Sum:%d\n",sum(head));
    printf("Recurrsive Sum:%d\n",recurrsive_sum(head));
    printf("Max Element:%d\n",max_elem(head));
    struct Node*temp=search(head,7);
    if(temp) printf("Element %d Found\n",temp->data);
    else printf("Element Not Found\n");
    insert(head,2,12);
    printf("After Insertion:\n");
    display(head);
    append(20);
    printf("\nAfter Appending:\n");
    display(head);
    int deleted=delete(head,3);
    printf("\nDeleted Element:%d\n",deleted);
    printf("After Deletion:\n");
    display(head);
    reverse(head);
    printf("\nAfter Reversing:\n");
    display(head);
    recursive_reverse(NULL,head);
    printf("\nAfter Recursive Reversing:\n");
    display(head);
    return 0;
}