#include<stdio.h>
struct Student{
    int roll_no;
    char name[50];
    float marks;
};
int main(){
    struct Student s={98,"ABC",72.8};
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
    return 0;
}