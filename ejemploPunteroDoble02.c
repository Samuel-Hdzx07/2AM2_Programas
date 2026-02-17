#include<stdio.h>

int main(){
int arg[5];
int *ptr,**pptr;

for(ptr=arg,pptr=&ptr;*pptr < &arg[5];(*pptr)++){
printf("\nIngrese un entero\t");
scanf("%d",*pptr);
}
for(ptr=arg,pptr=&ptr;*pptr < &arg[5];*pptr+=1)
printf("\nEl valor de la celda %d es %d en la direccion %p",(int)(*pptr-arg),**pptr,*pptr);
return 0;
}
