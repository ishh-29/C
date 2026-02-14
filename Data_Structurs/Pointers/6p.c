//To Generate Permutation Of A Given String
#include<stdio.h>
#include<string.h>
void change(char*ch1,char*ch2){
    char tmp;
    tmp=*ch1;
    *ch1=*ch2;
    *ch2=tmp;
}
void permutate(char*cht,int stno,int endno){
    if(stno==endno) printf("%s ",cht);
    else{
        for(int i=stno;i<=endno;i++){
            change((cht+stno),(cht+i));
            permutate(cht,stno+1,endno);
            change((cht+stno),(cht+i));
        }
    }
}
int main(){
    char str[]="abcd";
    int n=strlen(str);
    permutate(str,0,n-1);
    return 0;
}