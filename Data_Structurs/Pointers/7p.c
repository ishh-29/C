//To Find The Length Of A String
#include<stdio.h>
int len(char*);
int main() {
   char str[25];
   int l;
   printf("Input A String:");
   fgets(str,sizeof(str),stdin);
   l=len(str);
   printf("Length:%d ",l-1);
}
int len(char*ch){
   int ctr=0;
   while(*ch!='\0'){
      ctr++;
      ch++;
    }
   return ctr;
}