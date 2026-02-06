//Time Structure
#include<stdio.h>
struct Time{
    int hrs;
    int mins;
    int sec;
};
int main(){
    struct Time t1,t2,result;
    printf("Input First (hours minutes seconds):");
    scanf("%d %d %d",&t1.hrs,&t1.mins,&t1.sec);
    printf("Input Second (hours minutes seconds):");
    scanf("%d %d %d",&t2.hrs,&t2.mins,&t2.sec);
    result.sec=t1.sec+t2.sec;
    result.mins=t1.mins+t2.mins+result.sec/60;
    result.hrs=t1.hrs+t2.hrs+result.mins/60;
    result.mins%=60;
    result.sec%=60;
    printf("\nResultant Time: %02d:%02d:%02d\n",result.hrs,result.mins,result.sec);
    return 0;
}
