#include <stdio.h>
#include <conio.h>

unsigned long long int fibonacci(int n);

int main() {
	unsigned long long int resultado;
	int valor;
	printf("\n Ingrese un valor:");
	scanf("%d", &valor);
	if(valor < 0){
		printf("Error");
	}else{
		resultado= fibonacci(valor);
		printf("El fibonacci de %d es %llu", valor, resultado);		
	}
	getch();	
	return 0;
}
unsigned long long int fibonacci(int n){
	if(n==0){
	return 0;	
	}
	else if (n==1){
	return 1;
	}
	else{
	return fibonacci(n-1)+fibonacci(n-2);
	}
}

