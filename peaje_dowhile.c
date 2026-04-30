#include <stdio.h>
#include <math.h>

/*Escriba un algoritmo que determine el precio del peaje a abonar por el 
pasajero en funcion de los kilometros que va a recorrer, sabiendo que hasta 10km
el precio es de 200$, hasta 20km el precio es de 300$, hasta 40km el precio es
de 400$, hasta 80km es de 500$, y si supera los 80km es de 600$*/

int main() {
	float km; 
    int precio;
   
    do{
        printf("Ingrese los km a recorrer: ");
        scanf("%f", &km);

        if(km<=0){
            printf("Error. Debe ingresar un valor mayor a 0 \n");

        }else{
            if(km<=10 && km>0){
                precio = 200;
            }else if (km<=20){
                precio = 300;
            }else if(km<=40){
                precio = 400;
            }else if (km<=80){
                precio = 500;
            }else{
                precio = 600;
            }
            printf("*************************************\n");
            printf("El valor del peaje es de %d $\n", precio);
            printf("*************************************\n");
        }
    }while (km<=0);
    return 0;
}