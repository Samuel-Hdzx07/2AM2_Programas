#include<stdio.h>

struct per{
char nom[30];
int edad;
float est;
char sexo;
};

int main(){
struct per perArg[2];
for(int i=0;i<2;i++){
setbuf(stdin,NULL);
printf("\nIngrese un nombre\t");
fgets(perArg[i].nom,30,stdin);
printf("\nIngrese una edad\t");
scanf("%d",&perArg[i].edad);
printf("\nIngrese una altura\t");
scanf("%f",&perArg[i].est);
setbuf(stdin,NULL);
printf("\nIngrese un sexo\t");
perArg[i].sexo=getchar();
}
for(int i=0;i<2;i++){
printf("\nEn la celda %d esta el nombre %s en la direccion %p",i,perArg[i].nom,&perArg[i].nom);
printf("\nEn la celda %d esta la edad %d en la direccion %p",i,perArg[i].edad,&perArg[i].edad);
printf("\nEn la celda %d esta la altura %f en la direccion %p",i,perArg[i].est,&perArg[i].est);
printf("\nEn la celda %d esta el sexo %c en la direccion %p",i,perArg[i].sexo,&perArg[i].sexo);
}
return 0;
}
