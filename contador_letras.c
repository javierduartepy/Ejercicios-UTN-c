#include <stdio.h>
#include <string.h>

int main() {
	char frase[100];
	char letra;
	int i, contador;
	
	
	printf("Ingrese una frase: ");
	scanf(" %[^\n]", frase); 
	fflush(stdin);
	
	printf("Ingrese la letra a buscar: ");
	scanf(" %c", &letra); 
	fflush(stdin);
	
	
	contador = 0;
	for(i = 0; frase[i] != '\0'; i++) {
		if(frase[i] == letra) {
			contador++;
		}
	}
	
	
	printf("La letra '%c' aparece %d veces en la frase.\n", letra, contador);
	
	return 0;
}


