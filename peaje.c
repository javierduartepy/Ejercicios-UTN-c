#include <stdio.h>
#include <math.h>

/*Escriba un algoritmo que determine el precio del peaje a abonar por el 
pasajero en funcion de los kilometros que va a recorrer, sabiendo que hasta 10km
el precio es de 200$, hasta 20km el precio es de 300$, hasta 40km el precio es
de 400$, hasta 80km es de 500$, y si supera los 80km es de 600$*/

int main() {
	float km; 
    int precio;
    inicio:
    printf("Ingrese los km a recorrer: ");
    scanf("%f", &km);

    if(km<=0){
        printf("Error. Debe ingresar un valor mayor a 0");
        goto inicio;
    } else if (km<=10){
        precio = 200;
        printf("El valor del peaje es de: %d", precio);
        if(km>10 && km<=20){
            precio = 300;
            printf("El valor del peaje es de: %d", precio);
            if (km>20 && km<=40){
                precio = 400;
                printf("El valor del peaje es de: %d", precio);
            }else if (km>40 && km<=80){
                precio = 500;
                printf("El valor del peaje es de: %d", precio);
            }
        }else{
            precio = 600;
            printf("El valor del peaje es de: ", precio);
        }
    }
    return 0;
}