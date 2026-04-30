#include <stdio.h>

int main() {
	
	double costo_inicial = 20000000.0;
	double valor_rescate = 2000.0;
	int vida_util = 6;
	int anio_inicial = 2023;
	
	double dep_anual = (costo_inicial - valor_rescate) / vida_util;
	double dep_acumulada = 0;
	double valor = costo_inicial;
	
	printf("TABLA DE DEPRECIACION\n");
	printf("--------------------------------------------------------------\n");
	printf("%-10s | %-15s | %-15s | %-15s\n", "Anio", "Dep. Anual", "Dep. Acumulada", "Valor");
	printf("--------------------------------------------------------------\n");
	
	printf("%-10d | %-15.2f | %-15.2f | %-15.2f\n", anio_inicial, 0.0, dep_acumulada, valor);
	
	for (int i = 1; i <= vida_util; i++) {
		dep_acumulada += dep_anual;
		valor -= dep_anual;
		
		printf("%-10d | %-15.2f | %-15.2f | %-15.2f\n", anio_inicial + i, dep_anual, dep_acumulada, valor);
	}
	
	printf("--------------------------------------------------------------\n");
	
	return 0;
}
