#include <stdio.h>

int main() {
	int n1, n2, n3, op;
	
	Inicio:
		printf("\n--- BUSCADOR DEL NUMERO MAYOR ---\n");
	printf("Ingrese tres numeros enteros positivos y distintos:\n");
	
	if (scanf("%d %d %d", &n1, &n2, &n3) != 3) {
		printf("ERROR: Debe ingresar valores numericos.\n");
		fflush(stdin); // Limpia el error de entrada
		goto Inicio;
	}
	
	// IF anidado para validar que sean positivos
	if (n1 > 0 && n2 > 0 && n3 > 0) {
		// IF anidado para validar que sean distintos
		if (n1 != n2 && n1 != n3 && n2 != n3) {
			
			// Logica para encontrar el mayor
			if (n1 > n2) {
				if (n1 > n3) {
					printf("RESULTADO: El mayor es %d\n", n1);
				} else {
					printf("RESULTADO: El mayor es %d\n", n3);
				}
			} else {
				if (n2 > n3) {
					printf("RESULTADO: El mayor es %d\n", n2);
				} else {
					printf("RESULTADO: El mayor es %d\n", n3);
				}
			}
			
		} else {
			printf("ERROR: Los numeros no son distintos. Reintente.\n");
			goto Inicio;
		}
	} else {
		printf("ERROR: Los numeros deben ser mayores a cero.\n");
		goto Inicio;
	}
	
	printf("------------------------------------\n");
	
	Menu:
		printf("¿Desea comparar otros numeros? (1:Si / 0:No): ");
	scanf("%d", &op);
	
	if (op == 1) {
		goto Inicio;
	} else if (op == 0) {
		printf("Terminado.\n");
	} else {
		printf("ERROR: Opcion invalida. Elija 1 o 0.\n");
		goto Menu;
	}
	
	return 0;
}




