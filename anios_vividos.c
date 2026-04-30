#include <stdio.h>

/*4.1 Escribir un programa que pregunte al usuario su edad y muestre 
por pantalla todos los años que ha cumplido (desde 1 hasta su edad).*/

int main() {
	int anio_nac, anio_actual, primer, i;
	inicio:
	printf("Ingrese el anio de nacimiento: ");
	scanf("%d", &anio_nac);
	if(anio_nac<=0){
		printf("El anio debe ser mayor a 0\n");
		goto inicio;
	}
	inicio2:
	printf("Ingrese el anio actual: ");
	scanf("%d", &anio_actual);
	if(anio_actual<anio_nac){
		printf("El anio debe ser mayor al del nacimiento\n");
		goto inicio2;
	}
	
	primer=anio_nac+1;
	
	printf("================================================\n");
	printf("LOS AÑOS VIVIDOS SON\n");
	printf("================================================\n");
	for (i=primer; i<=anio_actual; i++){
		printf("%d ", i);			
	}
	printf("\n");
	printf("================================================\n");
	return 0;
}

