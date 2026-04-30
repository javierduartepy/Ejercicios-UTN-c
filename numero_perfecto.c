#include <stdio.h>

int main() {
	int num, i;
	int suma=0;
	printf("Ingrese un numero: ");
	scanf("%d", &num);
	
	for (i=1; i<=(num/2); i++){
		if (num%i==0){
			printf("%d \n", i);
			suma+=i;
		}		
	}
	printf("\nSuma total de divisores: %d\n", suma);
	if (suma == num && num > 0) {
		printf("El numero %d es perfecto.\n", num, i);
	} else {
		printf("El numero %d no es perfecto.\n", num, i);
	}
	
	return 0;
}

