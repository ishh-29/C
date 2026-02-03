//Evaluation Of Postfix Expression 
#include<stdio.h>
#include<string.h>
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
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/') return 0;
    else return 1;
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
int eval(char*postfix){
    int x,y,r=0;
    for(int i=0;postfix[i]!='\0';i++){
        if(isoperand(postfix[i])) push(postfix[i]-'0');
        else{
            y=pop();
            x=pop();
            switch(postfix[i]){
                case '+':r=x+y;
                        break;
                case '-': r=x-y;
                        break;
                case '*': r=x*y;
                        break;
                case '/': r=x/y;
                        break;        
            }
            push(r);
        }
    }
    return top->data;
}
int main(){
    return 0;
}