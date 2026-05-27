#include <stdio.h>
#include <string.h>

int main() {
	char cadena[100];
	int i, longitud;
	
	// 1. CARGA CONTROLADA
	printf("Ingrese una cadena: ");
	scanf(" %[^\n]", cadena);
	fflush(stdin);
	
	
	longitud = 0;
	for(i = 0; cadena[i] != '\0'; i++) {
		longitud++;
	}
	
	// 3. MUESTRAS SEGÚN LA CAPTURA
	printf("%s tiene %d letras.\n", cadena, longitud);
	
	printf("%s escrita al reves es: ", cadena);
	// Recorremos de atras para adelante (desde longitud-1 hasta 0)
	for(i = longitud - 1; i >= 0; i--) {
		printf("%c", cadena[i]);
	}
	printf("\n");
	
	return 0;
}


