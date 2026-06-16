#include<stdio.h>

struct per{
char nom[30];
int edad;
float est;
char sexo;
};

int main(){
struct per perArg[2],*ptrS;
for(ptrS=perArg;ptrS<&perArg[2];ptrS+=1){
setbuf(stdin,NULL);
printf("\nIngrese un nombre\t");
fgets(ptrS->nom,30,stdin);
printf("\nIngrese una edad\t");
scanf("%d",&ptrS->edad);
printf("\nIngrese una altura\t");
scanf("%f",&ptrS->est);
setbuf(stdin,NULL);
printf("\nIngrese un sexo\t");
ptrS->sexo=getchar();
}
for(ptrS=perArg;ptrS<&perArg[2];ptrS+=1){
printf("\nEn la celda %d esta el nombre %s en la direccion %p",(int)(ptrS-perArg),ptrS->nom,&ptrS->nom);
printf("\nEn la celda %d esta la edad %d en la direccion %p",(int)(ptrS-perArg),ptrS->edad,&ptrS->edad);
printf("\nEn la celda %d esta la altura %f en la direccion %p",(int)(ptrS-perArg),ptrS->est,&ptrS->est);
printf("\nEn la celda %d esta el sexo %c en la direccion %p",(int)(ptrS-perArg),ptrS->sexo,&ptrS->sexo);
}
return 0;
}
