#include<stdio.h>

int main(){
int a,b;
int *ptr,**pptr;
a=20;
ptr=&a;
pptr=&ptr;
b=**pptr;
printf("%d",b);
return 0;
}
