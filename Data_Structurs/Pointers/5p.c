//To Check If A String Is Palindrome 
#include<stdio.h> 
void drome(char*str){ 
    char*ptr,*rev; 
    ptr=str; 
    while(*ptr!='\0') ++ptr;
    --ptr; 
    for(rev=str;ptr>=rev;){ 
        if(*ptr==*rev){ 
            --ptr; 
            rev++; 
        } 
        else break; 
    } 
    if (rev>ptr) printf("Palindrome"); 
    else printf("Not Palindrome"); 
} 
int main(){ 
    char str[1000]="kuchu puchu";
    drome(str); 
    return 0; 
}