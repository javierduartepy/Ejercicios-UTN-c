#include <stdio.h>
#define MAX 10

void cargarArreglo(int a[]);
void mostrarArreglo(int a[]);
void mostrarInverso(int a[]);
void mostrarInversoBurbuja(int a[]);
int contarNumerosPrimos(int a[]);
int buscarRepeticiones(int a[], int num);
int main() {
	int vectorDatos[MAX];
	int valorBuscado, cantidadRepeticiones;
	
	cargarArreglo(vectorDatos);
	
	printf("\nVisualizacion de Elementos del Arreglo:\n");
	mostrarArreglo(vectorDatos);
	
	printf("\nVisualizacion en sentido inverso:\n");
	mostrarInverso(vectorDatos);
	
	printf("\nCantidad de numeros primos detectados: %d\n", contarNumerosPrimos(vectorDatos));
	
	printf("\nVisualizacion en sentido inverso Burbuja:\n");
	mostrarInversoBurbuja(vectorDatos);
			
	printf("\nIngrese el numero enetero que desea buscar en el vector:\n");
	scanf("%d", &valorBuscado);
	
	cantidadRepeticiones = buscarRepeticiones(vectorDatos, valorBuscado);
	printf("El numero %d se encontro %d veces en el arreglo.\n", valorBuscado, cantidadRepeticiones);
	
	return 0;	
}

void cargarArreglo(int a[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("Ingrese el valor entero para la celda %d: ", i);
		scanf("%d", &a[i]);
	}
}

void mostrarArreglo(int a[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("Indice (%d) - Contenido: %d \n", i, a[i]);
	}
}
	
void mostrarInverso(int a[]){
	int i;
	for(i = MAX - 1; i >= 0; i--){
		printf("Indice (%d) - Contenido: %d \n", i, a[i]);
	}
}

void mostrarInversoBurbuja(int a[]){
	int i,j, aux;
	for(i=(MAX - 1); i>0; i--){
		for(j=MAX-1;j>(MAX-1-i);j--){
			if(a[j] > a[j-1]){
				aux=a[j];
				a[j]=a[j-1];
				a[j-1] = aux;
			}
		}
	}
	for(i=0; i<MAX; i++){
		printf("Indice (%d) - Contenido: %d \n", i, a[i]);
	}
}
	
int contarNumerosPrimos(int a[]){
	int i, j;
	int contadorPrimos = 0;
	for(i=0; i<MAX; i++){
		int numeroEvaluar = a[i];
		if(numeroEvaluar > 0){
			int esPrimo = 1;
			for(j = 2; j*j <= numeroEvaluar; j++){
				if(numeroEvaluar % j == 0){
					esPrimo = 0;
					break;
				}
			}
			if(esPrimo == 1){
				contadorPrimos++;
			}
		}
	}
	return contadorPrimos;
}

int buscarRepeticiones(int a[], int num){
	int i;
	int acumuladorApariciones = 0;
	for(i=0; i<MAX; i++){
		if(a[i]== num){
			acumuladorApariciones++;
		}
	}
	return acumuladorApariciones;
}
