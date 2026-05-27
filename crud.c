#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Ejercicio 5: Arreglos-Registros
5.1. Una empresa de servicios de limpieza necesita almacenar en un arreglo la siguiente información:
*Nro de Cliente
*Tipo de Cliente ( E: Empresa – P: Particular)
•Nombre del Cliente
•Nro.Celular de Contacto
*/

struct cliente {
	int cliente_nro;
	char cliente_nombre[20];
	char cliente_tipo;
	char cliente_cel[12];
};

int main() {
	struct cliente clientes[3];
	struct cliente aux; // Estructura auxiliar para el intercambio
	
	
	// TODAS LAS VARIABLES DECLARADAS ARRIBA DE TODO (Norma estricta de C)
	int i, j, es_valido;
	int total_clientes, total_tipo_E, total_tipo_P;
	int buscado, centro, inicio, fin, encontrado;
	int pos_modificar;
	int id_borrar, pos_borrar;
	// ====================================================================
	// 1. SECCIÓN DE CARGA CONTROLADA
	// ====================================================================
	for(i = 0; i < 3; i++) {
		printf("-----INGRESO DE CLIENTES %d-----\n", i + 1);
		
		printf("Ingrese el numero de cliente: ");
		while(scanf("%d", &clientes[i].cliente_nro) != 1) {
			printf("Atención! Ingrese un numero al cliente: ");
			fflush(stdin);
		}
		fflush(stdin);
		
		do {
			printf("Ingrese E para cliente empresarial o P para privado: ");
			scanf(" %c", &clientes[i].cliente_tipo);
			clientes[i].cliente_tipo = toupper(clientes[i].cliente_tipo);
			if(clientes[i].cliente_tipo != 'P' && clientes[i].cliente_tipo != 'E') {
				printf("Atención! Ingrese P o E: \n");
			}			
		} while(clientes[i].cliente_tipo != 'P' && clientes[i].cliente_tipo != 'E');
		
		do {
			printf("Ingrese el nombre del cliente: ");
			scanf(" %[^\n]", clientes[i].cliente_nombre);
			es_valido = 1;
			for(j = 0; clientes[i].cliente_nombre[j] != '\0'; j++) {
				if(!isalpha(clientes[i].cliente_nombre[j]) && clientes[i].cliente_nombre[j] != ' ') {
					es_valido = 0;
					break;
				}
			}
			if(es_valido == 0) {
				printf("Atencion! Ingrese el nombre del cliente \n");
			}
		} while(es_valido == 0);
		
		printf("Ingrese el numero de telefono del cliente: ");
		scanf(" %s", clientes[i].cliente_cel);
	}
	
	// ====================================================================
	// 2. MUESTRAS ORIGINALES (TAL CUAL TU CÓDIGO - DESORDENADAS)
	// ====================================================================
	printf("--------------------------------------------------------------------\n");
	
	printf("PRIVADO \n");
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'P') {
			printf("Cliente %d\n", i + 1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n");
		}
	}
	
	printf("EMPRESARIAL \n");
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'E') {
			printf("Cliente %d\n", i + 1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n");
		}
	}
	
	printf("--------------------------------------------------------------------\n");
	
	printf("PRIVADO \n");
	printf("[ ");
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'P') {
			printf("(%d). %s, %d, Telefono: %s; ", i + 1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel);
		}
	}
	printf(" ]\n");
	
	printf("EMPRESARIAL \n");	
	printf("[ ");	
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'E') {
			printf("(%d). %s, %d, Telefono: %s; ", i + 1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel);
		}
	}
	printf(" ]\n");
	
	// ====================================================================
	// 3. ALGORITMO DE ORDENAMIENTO DE MAYOR A MENOR (CON EL SIGNO ESCANEDADO <)
	// ====================================================================
	printf("===================LISTA ORDENADA (MAYOR A MENOR)===================\n");
	for(i = 0; i < 2; i++) {
		for(j = i + 1; j < 3; j++) {
			// USAMOS EL SIGNO MENOR (<) PARA LOGRAR EL ORDEN DESCENDENTE
			if(clientes[i].cliente_nro < clientes[j].cliente_nro) {
				aux = clientes[i];
				clientes[i] = clientes[j];
				clientes[j] = aux;				
			}
		}
	}
	
	// Muestras ordenadas por categorías (Tu código pero ahora salen de mayor a menor)
	printf("PRIVADO \n");
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'P') {
			printf("Cliente %d\n", i + 1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n");
		}
	}
	
	printf("EMPRESARIAL \n");
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'E') {
			printf("Cliente %d\n", i + 1);
			printf("Numero de cliente: %d\n", clientes[i].cliente_nro);
			printf("Nombre de cliente: %s\n", clientes[i].cliente_nombre);
			printf("Telefono del cliente: %s\n", clientes[i].cliente_cel);
			printf("\n");
		}
	}
	
	printf("--------------------------------------------------------------------\n");
	
	printf("PRIVADO \n");
	printf("[ ");
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'P') {
			printf("(%d). %s, %d, Telefono: %s; ", i + 1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel);
		}
	}
	printf(" ]\n");
	
	printf("EMPRESARIAL \n");	
	printf("[ ");	
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_tipo == 'E') {
			printf("(%d). %s, %d, Telefono: %s; ", i + 1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel);
		}
	}
	printf(" ]\n");
	
	// ====================================================================
	// 4. MUESTRAS GENERALES UNIFICADAS (ORDENADAS DE MAYOR A MENOR)
	// ====================================================================
	
	// A) Formato de Bloque General Ordenado
	printf("===================BLOQUE GENERAL ORDENADO=======================\n");
	for(i = 0; i < 3; i++) {
		printf("Cliente %d\n", i + 1);
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
	
	// B) Formato de Vector General Directo Ordenado
	printf("===================VECTOR GENERAL ORDENADO=======================\n");
	printf("[ ");
	for(i = 0; i < 3; i++) {
		printf("(%d). %s, %d, Telefono: %s, ", i + 1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_cel);
		if(clientes[i].cliente_tipo == 'E') {
			printf("Empresarial; ");
		} else {
			printf("Privado; ");
		}
	}
	printf("]\n");
	
	// C) Tabla de Listado de Clientes con Totales (Tu imagen)
	printf("\n\t\tListado de Clientes (Tabla)\n");
	printf("-------------------------------------------------------------\n");
	printf("%-12s %-14s %-16s %s\n", "Nro.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
	printf("-------------------------------------------------------------\n");
	
	total_clientes = 0;
	total_tipo_E = 0;
	total_tipo_P = 0;
	
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
	
	// ====================================================================
	// 5. ALGORITMO DE BÚSQUEDA SECUENCIAL
	// ====================================================================
	// Nota: Como ordenamos de Mayor a Menor, la búsqueda Binaria clásica no funciona, 
	// por lo que usamos la búsqueda secuencial que es 100% segura para cualquier orden.
	printf("===================BUSQUEDA SECUENCIAL===========================\n");
	encontrado = -1; 
	
	printf("Ingrese el numero de cliente a buscar: ");
	scanf("%d", &buscado);
	fflush(stdin);
	
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_nro == buscado) {
			encontrado = i; 
			break;          
		}
	}
	
	if (encontrado != -1) {
		printf("¡Cliente Encontrado! -> Nombre: %s, Telefono: %s, Tipo: %s\n\n", 
			   clientes[encontrado].cliente_nombre, 
			   clientes[encontrado].cliente_cel,
			   (clientes[encontrado].cliente_tipo == 'E') ? "Empresarial" : "Privado");
	} else {
		printf("El cliente %d no existe.\n\n", buscado);
	}
	
	// ====================================================================
	// OPERACIONES CRUD EXTRAS: ALTA (MODIFICAR) Y BAJA (BORRAR)
	// ====================================================================
	
	
	printf("\n=================== OPERACION: INSERTAR NUEVO ELEMENTO ===================\n");
	printf("Tu arreglo esta lleno (3/3). Ingrese que posicion desea reemplazar (1, 2 o 3): ");
	while(scanf("%d", &pos_modificar) != 1 || pos_modificar < 1 || pos_modificar > 3) {
		printf("Atencion! Ingrese una posicion valida entre 1 y 3: ");
		fflush(stdin);
	}
	fflush(stdin);
	
	// Convertimos la posición humana a índice de C (ej: renglón 1 es índice 0)
	pos_modificar = pos_modificar - 1; 
	
	printf("--- Cargando nuevos datos para la posicion %d ---\n", pos_modificar + 1);
	printf("Ingrese el NUEVO numero de cliente: ");
	while(scanf("%d", &clientes[pos_modificar].cliente_nro) != 1) {
		printf("Atención! Ingrese un numero valido: ");
		fflush(stdin);
	}
	fflush(stdin);
	
	do {
		printf("Ingrese E o P: ");
		scanf(" %c", &clientes[pos_modificar].cliente_tipo);
		clientes[pos_modificar].cliente_tipo = toupper(clientes[pos_modificar].cliente_tipo);
	} while(clientes[pos_modificar].cliente_tipo != 'P' && clientes[pos_modificar].cliente_tipo != 'E');
	fflush(stdin);
	
	do {
		printf("Ingrese el NUEVO nombre del cliente: ");
		scanf(" %[^\n]", clientes[pos_modificar].cliente_nombre);
		fflush(stdin);
		es_valido = 1;
		for(j = 0; clientes[pos_modificar].cliente_nombre[j] != '\0'; j++) {
			if(!isalpha(clientes[pos_modificar].cliente_nombre[j]) && clientes[pos_modificar].cliente_nombre[j] != ' ') {
				es_valido = 0;
				break;
			}
		}
	} while(es_valido == 0);
	
	printf("Ingrese el NUEVO numero de telefono: ");
	scanf(" %s", clientes[pos_modificar].cliente_cel);
	fflush(stdin);
	
	printf("¡Elemento insertado con exito en el casillero %d!\n", pos_modificar + 1);
	
	
	printf("\n=================== OPERACION: ELIMINAR UN ELEMENTO ===================\n");
	printf("Ingrese el numero de cliente que desea dar de baja (eliminar): ");
	scanf("%d", &id_borrar);
	fflush(stdin);
	
	pos_borrar = -1;
	for(i = 0; i < 3; i++) {
		if(clientes[i].cliente_nro == id_borrar) {
			pos_borrar = i;
			break;
		}
	}
	
	if(pos_borrar != -1) {
		// Borramos los datos limpiando sus campos (Baja lógica)
		clientes[pos_borrar].cliente_nro = 0;
		clientes[pos_borrar].cliente_tipo = ' ';
		strcpy(clientes[pos_borrar].cliente_nombre, "ELIMINADO");
		strcpy(clientes[pos_borrar].cliente_cel, "0");
		printf("¡El cliente numero %d fue dado de baja y limpiado del sistema!\n", id_borrar);
	} else {
		printf("El cliente numero %d no existe, no se pudo eliminar.\n", id_borrar);
	}
	
	// MUESTRA DE COMPROBACIÓN FINAL
	printf("\n--- VECTOR COMPLETO LUEGO DE LAS MODIFICACIONES ---\n");
	printf("[ ");
	for(i = 0; i < 3; i++) {
		printf("(%d). %s, %d, Tipo: %c; ", i + 1, clientes[i].cliente_nombre, clientes[i].cliente_nro, clientes[i].cliente_tipo);
	}
	printf(" ]\n");
	
	
	return 0;
}

