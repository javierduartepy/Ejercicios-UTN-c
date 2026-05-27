#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*Ejercicio 5: Arreglos-Registros
5.1. Una empresa de servicios de limpieza necesita almacenar en un arreglo la siguiente información:
*Nro de Cliente
*Tipo de Cliente ( E: Empresa – P: Particular)
•Nombre del Cliente
•Nro.Celular de Contacto*/

/*Se pide:
•Cargar el arreglo.
*Ordenar por numero de cliente*/

struct cliente{
	int cliente_nro;
	char cliente_nombre[20];
	char cliente_tipo;
	char cliente_cel[12];
};

int main() {
	struct cliente clientes[3];
	int i, j, es_valido;
	int buscado, centro;
	int inicio = 0;
	int fin = 2; // El último índice de tu arreglo de 3 elementos (0, 1, 2)
	int encontrado = -1; // Guardará el índice donde se encontró, o -1 si no existe
	int total_clientes = 0;
	int total_tipo_E = 0;
	int total_tipo_P = 0;
	for(i=0; i<3; i++){
		printf("-----INGRESO DE CLIENTES %d-----\n", i+1);
		
		printf("Ingrese el numero de cliente: ");
		while(scanf("%d", &clientes[i].cliente_nro) !=1){
			printf("Atención! Ingrese un numero al cliente: ");
			fflush(stdin);
		}
		fflush(stdin);
		
		do{
			printf("Ingrese E para cliente empresarial o P para privado: ");
			scanf(" %c", &clientes[i].cliente_tipo);
			clientes[i].cliente_tipo = toupper(clientes[i].cliente_tipo);
			if(clientes[i].cliente_tipo != 'P' && clientes[i].cliente_tipo != 'E'){
				printf("Atención! Ingrese P o E: \n");
			}			
		}while(clientes[i].cliente_tipo != 'P' && clientes[i].cliente_tipo != 'E');
		
		do{
			printf("Ingrese el nombre del cliente: ");
			scanf(" %[^\n]", clientes[i].cliente_nombre);
			es_valido=1;
			for(j=0; clientes[i].cliente_nombre[j] != '\0'; j++){
				if(!isalpha(clientes[i].cliente_nombre[j]) && clientes[i].cliente_nombre[j] != ' '){
					es_valido = 0;
					break;
				}
			}
			if(es_valido == 0){
				printf("Atencion! Ingrese el nombre del cliente \n");
			}
		} while(es_valido == 0);
		
		printf("Ingrese el numero de telefono del cliente: ");
		scanf(" %s", &clientes[i].cliente_cel);
	}
	
	printf("--------------------------------------------------------------------\n");
	
	printf("PRIVADO \n"	);
	for(i=0; i<3; i++){
		if(clientes[i].cliente_tipo == 'P'){
			printf("Cliente %d\n", i+1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n");
		}
	}
	printf("EMPRESARIAL \n"	);
	for(i=0; i<3; i++){
		if(clientes[i].cliente_tipo == 'E'){
			printf("Cliente %d\n", i+1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n"	);
		}
	}
	
	printf("--------------------------------------------------------------------\n");
	printf("[ ");
	printf("PRIVADO \n");
	for(i=0; i<3; i++){
		if(clientes[i].cliente_tipo == 'P'){
			printf("(%d). %s, %d, Telefono: %s; ", i+1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel );
		}
	}
	printf(" ]\n");
	
	printf("EMPRESARIAL \n");	
	printf("[ ");	
	for(i=0; i<3; i++){
		
		if(clientes[i].cliente_tipo == 'E'){
			printf("(%d). %s, %d, Telefono: %s; ", i+1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel );
		}
	}
	printf(" ]\n");
	
	printf("===================LISTA ORDENADA===============================\n");
	struct cliente aux;
	for(i=0; i<2; i++){
		for(j=i+1; j<3; j++){
			if(clientes[i].cliente_nro>clientes[j].cliente_nro){
				aux = clientes[i];
				clientes[i] = clientes[j];
				clientes[j] = aux;				
			}
		}
	}
	printf("PRIVADO \n"	);
	for(i=0; i<3; i++){
		if(clientes[i].cliente_tipo == 'P'){
			printf("Cliente %d\n", i+1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n");
		}
	}
	printf("EMPRESARIAL \n"	);
	for(i=0; i<3; i++){
		if(clientes[i].cliente_tipo == 'E'){
			printf("Cliente %d\n", i+1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n"	);
		}
	}
	
	printf("--------------------------------------------------------------------\n");
	printf("[ ");
	printf("PRIVADO \n");
	for(i=0; i<3; i++){
		if(clientes[i].cliente_tipo == 'P'){
			printf("(%d). %s, %d, Telefono: %s; ", i+1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel );
		}
	}
	printf(" ]\n");
	
	printf("EMPRESARIAL \n");	
	printf("[ ");	
	for(i=0; i<3; i++){
		
		if(clientes[i].cliente_tipo == 'E'){
			printf("(%d). %s, %d, Telefono: %s; ", i+1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel );
		}
	}
	printf(" ]\n");
	printf("\n");	
	printf("===================VECTOR GENERAL ORDENADO=======================\n");
	printf("\n");
	printf("[ "); 
	for(i = 0; i < 3; i++) {
		printf("(%d). %s, %d, Telefono: %s, %s; ", 
			   i+1, 
			   clientes[i].cliente_nombre, 
			   clientes[i].cliente_nro, 
			   clientes[i].cliente_cel,
			   (clientes[i].cliente_tipo == 'E') ? "Empresarial" : "Privado"
			   );
	}
	printf("]\n");
	printf("\n");	
	printf("===================BLOQUE GENERAL ORDENADO=======================\n");
	for(i = 0; i < 3; i++) {
		printf("Cliente %d\n", i+1);
		printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
		printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
		printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
		
		if(clientes[i].cliente_tipo == 'E') {
			printf("Tipo de cliente: Empresarial\n");
		} else {
			printf("Tipo de cliente: Privado\n");
		}
		printf("\n");
	}
	printf("\n");
	printf("===================BUSQUEDA DE CLIENTE===========================\n");
	printf("\n");
	
	
	printf("Ingrese el numero de cliente que desea buscar: ");
	scanf("%d", &buscado);
	fflush(stdin);
	
	// ALGORITMO DE BÚSQUEDA BINARIA
	while (inicio <= fin) {
		centro = (inicio + fin) / 2;		
		if (clientes[centro].cliente_nro == buscado) {
			encontrado = centro; 
			break;               
		}
		else if (buscado < clientes[centro].cliente_nro) {
			fin = centro - 1;   
		}
		else {
			inicio = centro + 1; 
		}
	}
	
	
	if (encontrado != -1) {
		printf("\n¡Cliente Encontrado con exito!\n");
		printf("Nombre: %s\n", clientes[encontrado].cliente_nombre);
		printf("Telefono: %s\n", clientes[encontrado].cliente_cel);
		printf("Tipo: %s\n", (clientes[encontrado].cliente_tipo == 'E') ? "Empresarial" : "Privado");
	} else {
		printf("\nEl cliente numero %d no existe en el sistema.\n", buscado);
	}
	
	printf("\n");
	printf("===================TABLA===========================\n");
	printf("\n");
	printf("\n\t\tListado de Clientes\n");
	printf("-------------------------------------------------------------\n");
	printf("%-12s %-14s %-16s %s\n", "Nro.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
	printf("-------------------------------------------------------------\n");
	
	for(i = 0; i < 3; i++) {
		
		printf("%-12d ", clientes[i].cliente_nro);
		
		if(clientes[i].cliente_tipo == 'E') {
			printf("%-14s ", "Empresarial");
			total_tipo_E++; 
		} else {
			printf("%-14s ", "Privado");
			total_tipo_P++; 
		}
		
		printf("%-16s ", clientes[i].cliente_nombre);
		printf("%s\n", clientes[i].cliente_cel);
		
		total_clientes++; 
	}
	
	printf("-------------------------------------------------------------\n");
	
	printf("Total de Clientes: %d\n", total_clientes);
	printf("Total de Clientes Tipo E: %d\n", total_tipo_E);
	printf("Total de Clientes Tipo P: %d\n", total_tipo_P);
	printf("-------------------------------------------------------------\n\n");
	
	
	printf("===================BUSQUEDA SECUENCIAL===========================\n");
	encontrado = -1; // Volvemos a poner la bandera en -1
	
	printf("Ingrese el numero de cliente que desea buscar: ");
	scanf("%d", &buscado);
	fflush(stdin);
	
	// ALGORITMO SECUENCIAL
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_nro == buscado) {
			encontrado = i; // Guardamos la posición donde coincidió
			break;          // Frenamos el bucle porque ya lo encontramos
		}
	}
	
	// MUESTRA DE RESULTADOS (Igual que en la binaria)
	if (encontrado != -1) {
		printf("\n¡Cliente Encontrado!\n");
		printf("Nombre: %s\n", clientes[encontrado].cliente_nombre);
	} else {
		printf("\nEl cliente %d no existe.\n", buscado);
	}
	
	
	return 0;
}

