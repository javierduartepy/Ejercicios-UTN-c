#include <stdio.h>

/*Calcula el precio de un boleto de viaje, tomando en cuenta el 
número de kilómetros que se van a recorrer, siendo el precio $45 por Km.*/

int main() {
	int i, km, precio;
	inicio:
	printf("Ingrese la distancia a realizar: \n");
	scanf("%d", &km);
	
	if(km>=1){
		precio = km*45;
		printf("El precio que debe pagar por %d km es de----%d $", km, precio);
	}else{
		printf("Debe ingresar una distancia mayor a 0 \n");
		goto inicio;
	}
	return 0;
}

