#include <stdio.h>

#define FILAS 2
#define COLUMNAS 3
#define TOTAL 6 // 2 * 3 = 6 elementos en total

void ordenarBurbuja(int arr[], int n);
void mostrarMatriz(int mat[FILAS][COLUMNAS]);
void mostrarArreglo(int arr[], int n);

int main() {
	// Matriz fija de prueba desordenada
	int matriz[FILAS][COLUMNAS] = {
		{9, 2, 8},
	{1, 5, 4}
	};
	
	int arreglo[TOTAL];
	int k = 0; // Índice para recorrer el arreglo lineal
	
	// -------------------------------------------------------------
	// ESTADO INICIAL
	// -------------------------------------------------------------
	printf("=== 1. MATRIZ ORIGINAL ===\n");
	mostrarMatriz(matriz);
	
	// -------------------------------------------------------------
	// PASO 1: CONVERTIR MATRIZ A ARREGLO
	// -------------------------------------------------------------
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			arreglo[k] = matriz[i][j]; // Copia el elemento
			k++;                       // Avanza al siguiente casillero del arreglo
		}
	}
	
	printf("\n=== 2. ARREGLO PLANO (Antes de ordenar) ===\n");
	mostrarArreglo(arreglo, TOTAL);
	
	// -------------------------------------------------------------
	// PASO 2: ORDENAR EL ARREGLO CON BURBUJA
	// -------------------------------------------------------------
	ordenarBurbuja(arreglo, TOTAL);
	
	printf("\n=== 3. ARREGLO PLANO (Ya ordenado) ===\n");
	mostrarArreglo(arreglo, TOTAL);
	
	// -------------------------------------------------------------
	// PASO 3: VOLVER A PASAR EL ARREGLO A LA MATRIZ
	// -------------------------------------------------------------
	k = 0; // Volvemos a empezar desde el primer casillero del arreglo
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			matriz[i][j] = arreglo[k]; // Devuelve el dato ordenado a la matriz
			k++;                       // Avanza en el arreglo
		}
	}
	
	// -------------------------------------------------------------
	// ESTADO FINAL
	// -------------------------------------------------------------
	printf("\n=== 4. MATRIZ FINAL (Ordenada) ===\n");
	mostrarMatriz(matriz);
	
	return 0;
}

// Función de ordenamiento clásica para números enteros
void ordenarBurbuja(int arr[], int n) {
	int aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			// Si el número actual es mayor al que le sigue, los intercambia
			if (arr[j] > arr[j + 1]) {
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}

// Función auxiliar para imprimir la matriz de forma visual
void mostrarMatriz(int mat[FILAS][COLUMNAS]) {
	for (int i = 0; i < FILAS; i++) {
		printf("  [ ");
		for (int j = 0; j < COLUMNAS; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("]\n");
	}
}

// Función auxiliar para imprimir el arreglo lineal
void mostrarArreglo(int arr[], int n) {
	printf("  [ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

