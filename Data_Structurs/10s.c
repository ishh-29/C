//Parenthesis Matching Using Stack
#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node*next;
}*top=NULL;
void push(char x){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    if(!t) printf("Stack Overflow\n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop(){
    struct Node*t;
    char x=-1;
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
        printf("%c->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
int balance(char*exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(') push(exp[i]);
        else if(exp[i]==')'){
            if(top==NULL) return 0;
            pop();
        }
        
    }
    return top?0:1;
}
int main(){
    char*exp="((a+b)*(c-d))";
    if(balance(exp)) printf("Balanced Parenthesis");
    else printf("Unbalanced Parenthesis");
    return 0;
}
