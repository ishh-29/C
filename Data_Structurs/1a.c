//Array ADT
#include<stdio.h>
#include<stdlib.h>
struct Array{
    int*A;
    int size;
    int length;
};
//Merging Two Sorted Arrays
struct Array*Merge(struct Array*arr1,struct Array*arr2){
    int i,j,k;
    struct Array*arr3=(struct Array*)malloc(sizeof(struct Array));
    arr3->size=arr1->size+arr2->size;
    arr3->length=arr1->length+arr2->length;
    arr3->A=(int*)malloc(arr3->size*sizeof(int));
    i=j=k=0;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++) arr3->A[k++]=arr2->A[j];
    return arr3;
}
//Set Operations On Array
struct Array*Union(struct Array*arr1,struct Array*arr2){
    int i=0,j=0,k=0;
    struct Array*arr3=(struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i]) arr3->A[k++]=arr2->A[j++];
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++) arr3->A[k++]=arr2->A[j];
    return arr3;
}
struct Array*Intersection(struct Array*arr1,struct Array*arr2){
    int i=0,j=0,k=0;
    struct Array*arr3=(struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]) i++;
        else if(arr2->A[j]<arr1->A[i]) j++;
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
void display(struct Array arr){
    for(int i=0;i<arr.length;i++) printf("%d",arr.A[i]);
}
void append(struct Array *arr,int x){
    if(arr->length<arr->size) arr->A[++arr->length]=x;
}
void insert(struct Array *arr,int index,int x){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length;i>index;i--) arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
int delete(struct Array *arr,int index){
    int x=0;
    if(index>=0 && index<arr->length){
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++) arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}
int get(struct Array arr,int index){
    if(index>=0 && index<arr.length) return arr.A[index];
    return -1;
}
void set(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length) arr->A[index]=x;
}
int main(){
    struct Array arr;
    printf("Enter Size Of Array:");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int));
    arr.length=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr.A[i]);
    arr.length=n;
    display(arr);
    return 0;
}