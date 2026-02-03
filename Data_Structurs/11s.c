//Infix To Postfix Conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int precedence(char x){
    if(x=='+'||x=='-') return 1;
    else if(x=='*'|| x=='/') return 2;
    return 0;
}
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/') return 0;
    else return 1;
}
char*inftopost(char*infix){
    char*postfix;
    int i=0,j=0;
    int l=strlen(infix);
    postfix=(char*)malloc((l+2)*sizeof(char));
    while(infix[i]!='\0'){
        if(isoperand(infix[i])) postfix[j++]=infix[i++];
        else{
            if(precedence(infix[i])>precedence(top->data)) push(infix[i++]);
            else postfix[j++]=pop();
        }
    }
    while(top) postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}
int main(){
    char*infix="a+b*c-d/e";
    push('#');
    char*postfix=inftopost(infix);
    printf("%s",postfix);
    return 0;
}
