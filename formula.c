#include <stdio.h>
#include <math.h>

/* 
* OBJETIVO: Calcular las raices de una ecuacion cuadratica,
considerando los 
siguientes requerimientos
* ENTRADAS: Coeficientes a=1, b=4, c=-5.
* RESTRICCIONES: Si el vlaor (d) es negativo, no se operan las raices.
* SALIDA: Valores de d, e, x1 y x2 si existen raices reales.
*/

int main() {
	const float a = 1.0;
	const float b = 4.0;
	const float c = -5.0;
	float d, e, x1, x2;
	
	d = (b * b) - (4 * a * c);
	
	if (d < 0) {
		printf("No existen ra�ces reales para esta ecuaci�n.\n");
	} else {
		e = sqrt(d);
		x1 = (-b + e) / (2 * a);
		x2 = (-b - e) / (2 * a);
		
		printf("C�lculo exitoso:\n");
		printf("------------------\n");
		printf("Valor de d: %.2f\n", d);
		printf("Ra�z e: %.2f\n", e);
		printf("Resultado x1: %.2f\n", x1);
		printf("Resultado x2: %.2f\n", x2);
	}
	
	return 0;
}


