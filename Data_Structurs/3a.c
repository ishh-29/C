//Polynomial Representation Using Arrays
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Term{
    int coeff;
    int exp;
};
struct Poly{
    int n;
    struct Term*t;
};
void create(struct Poly*p){
    printf("Enter Number Of Terms:");
    scanf("%d",&p->n);
    p->t=(struct Term*)malloc(p->n*sizeof(struct Term));
    printf("Enter Coefficients And Exponents:\n");
    for(int i=0;i<p->n;i++){
        printf("Term No.:%d\n",i+1);
        scanf("%d %d",&p->t[i].coeff,&p->t[i].exp);
    }
}
void display(struct Poly p){
    for(int i=0;i<p.n;i++){
        printf("%dx^%d",p.t[i].coeff,p.t[i].exp);
    }
}
int eval(struct Poly p,int x){
    int sum=0;
    for(int i=0;i<p.n;i++){
        sum+=p.t[i].coeff*pow(x,p.t[i].exp);
    }
    return sum;
}
struct Poly*add(struct Poly*p1,struct Poly*p2){
    struct Poly*sum;
    sum=(struct Poly*)malloc(sizeof(struct Poly));
    sum->t=(struct Term*)malloc((p1->n+p2->n)*sizeof(struct Term));
    int i=0,j=0,k=0;
    while(i<p1->n && j<p2->n){
        if(p1->t[i].exp>p2->t[j].exp) sum->t[k++]=p1->t[i++];
        else if(p1->t[i].exp<p2->t[j].exp) sum->t[k++]=p2->t[j++];
        else{
            sum->t[k].exp=p1->t[i].exp;
            sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
        }
        for(;i<p1->n;i++) sum->t[k++]=p1->t[i];
        for(;j<p2->n;j++) sum->t[k++]=p2->t[j];
        sum->n=k;
        return sum;
    }
}
int main(){
    struct Poly p1,p2,*sum;
    int x=5;
    create(&p1);
    display(p1);
    create(&p2);
    display(p2);
    sum=add(&p1,&p2);
    printf("Sum Polynomial:\n");
    display(*sum);
    printf("Evaluating Polynomial: %d\n",eval(p1,x));
    return 0;
}