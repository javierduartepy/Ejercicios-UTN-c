#include <stdio.h>
#include <string.h> // Se necesita para usar strcmp (comparar textos)

// Definimos la estructura básica como la pediste
struct Persona {
	char dni[16];      // El DNI ahora es un texto de hasta 15 caracteres
	char apellido[30];
	char nombre[30];
};

// Pasamos las funciones usando "void"
void ordenarBurbuja(struct Persona p[], int n); /*cantidad total de personas es n es lo mismo que poner el numero y p[] es la lista*/
void mostrarPersonas(struct Persona p[], int n);

int main() {
	// Datos fijos para no perder tiempo cargando
	struct Persona personas[5] = {
		{"45000111", "Gomez", "Carlos"},
		{"23000222", "Alvarez", "Maria"},
		{"12000333", "Gomez", "Ana"},      // Mismo apellido, pero DNI "12..." es menor que "45..."
		{"38000444", "Blanco", "Jorge"},
		{"11000555", "Alvarez", "Maria"}   // Mismo apellido, DNI "11..." es menor que "23..."
	};
	
	// Llamamos a las funciones
	ordenarBurbuja(personas, 5);
	mostrarPersonas(personas, 5);
	
	return 0;
}

void ordenarBurbuja(struct Persona p[], int n) {
	struct Persona aux; // Variable temporal para hacer el intercambio de cajas
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			
			// ¿QUÉ ES STRCMP? 
			// Es una función de C que compara dos textos ordenados alfabéticamente.
			// Si el primer texto va DESPUÉS que el segundo (ej: "Gomez" y "Alvarez"), devuelve un número mayor a cero (> 0).
			int resultadoApellido = strcmp(p[j].apellido, p[j + 1].apellido);
			
			// ¿QUÉ ES EL DNI COMO TEXTO AQUÍ?
			// Como el DNI ahora es texto, también usamos strcmp para saber cuál es mayor.
			int resultadoDni = strcmp(p[j].dni, p[j + 1].dni);
			
			// CONDICIÓN DE ORDENAMIENTO:
			// Opción A: El apellido actual es alfabéticamente mayor.
			// Opción B: Los apellidos son iguales (resultadoApellido == 0) PERO el DNI actual es mayor.
			if (resultadoApellido > 0 || (resultadoApellido == 0 && resultadoDni > 0)) {
				// Intercambio clásico de burbuja
				aux = p[j];
				p[j] = p[j + 1];
				p[j + 1] = aux;
			}
		}
	}
}

void mostrarPersonas(struct Persona p[], int n) {
	printf("\n%-15s %-15s %-12s\n", "Apellido", "Nombre", "DNI");
	printf("--------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		// Usamos %s para todos porque ahora DNI también es un texto (string)
		printf("%-15s %-15s %-12s\n", p[i].apellido, p[i].nombre, p[i].dni);
	}
}

