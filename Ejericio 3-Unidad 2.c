#include <stdio.h>

int main() {
	char caracter;
	int numero_entero;
	float numero_real;
	double numero_doble_precision;
	
	printf("Ingrese un carácter: ");
	scanf(" %c", &caracter);
	while (getchar() != '\n');
	
	printf("Ingrese un número entero: ");
	while (scanf("%d", &numero_entero) != 1 || getchar() != '\n') {
		printf("Error: Ingrese un entero válido: ");
		while (getchar() != '\n'); 
	}
	
	printf("Ingrese un número real (Use punto '.' para decimales): ");
	while (scanf("%f", &numero_real) != 1 || getchar() != '\n') {
		printf("Error: Formato incorrecto. Use punto '.' en vez de comas: ");
		while (getchar() != '\n'); 
	}
	
	printf("Ingrese un número de doble precisión (Número grande): ");
	while (scanf("%lf", &numero_doble_precision) != 1 || getchar() != '\n') {
		printf("Error: Formato incorrecto. No se permiten letras: ");
		while (getchar() != '\n');
	}
	
	printf("\n--- Datos cargados correctamente ---\n");
	printf("Carácter: %c | Entero: %d | Real: %.2f | Doble: %.2lf\n", 
		   caracter, numero_entero, numero_real, numero_doble_precision);
	
	return 0;
}


