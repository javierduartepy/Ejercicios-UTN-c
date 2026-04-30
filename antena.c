#include <stdio.h>
#include <math.h>

/* Se desea calcular la longitud de cable que se precisa adquirir
para amarrar una antena de 100m. Se sabe que las sujeciones son 3, 
que se amarran a 4/5 de la altura total de la antena y a 20m de la 
base en el suelo. Ademas, se debe prever un 10% adicional para las
sujeciones*/

int main() {
	const float antena = 100.0;
    const float base = 20.0;
	float altura_sujecion, sujecion, raiz, adicional_sujecion, sujecion_total;
			
	altura_sujecion = antena*(4.0/5.0);
    sujecion = (base*base)+(altura_sujecion*altura_sujecion);
    raiz= sqrt(sujecion);
    adicional_sujecion= raiz*1.10;
    sujecion_total= adicional_sujecion*3;
		
	printf("La cantindad de cable que se necesita es: %.2f\n", sujecion_total);
	return 0;
}
