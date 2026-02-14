//To Sort A 2D Array Of Strings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char**names,int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(strcmp(names[j],names[j+1])>0){
                char*temp;
                temp=(char*)calloc(30,sizeof(char));   //Bubble Sort
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
}
int main(){
    char**names;
    int n;
    printf("Number Of Strings:");
    scanf("%d\n",&n);
    names=(char**)calloc(n, sizeof(char*));
    for(int i=0;i<n;i++){
        names[i]=(char*)calloc(30,sizeof(char));
        scanf("%s",names[i]);
    }
    sort(names,n);
    for(int i=0;i<n;i++) printf("%s\n",names[i]);
    return 0;
}