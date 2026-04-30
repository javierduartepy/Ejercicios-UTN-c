#include <stdio.h>

int main() {
	int se_mueve, deberia;
	
	do {
		printf("\n--- Asistente de Reparacion (0 para salir) ---\n");
		
		do {
			printf("¿El objeto se mueve? (1: SI / 2: NO / 0: SALIR): ");
			scanf("%d", &se_mueve);
			if (se_mueve < 0 || se_mueve > 2) {
				printf("Error: Por favor, ingrese 1, 2 o 0.\n");
			}
		} while (se_mueve < 0 || se_mueve > 2);
		
		if (se_mueve == 0) break;
		
		do {
			printf("¿El objeto deberia moverse? (1: SI / 2: NO / 0: SALIR): ");
			scanf("%d", &deberia);
			if (deberia < 0 || deberia > 2) {
				printf("Error: Por favor, ingrese 1 o 2, o 0 para salir.\n");
			}
		} while (deberia != 1 && deberia != 2 && deberia != 0);
		
		
		if (se_mueve == 1 && deberia == 1) {
			printf("Resultado: No hace falta reparar.\n");
		} else if (se_mueve == 1 && deberia == 2) {
			printf("Resultado: Utilizar cinta americana.\n");
		} else if (se_mueve == 2 && deberia == 2) {
			printf("Resultado: No hace falta reparar.\n");
		} else {
			printf("Resultado: Utilizar aceite 3 en 1.\n");
		}
		
	} while (se_mueve != 0);
	
	printf("\nSe termino de ejecutar el programa.\n");
	
	return 0;
}
