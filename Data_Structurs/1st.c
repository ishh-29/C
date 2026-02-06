//To Add Two Distances In The Inch-Feet System 
#include<stdio.h>
struct fps{
    int feet;
    float inch;
};
void findsum(struct fps arr[],int N){
    int fsum=0;
    float isum=0.0;
    int x;
    for(int i=0;i<N;i++){
        fsum+=arr[i].feet;
        isum+=arr[i].inch;
    }
    if(isum>=12){
        x=(int)isum;
        isum-=x;
        isum+=x%12;
        fsum+=x/12;
    }
    printf("Feet Sum: %d",fsum);
    printf("Inch Sum: %.2f",isum);
}
int main(){
    struct fps arr[]={{10,3.7},{10,5.5},{6,8.0}};
    int N=sizeof(arr)/sizeof(arr[0]);
    findsum(arr, N);
    return 0;
}