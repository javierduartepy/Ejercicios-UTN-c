#include <stdio.h>

int main() {
	// 1. DECLARACIÓN DE TODAS LAS VARIABLES ARRIBA
	int matriz[2][3] = {{10, 20, 30}, {40, 50, 60}};
	int arreglo[6];
	int nueva_matriz[2][3];
	
	int f, c, i; // Variables para recorrer (filas, columnas, índice de arreglo)
	
	// ====================================================================
	// CASO 1: PASAR DE MATRIZ A ARREGLO (Aplanar la matriz)
	// ====================================================================
	i = 0; // El índice del arreglo arranca en 0
	for(f = 0; f < 2; f++) {
		for(c = 0; c < 3; c++) {
			arreglo[i] = matriz[f][c]; // Copiamos el dato
			i++; // Avanzamos al siguiente casillero del arreglo
		}
	}
	
	// Mostramos el arreglo resultante en una sola línea
	printf("Arreglo 1D resultante: ");
	printf("[ ");
	for(i = 0; i < 6; i++) {
		printf("%d ", arreglo[i]);
	}
	printf("]\n\n");
	
	// ====================================================================
	// CASO 2: PASAR DE ARREGLO A MATRIZ (Darle forma de tabla otra vez)
	// ====================================================================
	i = 0; // Reiniciamos el índice del arreglo para volver a leerlo
	for(f = 0; f < 2; f++) {
		for(c = 0; c < 3; c++) {
			nueva_matriz[f][c] = arreglo[i]; // Copiamos del arreglo a la matriz
			i++; // Avanzamos al siguiente casillero del arreglo
		}
	}
	
	// Mostramos la nueva matriz en forma de bloques (filas y columnas)
	printf("Matriz 2D reconstruida:\n");
	for(f = 0; f < 2; f++) {
		for(c = 0; c < 3; c++) {
			printf("%d\t", nueva_matriz[f][c]);
		}
		printf("\n"); // Salto de línea al terminar cada fila
	}
	
	return 0;
}


