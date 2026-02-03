//Implementation Of Stack Using Array
#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int*s;
};
void create(struct Stack*st){
    printf("Enter Size:");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}
void display(struct Stack st){
    for(int i=st.top;i>=0;i--) printf("%d-",st.s[i]);
    printf("NULL\n");
}
void push(struct Stack*st,int x){
    if(st->top==st->size-1) printf("Stack Overflow\n");
    else st->s[++st->top]=x;
}
int pop(struct Stack*st){
    int x=-1;
    if(st->top==-1) printf("Stack Underflow\n");
    else x=st->s[st->top--];
    return x;
}
int peek(struct Stack st,int index){
    int x=-1;
    if(st.top-index+1<0) printf("Invalid Index");
    x=st.s[st.top-index+1];
    return x;
}
int isempty(struct Stack st){
    return st.top==-1;
}
int isfull(struct Stack st){
    return st.top==st.size-1;
}
int stack_top(struct Stack st){
    if(!isempty(st)) return st.s[st.top];
    return -1;
}
int main(){
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    printf("%d\n",peek(st,2));
    display(st);
    return 0;
}