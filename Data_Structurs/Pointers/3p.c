//To Sort An Array Using Pointers
#include<stdio.h> 
void sort(int n,int*ptr){ 
    for(int i=0;i<n;i++){ 
        for(int j=i+1;j<n;j++){ 
            if(*(ptr+j)<*(ptr+i)){
                int t=*(ptr+i); 
                *(ptr+i)=*(ptr+j); 
                *(ptr+j)=t; 
            } 
        } 
    } 
    for(int i=0;i<n;i++) printf("%d ",*(ptr+i)); 
} 
int main(){
    int n=5; 
    int arr[]={0,23,14,12,9}; 
    sort(n,arr);
    return 0; 
}