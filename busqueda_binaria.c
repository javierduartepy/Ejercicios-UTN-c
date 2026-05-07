#include <stdio.h>

int main() {
	// Array original proporcionado
	int numeros[] = {84, 12, 97, 33, 56, 21, 48, 75, 19, 62, 44, 91, 27, 83, 10, 59, 
		38, 70, 25, 66, 14, 93, 41, 52, 88, 30, 77, 16, 49, 61, 23, 95, 34, 57, 81, 13, 68, 40, 29, 99,
		51, 74, 18, 86, 32, 65, 47, 22, 90, 37, 55, 11, 73, 28, 82, 46, 60, 20, 96, 39};
	int n = sizeof(numeros) / sizeof(numeros[0]);
	int buscar, i, j, temp;
	int inferior = 0, superior = n - 1, mitad;
	int encontrado = -1;
	
	// 1. ORDENAMIENTO (Método Burbuja)
	// La búsqueda binaria SOLO funciona si el array está ordenado
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (numeros[j] > numeros[j + 1]) {
				temp = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = temp;
			}
		}
	}
	
	printf("Array ordenado para la busqueda:\n");
	for (i = 0; i < n; i++) printf("%d ", numeros[i]);
	
	// 2. ENTRADA DE USUARIO
	printf("\n\nIngrese el numero que desea buscar: ");
	scanf("%d", &buscar);
	
	// 3. BUSQUEDA BINARIA
	while (inferior <= superior) {
		mitad = inferior + (superior - inferior) / 2;
		
		if (numeros[mitad] == buscar) {
			encontrado = mitad;
			break; // Se encontró el elemento
		}
		if (numeros[mitad] < buscar) {
			inferior = mitad + 1;
		} else {
			superior = mitad - 1;
		}
	}
	
	// 4. RESULTADO
	if (encontrado != -1) {
		printf("El numero %d se encuentra en la posicion %d (indice del array ordenado).\n", buscar, encontrado);
	} else {
		printf("El numero %d no existe en el array.\n", buscar);
	}
	
	return 0;
}


