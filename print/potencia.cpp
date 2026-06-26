#include <stdio.h>
#include <conio.h>

unsigned long long int potencia(int a, int n);

int main(){
	int base;
	int elevado;
	unsigned long long int resultado;
	do{
		printf("\n Ingrese un valor para la base: ");
		scanf("%d", &base);
		printf("\n Ingrese un valor para la potencia: ");
		scanf("%d", &elevado);
		if(base==0 && elevado<=0){
			printf("Error. Si la base es 0 ingrese un valor positivo \n");
		}
	}while(base==0 && elevado<=0);	
	
	resultado = (potencia(base, elevado-1)*base);
	if(elevado<0){
		printf("El resultado del numero %d elevado a %d es: 1/%llu",base, elevado, resultado);
		
	}else{
		printf("El resultado del numero %d elevado a %d es: %llu",base, elevado, resultado);		
	}
	getch();
 	return 0;
}

unsigned long long int potencia(int a, int n){
	if(n==1){
		return a;		
	}	
	else if(n==0 && a!=0){
		return 1;
	}
	else{
		return (potencia(a, n-1)*a);
	}
}

