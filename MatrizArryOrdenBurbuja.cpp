#include <stdio.h>

#define FILAS 2
#define COLUMNAS 3
#define TOTAL 6 // FILAS * COLUMNAS

void ordenarBurbuja(int arr[], int n);

int main() {
	// Matriz fija de prueba
	int matriz[FILAS][COLUMNAS] = {
		{9, 2, 8},
	{1, 5, 4}
	};
	
	int arreglo[TOTAL];
	int k = 0; // Índice auxiliar para movernos en el arreglo plano
	
	// --- PASO 1: CONVERTIR MATRIZ A ARREGLO ---
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			// ??? TU CÓDIGO ACÁ: Asigná el elemento de la matriz al arreglo
			// Pista: usá la variable 'k' para el casillero del arreglo y sumale 1 (k++)
		}
	}
	
	// --- PASO 2: ORDENAR EL ARREGLO ---
	ordenarBurbuja(arreglo, TOTAL);
	
	// --- PASO 3: VOLVER A PASAR EL ARREGLO A LA MATRIZ ---
	k = 0; // Reiniciamos el índice del arreglo en cero
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			// ??? TU CÓDIGO ACÁ: Guardá lo que hay en el arreglo de vuelta en la matriz
		}
	}
	
	// --- MOSTRAR RESULTADO FINAL ---
	printf("Matriz ordenada final:\n");
	for (int i = 0; i < FILAS; i++) {
		printf("[ ");
		for (int j = 0; j < COLUMNAS; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("]\n");
	}
	
	return 0;
}

// Función de ordenamiento clásica
void ordenarBurbuja(int arr[], int n) {
	int aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			// ??? TU CÓDIGO ACÁ: Condición del if e intercambio de burbuja
			// Queremos ordenar de MENOR a MAYOR
		}
	}
}
