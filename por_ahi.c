// RECORRIDO INVERTIDO PARA MOSTRAR DE ATRÁS PARA ADELANTE
for(i = 2; i >= 0; i--) { // Arranca en el último índice (2) y baja hasta el cero
	printf("(%d). %s, %d; ", i+1, clientes[i].cliente_nombre, clientes[i].cliente_nro);
}

// ORDENAMIENTO DESCENDENTE (MAYOR A MENOR)
for(i = 0; i < 2; i++) {
	for(j = i + 1; j < 3; j++) {
		// Al usar el signo MENOR (<), los números grandes se mueven hacia la izquierda
		if(clientes[i].cliente_nro < clientes[j].cliente_nro) { 
			aux = clientes[i];
			clientes[i] = clientes[j];
			clientes[j] = aux;
		}
	}
}

// --- ORDENAMIENTO DE MAYOR A MENOR (MÉTODO SECUENCIAL) ---
struct cliente aux;

for(i = 0; i < 2; i++) {
	for(j = i + 1; j < 3; j++) {
		
		// Al usar el signo MENOR (<), si el de la izquierda es más chico, se intercambia.
		// Esto empuja los números más grandes hacia el principio del vector.
		if(clientes[i].cliente_nro < clientes[j].cliente_nro) {
			aux = clientes[i];
			clientes[i] = clientes[j];
			clientes[j] = aux;
		}
	}
}


