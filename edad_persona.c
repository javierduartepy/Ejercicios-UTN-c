#include <stdio.h>

int main() {
	int dia_nacimiento, mes_nacimiento, anio_nacimiento;
	int dia_actual, mes_actual, anio_actual;
	int edad, limite_dias;
	Ingresar_Anio:
		printf("Ingrese año de nacimiento(4 dígitos): ");
	scanf("%d", &anio_nacimiento);
	if (anio_nacimiento < 0) goto Ingresar_Anio;
	Ingresar_Mes:
		printf("Ingrese mes de nacimiento(dos dígitos): ");
	scanf("%d", &mes_nacimiento);
	if (mes_nacimiento < 1 || mes_nacimiento > 12) goto Ingresar_Mes;
	if (mes_nacimiento == 4 || mes_nacimiento == 6 || mes_nacimiento == 9 || mes_nacimiento == 11) {
		limite_dias = 30;
	} else if (mes_nacimiento == 2) {
		limite_dias = 28;
	} else {
		limite_dias = 31;
	}
	Ingresar_Dia:
			   printf("Ingrese dia de nacimiento(dos dígitos): ");
	scanf("%d", &dia_nacimiento);
	if (dia_nacimiento < 1 || dia_nacimiento > limite_dias) goto Ingresar_Dia;
	printf("Ingrese la fecha actual(dos dígitos): ");
	scanf("%d", &dia_actual);
	printf("Ingrese mes actual(dos dígitos): ");
	scanf("%d", &mes_actual);
	printf("Ingrese año actual(4 dígitos): ");
	scanf("%d", &anio_actual);
	edad = anio_actual - anio_nacimiento;
	if (mes_actual < mes_nacimiento) {
		edad = edad - 1;
	} else if (mes_actual == mes_nacimiento && dia_actual < dia_nacimiento) {
		edad = edad - 1;
	}
	printf("\nLa edad exacta es: %d años cumplidos.\n", edad);
	
	return 0; 
}

