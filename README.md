# Ejercicios-UTN-c

ARREGLOS
UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD: ESTRUCTURAS DE DATOS Y ARREGLOS UNIDIMENSIONALES
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición formal de Estructura de Datos:
Es una colección de datos que se caracterizan por su organización, su distribución en la memoria física y el conjunto de operaciones matemáticas y lógicas que se definen sobre ellos.
Criterio de Clasificación por la Administración de Memoria:
Estructuras Estáticas:
Son aquellas en las que el espacio ocupado en la memoria RAM se asigna de forma definitiva en tiempo de compilación, antes de que el programa se ejecute. Su tamaño es fijo y es imposible modificarlo durante la ejecución del programa.
Ventaja: El acceso a los datos es directo y extremadamente rápido.
Desventaja: Falta de flexibilidad. Si se dimensiona de más, se produce desperdicio de memoria. Si se dimensiona de menos, ocurre un desbordamiento físico.
Ejemplos primitivos: Boolean, Char, Integer, Real.
Ejemplos compuestos: Arreglos, Conjuntos, Strings, Registros, Archivos.
Estructuras Dinámicas:
Son aquellas que no poseen restricciones fijas en el tamaño de la memoria ocupada. Gestionan el espacio en tiempo de ejecución mediante el uso de punteros y asignación en la zona de memoria conocida como Heap.
Subclasificación Lineal: Pilas, Colas, Listas enlazadas.
Subclasificación No Lineal: Árboles, Grafos.
Definición Abstracta de un Arreglo (Array / Vector):
Se define técnicamente como un conjunto finito, ordenado y homogéneo de elementos de datos.
Finito: Implica que existe un número específico, determinado y contable de celdas en el arreglo. El límite superior debe ser definido por el programador.
Ordenado: Significa que las celdas están dispuestas de forma secuencial, donde existe un elemento cero, un elemento primero, un segundo, y así sucesivamente, accesibles mediante un índice numérico.
Homogéneo: Significa que todos y cada uno de los elementos del arreglo pertenecen estrictamente al mismo tipo de dato básico, ocupando idéntica cantidad de bytes en el hardware.
Características de los Arreglos en Lenguaje C:
Memoria Contigua: Un arreglo consta de posiciones de memoria consecutivas y de igual tamaño en el hardware de la RAM.
Direccionamiento Base: La dirección de memoria más baja corresponde matemáticamente al primer elemento (índice cero) y la más alta al último elemento. El nombre del arreglo funciona internamente como un puntero constante a dicha dirección base.
Dimensiones: Un arreglo puede ser unidimensional (vectores) o multidimensional (matrices).
Fórmula de Ocupación de Espacio: El espacio total en bytes utilizado por un arreglo es igual a la cantidad total de elementos multiplicada por el tamaño en bytes del tipo de dato base (por ejemplo, 4 bytes para un entero de 32 bits).
________________________________________
2.	ANÁLISIS DE OPERACIONES Y SINTAXIS CRÍTICA EN C
Declaración de un Arreglo Unidimensional:
Sintaxis: tipo nombre_arreglo(tamaño);
Ejemplo de cátedra: int elem(10);
Donde int determina que cada celda aloja un entero, elem es el identificador, y el valor entre corchetes es la cardinalidad. Los índices válidos para este ejemplo van estrictamente desde elem(0) hasta elem(9).
Inicialización por Declaración y Reglas de Omisión:
Si se declara un arreglo inicializando solo una parte de sus celdas, el estándar de C inicializa automáticamente en cero todas las posiciones restantes.
Ejemplo: int y(30) = {2, 4, 5}; -> Las celdas 0, 1 y 2 guardan esos valores, mientras que de la celda 3 a la 29 se cargan con el valor 0.
Error de Desbordamiento: int z(3) = {1, 2, 3, 4}; -> Provoca un fallo crítico de compilación por exceso de elementos en el espacio reservado.
Mecánica de Carga y Lectura Secuencial:
Para la carga por teclado dentro de bucles, el uso del operador de dirección (ampersand) es estrictamente obligatorio para indicar al flujo de entrada en qué dirección exacta de memoria RAM guardar el valor.
Sintaxis de carga: scanf("%d", &lista(i));
Sintaxis de muestra: printf("%d", lista(i)); (No lleva ampersand porque accede directamente al valor contenido).
Paso de Arreglos a Módulos (Funciones y Procedimientos):
En Lenguaje C, los arreglos siempre se transmiten por referencia de forma implícita. Al invocar un módulo pasando el nombre del vector, se está enviando la dirección de memoria de la celda cero. Por lo tanto, cualquier modificación, ordenamiento o asignación de datos que realice el módulo afectará de forma directa y permanente a las variables del bloque principal (main).
________________________________________
3.	CÓDIGO FUENTE DE RESOLUCIÓN - ACTIVIDAD 1 (USO DE FOR)
A continuación se presenta la resolución modular estructurada para la Actividad 1. Todo el código utiliza estructuras de control definidas y funciones con pasaje de parámetros.
#include <stdio.h>
#define MAX 10
void cargarArreglo(int a);
void mostrarArreglo(int a);
void mostrarInverso(int a);
int contarNumerosPrimos(int a);
int buscarRepeticiones(int a, int num);
int main() {
int vectorDatos(MAX);
int valorBuscado, cantidadRepeticiones;
cargarArreglo(vectorDatos);
printf("\nVisualizacion de Elementos del Arreglo:\n");
mostrarArreglo(vectorDatos);
printf("\nVisualizacion en Sentido Inverso:\n");
mostrarInverso(vectorDatos);
printf("\nCantidad total de numeros primos detectados: %d\n", contarNumerosPrimos(vectorDatos));
printf("\nIngrese el numero entero que desea buscar en el vector: ");
scanf("%d", &valorBuscado);
cantidadRepeticiones = buscarRepeticiones(vectorDatos, valorBuscado);
printf("El numero %d se encontro %d veces en el arreglo.\n", valorBuscado, cantidadRepeticiones);
return 0;
}
void cargarArreglo(int a) {
int i;
for(i = 0; i < MAX; i++) {
printf("Ingrese el valor entero para la celda %d: ", i);
scanf("%d", &a(i));
}
}
void mostrarArreglo(int a) {
int i;
for(i = 0; i < MAX; i++) {
printf("Indice (%d) - Contenido: %d\n", i, a(i));
}
}
void mostrarInverso(int a) {
int i;
for(i = MAX - 1; i >= 0; i--) {
printf("Indice (%d) - Contenido: %d\n", i, a(i));
}
}
int contarNumerosPrimos(int a) {
int i, j, contadorPrimos = 0;
for(i = 0; i < MAX; i++) {
int numeroEvaluar = a(i);
if (numeroEvaluar > 1) {
int esPrimo = 1;
for(j = 2; j * j <= numeroEvaluar; j++) {
if (numeroEvaluar % j == 0) {
esPrimo = 0;
break;
}
}
if (esPrimo == 1) {
contadorPrimos++;
}
}
}
return contadorPrimos;
}
int buscarRepeticiones(int a, int num) {
int i, acumuladorApariciones = 0;
for(i = 0; i < MAX; i++) {
if(a(i) == num) {
acumuladorApariciones++;
}
}
return acumuladorApariciones;
}
________________________________________
4.	CÓDIGO FUENTE DE RESOLUCIÓN - ACTIVIDAD 2 (USO DE WHILE Y VALIDACIONES)
A continuación se presenta la resolución para la Actividad 2, empleando bucles condicionales indeterminados para el proceso de carga y control estricto de rangos de índices.
#include <stdio.h>
#define TAMANIO 10
void cargarConBucleWhile(int arreglo);
void mostrarElementosArreglo(int arreglo);
void verificarExistenciaYContar(int arreglo, int buscar);
void mostrarContenidoPorIndice(int arreglo, int posicion);
int main() {
int datos(TAMANIO);
int numeroAInquirir, posicionConsultar;
printf("Control de Carga de Datos mediante Bucle While:\n");
cargarConBucleWhile(datos);
printf("\nElementos Registrados en Memoria:\n");
mostrarElementosArreglo(datos);
printf("\nIngrese el numero entero a verificar y contar: ");
scanf("%d", &numeroAInquirir);
verificarExistenciaYContar(datos, numeroAInquirir);
printf("\nIngrese la posicion de la celda a consultar (rango 0 a 9): ");
scanf("%d", &posicionConsultar);
mostrarContenidoPorIndice(datos, posicionConsultar);
return 0;
}
void cargarConBucleWhile(int arreglo) {
int indiceActual = 0;
while (indiceActual < TAMANIO) {
printf("Ingrese valor numerico para la posicion (%d): ", indiceActual);
scanf("%d", &arreglo(indiceActual));
indiceActual++;
}
}
void mostrarElementosArreglo(int arreglo) {
int i;
for (i = 0; i < TAMANIO; i++) {
printf("Posicion (%d) almacena el valor: %d\n", i, arreglo(i));
}
}
void verificarExistenciaYContar(int arreglo, int buscar) {
int i;
int contadorOcurrencias = 0;
int banderaEncontrado = 0;
for (i = 0; i < TAMANIO; i++) {
if (arreglo(i) == buscar) {
banderaEncontrado = 1;
contadorOcurrencias++;
}
}
if (banderaEncontrado == 1) {
printf("Resultado del analisis: El numero %d SI existe dentro del arreglo.\n", buscar);
printf("Se registro una frecuencia de aparicion de %d veces.\n", contadorOcurrencias);
} else {
printf("Resultado del analisis: El numero %d NO se encuentra registrado en el arreglo.\n", buscar);
}
}
void mostrarContenidoPorIndice(int arreglo, int posicion) {
if (posicion >= 0 && posicion < TAMANIO) {
printf("Consulta exitosa: En el indice %d se encuentra el valor: %d\n", posicion, arreglo(posicion));
} else {
printf("Fallo de consulta: El indice %d se encuentra fuera de los limites legales del vector.\n", posicion);
}
}


UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD: ALGORITMOS DE BÚSQUEDA, INSERCIÓN Y ELIMINACIÓN EN ARREGLOS
1.	MARCO TEÓRICO ACADÉMICO PARA EXAMEN
Clasificación de los Algoritmos de Búsqueda:
Un algoritmo de búsqueda tiene como objetivo localizar la posición (índice) de un valor clave dentro de un vector. Su estrategia cambia según el estado del arreglo:
1.	Arreglo desordenado sin elementos repetidos: Se aplica búsqueda secuencial. El algoritmo recorre el vector desde el índice cero y se detiene inmediatamente al encontrar la primera coincidencia (eficiencia promedio).
2.	Arreglo desordenado con elementos repetidos: Requiere búsqueda secuencial exhaustiva. El bucle debe recorrer obligatoriamente la totalidad del arreglo para contabilizar todas las ocurrencias, sin importar si encontró el valor en las primeras celdas.
3.	Arreglo ordenado sin elementos repetidos: Permite aplicar el algoritmo de Búsqueda Binaria o Dicotómica, reduciendo drásticamente el tiempo de procesamiento.
4.	Arreglo ordenado con elementos repetidos: Se combina la búsqueda binaria para hallar el núcleo del elemento y luego se realiza un escaneo lateral secuencial para agrupar los duplicados contiguos.
Mecánica Avanzada de la Búsqueda Binaria:
Es un algoritmo de división y conquista aplicable únicamente sobre vectores ordenados de forma ascendente o descendente.
Procedimiento:
1.	Se establecen dos índices apuntadores: Primero (inicializado en 0) y Ultimo (inicializado en tamaño menos 1).
2.	Se calcula el elemento central: Central = (Primero + Ultimo) / 2.
3.	Se compara el valor central con la clave buscada.
4.	Si coinciden, la búsqueda finaliza con éxito.
5.	Si la clave es menor al valor central, se descarta la mitad derecha del vector, redefiniendo el apuntador Ultimo = Central - 1.
6.	Si la clave es mayor al valor central, se descarta la mitad izquierda, redefiniendo el apuntador Primero = Central + 1.
7.	El proceso se repite en intervalos cada vez menores hasta hallar el elemento o hasta que Primero sea mayor que Ultimo, lo que demuestra la inexistencia del valor.
Mecánica de la Operación de Inserción:
Para añadir un elemento en un arreglo estático se deben verificar dos condiciones de hardware:
1.	Disponibilidad de espacio: El vector no debe estar lleno. Debe contar con celdas libres en sus límites superiores.
2.	Desplazamiento de memoria hacia la derecha (Right Shift): Si la inserción ocurre al inicio o al medio de un vector ordenado, todos los elementos posteriores a la posición de destino deben moverse físicamente una posición hacia la derecha para liberar la celda correspondiente. El recorrido del bucle de desplazamiento debe realizarse de atrás hacia adelante (desde el último elemento hasta el índice de inserción) para evitar la sobrescritura y pérdida de datos.
Mecánica de la Operación de Eliminación:
Consiste en suprimir un elemento existente y reorganizar la estructura física:
1.	Localización previa: Se debe hallar el índice exacto donde se ubica el valor a eliminar (usando búsqueda secuencial o binaria).
2.	Desplazamiento de memoria hacia la izquierda (Left Shift): Una vez desalojado el valor, se produce un espacio vacío. Los elementos situados a la derecha de dicha posición deben desplazarse una celda hacia la izquierda. El recorrido del bucle se realiza de adelante hacia atrás (desde el índice eliminado hasta el final activo).
3.	Actualización de cardinalidad: El contador de elementos lógicos del vector disminuye en una unidad, quedando libre la última celda física.
________________________________________
2.	RESOLUCIÓN DE LA GUÍA DE REPASO GENERAL (PÁGINA 2)
A continuación se expone el código fuente unificado que resuelve de forma modular y con pasaje de parámetros todas las consignas requeridas en la diapositiva de repaso:
•	Carga en etapa de definición.
•	Muestra secuencial separada por dos guiones medios.
•	Suma y cálculo preciso de promedio.
•	Filtrado analítico de elementos mayores a la mitad del promedio.
•	Consulta de contenido mediante indexación por teclado.
•	Verificación booleana de pertenencia de un elemento.
#include <stdio.h>
#define TAM 10
void mostrarArregloSeparado(int vec);
int calcularSuma(int vec);
float calcularPromedio(int suma);
void mostrarMayoresMitadPromedio(int vec, float promedio);
void consultarPosicion(int vec);
void verificarPertenencia(int vec);
int main() {
int sumaTotal;
float promedioGeneral;
// Consigna 1: Cargar un arreglo de tipo entero de 10 elementos en etapa de definición
int arreglo(TAM) = {12, 45, 8, 23, 67, 14, 5, 30, 89, 2};
printf("=== CONSIGNA 1: MOSTRAR ELEMENTOS SEPARADOS POR DOS GUIONES ===\n");
mostrarArregloSeparado(arreglo);
printf("\n=== CONSIGNA 2: CALCULO DE SUMA Y PROMEDIO ===\n");
sumaTotal = calcularSuma(arreglo);
promedioGeneral = calcularPromedio(sumaTotal);
printf("Suma total de los elementos: %d\n", sumaTotal);
printf("Promedio calculado del vector: %.2f\n", promedioGeneral);
printf("\n=== CONSIGNA 3: ELEMENTOS MAYORES A LA MITAD DEL PROMEDIO ===\n");
mostrarMayoresMitadPromedio(arreglo, promedioGeneral);
printf("\n=== CONSIGNA 4: CONSULTA DE ELEMENTO POR POSICION ===\n");
consultarPosicion(arreglo);
printf("\n=== CONSIGNA 5: BUSQUEDA Y PERTENENCIA DE VALOR ===\n");
verificarPertenencia(arreglo);
return 0;
}
// Muestra el contenido uno al lado del otro separado por dos guiones medios
void mostrarArregloSeparado(int vec) {
int i;
for(i = 0; i < TAM; i++) {
printf("%d", vec(i));
// Evita imprimir los guiones después del último elemento
if(i < TAM - 1) {
printf(" -- ");
}
}
printf("\n");
}
// Calcula la sumatoria iterativa de las celdas
int calcularSuma(int vec) {
int i;
int acumulador = 0;
for(i = 0; i < TAM; i++) {
wl_acumulador = acumulador + vec(i); // Nota: acumulador += vec(i);
acumulador = wl_acumulador;
}
return acumulador;
}
// Calcula el promedio usando casteo flotante para no perder precisión decimal
float calcularPromedio(int suma) {
float prom;
prom = (float)suma / TAM;
return prom;
}
// Muestra los elementos que superan el umbral matemático de la mitad del promedio
void mostrarMayoresMitadPromedio(int vec, float promedio) {
int i;
float umbral;
umbral = promedio / 2.0;
printf("La mitad del promedio es: %.2f\n", umbral);
printf("Elementos que cumplen la condicion:\n");
for(i = 0; i < TAM; i++) {
if((float)vec(i) > umbral) {
printf("Indice (%d) - Valor %d es mayor que %.2f\n", i, vec(i), umbral);
}
}
}
// Permite ingresar una posición por teclado e indica el elemento asociado
void consultarPosicion(int vec) {
int posicion;
printf("Ingrese la posicion a consultar (rango legal de 0 a 9): ");
scanf("%d", &posicion);
// Validación estricta contra desbordamiento de memoria
if(posicion >= 0 && posicion < TAM) {
printf("Validacion exitosa: En la posicion %d se encuentra el elemento: %d\n", posicion, vec(posicion));
} else {
printf("Error critico: La posicion %d no pertenece a los limites del arreglo.\n", posicion);
}
}
// Algoritmo de búsqueda secuencial que determina si un valor pertenece al arreglo
void verificarPertenencia(int vec) {
int i;
int valorBuscado;
int banderaEncontrado = 0; // 0 equivale a falso, 1 equivale a verdadero
printf("Ingrese el valor entero que desea verificar si pertenece al arreglo: ");
scanf("%d", &valorBuscado);
for(i = 0; i < TAM; i++) {
if(vec(i) == valorBuscado) {
banderaEncontrado = 1;
break; // Interrumpe el bucle al hallar la primera coincidencia
}
}
if(banderaEncontrado == 1) {
printf("Resultado: El valor %d SI pertenece al arreglo.\n", valorBuscado);
} else {
printf("Resultado: El valor %d NO pertenece al arreglo.\n", valorBuscado);
}
}
________________________________________
3.	IMPLEMENTACIÓN DE ALGORITMOS COMPLEJOS EN TEXTO PLANO
A continuación se transcriben las funciones nativas en C para los procesos avanzados de Inserción Ordenada y Eliminación explicados en las diapositivas finales.
Código de Función: Inserción al Medio de un Arreglo Ordenado (Shift Right)
Este bloque busca la posición correcta y desplaza los valores para insertar manteniendo el orden:
void insertarAlMedio(int a, int *cantidadLogica, int numeroInsertar, int maxCapacidad) {
int i = 0;
int j;
if (*cantidadLogica >= maxCapacidad) {
printf("Error: No hay posiciones disponibles para la insercion.\n");
return;
}
// Encuentra el primer número que sea mayor al número a insertar
while (i < *cantidadLogica && a(i) < numeroInsertar) {
i++;
}
// Desplaza los elementos una posición hacia la derecha desde el final hasta el índice i
for (j = *cantidadLogica; j > i; j--) {
a(j) = a(j - 1);
}
// Inserta el número en la posición vacía
a(i) = numeroInsertar;
// Incrementa la cantidad de elementos reales del vector
*cantidadLogica = *cantidadLogica + 1;
}
Código de Función: Eliminación en un Arreglo Desordenado (Shift Left)
Este bloque implementa fielmente la lógica de la página 24 del documento de la UTN:
void eliminarElemento(int a, int *cantidadLogica, int numeroEliminar) {
int i = 0;
int j;
int encontrado = 0;
// Búsqueda secuencial del elemento
while (i < *cantidadLogica) {
if (a(i) == numeroEliminar) {
encontrado = 1;
break;
}
i++;
}
if (encontrado == 1) {
// Desplaza los elementos hacia la izquierda para ocupar el espacio del eliminado
for (j = i; j < *cantidadLogica - 1; j++) {
a(j) = a(j + 1);
}
// Modifica la cantidad de elementos válidos en el main
*cantidadLogica = *cantidadLogica - 1;
printf("El elemento %d fue eliminado con éxito.\n", numeroEliminar);
} else {
printf("Elemento no esta en el arreglo.\n");
}
}

UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD: MÉTODO DE ORDENAMIENTO EN ARREGLOS
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición del Proceso de Ordenamiento:
Es la operación de organizar los elementos de una estructura de datos (como un arreglo) en un orden secuencial específico (ascendente o descendente) de acuerdo con un criterio o clave de ordenamiento determinado.
Clasificación por la Ubicación de los Datos:
Ordenamientos Internos:
Son aquellos algoritmos en los que la totalidad de los valores a ordenar residen físicamente en la memoria principal (RAM) de la computadora.
Característica clave: El tiempo requerido para acceder a cualquier celda es idéntico y constante (Acceso Aleatorio), sin importar si se accede a la primera posición o a la última celda del vector.
Ordenamientos Externos:
Son aquellos algoritmos diseñados para manejar conjuntos de datos masivos que no caben en la memoria RAM, por lo que los valores se almacenan en dispositivos de memoria secundaria (discos duros, cintas mágicas, etc.).
Característica clave: El tiempo de acceso a un elemento no es constante, sino que depende directamente de la última posición física accedida por los cabezales de lectura (Acceso Secuencial).
Ejemplos externos: Straight merging, Natural merging, Balanced multiway merging, Polyphase sort.
Clasificación Académica de los Algoritmos Internos:
1.	Algoritmos de Intercambio:
Estrategia: Evalúan los elementos del vector tomándolos de dos en dos (celdas adyacentes). Comparan sus valores y realizan un intercambio físico de posiciones si no se encuentran en el orden adecuado. Este ciclo iterativo se repite sobre el vector hasta completar una pasada entera sin que se registre ningún intercambio.
Ejemplos: Método de la Burbuja (BubbleSort) y QuickSort.
2.	Algoritmos de Inserción:
Estrategia: Analizan los elementos del vector de uno en uno de izquierda a derecha. En cada iteración se toma un valor específico como clave y se lo compara con la sublista de elementos que ya fue ordenada a su izquierda, desplazando los elementos mayores para insertar la clave en su celda correspondiente.
Ejemplos: Inserción Directa, ShellSort, Inserción Binaria.
3.	Algoritmos de Selección:
Estrategia: El algoritmo busca de forma secuencial el elemento con el valor mínimo (o máximo) de todo el conjunto de datos desordenados y lo intercambia de forma directa con el elemento que ocupa la primera posición activa. Luego, repite el proceso buscando el mínimo del resto de la lista, ignorando las posiciones iniciales que ya quedaron fijadas.
Ejemplo: Selección Directa.
________________________________________
2.	IMPLEMENTACIÓN NATIVA EN C DE LOS TRES MÉTODOS ELEMENTALES
A continuación se presentan las funciones modulares escritas en código plano para C, respetando las buenas prácticas de la UTN. Utilizan el pasaje por referencia implícito para modificar el vector original.
Código de Función: Método de la Burbuja (Bubble Sort)
Esta versión utiliza una variable bandera para optimizar el algoritmo y detener las pasadas si el vector ya quedó ordenado de forma anticipada.
void ordenarBurbuja(int a, int tam) {
int i;
int j;
int auxiliar;
int huboIntercambio;
huboIntercambio = 1; // 1 equivale a Verdadero
for (i = 0; i < tam - 1 && huboIntercambio == 1; i++) {
huboIntercambio = 0; // Asumimos que ya está ordenado
for (j = 0; j < tam - 1 - i; j++) {
// Si el elemento actual es mayor al siguiente, se intercambian
if (a(j) > a(j + 1)) {
auxiliar = a(j);
a(j) = a(j + 1);
a(j + 1) = auxiliar;
huboIntercambio = 1; // Se registró un cambio, se requiere otra pasada
}
}
}
}
Código de Función: Método de Inserción Directa (Insertion Sort)
Toma un elemento como clave y realiza el desplazamiento hacia la derecha de los elementos mayores.
void ordenarInsercion(int a, int tam) {
int i;
int j;
int clave;
for (i = 1; i < tam; i++) {
clave = a(i); // Se selecciona el valor actual como clave
j = i - 1;
// Desplaza los elementos de la sublista izquierda que sean mayores que la clave
while (j >= 0 && a(j) > clave) {
a(j + 1) = a(j);
j = j - 1;
}
// Inserta la clave en la posición correcta libre
a(j + 1) = clave;
}
}
Código de Función: Método de Selección Directa (Selection Sort)
Busca el valor mínimo del vector restante e intercambia posiciones al final de cada ciclo.
void ordenarSeleccion(int a, int tam) {
int i;
int j;
int indiceMinimo;
int auxiliar;
for (i = 0; i < tam - 1; i++) {
indiceMinimo = i; // Inicializamos asumiendo que el primero es el mínimo
// Bucle para buscar el elemento más chico en el resto del vector
for (j = i + 1; j < tam; j++) {
if (a(j) < a(indiceMinimo)) {
indiceMinimo = j; // Actualiza el índice del menor valor encontrado
}
}
// Intercambia el mínimo encontrado con el elemento de la posición i
if (indiceMinimo != i) {
auxiliar = a(i);
a(i) = a(indiceMinimo);
a(indiceMinimo) = auxiliar;
}
}
}
________________________________________
3.	COMPARATIVA TÉCNICA DE RENDIMIENTO PARA EXAMEN
A continuación se detalla una tabla comparativa sobre el comportamiento de los tres métodos básicos, un conocimiento analítico muy evaluado en los exámenes teóricos de la UTN.
Método: Burbuja
Complejidad promedio: Alta
Estrategia base: Intercambio de celdas contiguas.
Consumo de memoria: Nulo (Ordena en el lugar).
Ideal para: Vectores casi ordenados o muy pequeños.
Método: Inserción Directa
Complejidad promedio: Moderada
Estrategia base: Inserción en sublista ordenada.
Consumo de memoria: Nulo (Ordena en el lugar).
Ideal para: Flujos de datos que se cargan dinámicamente elemento por elemento.
Método: Selección Directa
Complejidad promedio: Alta
Estrategia base: Búsqueda del mínimo global.
Consumo de memoria: Nulo (Ordena en el lugar).
Ideal para: Casos donde el intercambio físico de datos en memoria sea una operación muy costosa.

CADENAS

UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD: CADENAS DE CARACTERES (STRINGS)
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición Formal de Cadena (String):
En Lenguaje C, una cadena se define técnicamente como una secuencia o conjunto de caracteres (valores de tipo char) alojados en posiciones consecutivas de la memoria RAM, cuyo final está determinado obligatoriamente por la presencia del carácter nulo.
El Carácter Nulo:
El carácter nulo se representa textualmente como \0 y posee el valor numérico absoluto 0 en la tabla ASCII. No representa el carácter cero (el cual posee el valor ASCII 48), sino que actúa exclusivamente como un centinela o marca de fin de cadena para que las funciones del sistema sepan exactamente dónde terminan los datos válidos dentro del arreglo.
Regla de Dimensionamiento (Pregunta de Examen):
Al declarar un arreglo de caracteres destinado a almacenar una cadena, es un requisito de hardware ineludible prever un elemento adicional en el tamaño del vector respecto a la longitud máxima de texto que se planea guardar.
Por ejemplo, para almacenar la palabra FACULTAD (que posee 8 caracteres lógicos), el arreglo debe declararse como mínimo con un tamaño de 9 cels (char texto(9)), reservando el último índice para el carácter nulo. Si se declara char cadena(11), la longitud máxima de texto almacenable será de 10 caracteres.
Mecánica de Inicialización en Etapa de Definición:
Cuando se inicializa un vector de caracteres utilizando comillas dobles, el compilador de C realiza una asignación automática del carácter nulo en la celda final disponible.
Sintaxis automática: char cadena(5) = "hola";
La expresión anterior es exactamente equivalente en bajo nivel a las siguientes dos variantes de asignación celda por celda:
Variante por bloques: char cadena(5) = {'h', 'o', 'l', 'a', '\0'};
Variante por índices individuales:
cadena(0) = 'h';
cadena(1) = 'o';
cadena(2) = 'l';
cadena(3) = 'a';
cadena(4) = '\0';
________________________________________
2.	ANÁLISIS DE OPERACIONES Y PECULIARIDADES SINTÁCTICAS EN C
Operaciones Esenciales sobre Cadenas:
Las diapositivas definen el conjunto de operaciones lógicas aplicables a los strings en C:
1.	Cargar una cadena (lectura por flujo o carácter por carácter).
2.	Recorrer una cadena (evaluación secuencial indexada).
3.	Buscar un carácter en particular.
4.	Acceder a un carácter en una posición determinada.
5.	Acceder a una posición determinada y mostrar su contenido.
6.	Insertar un nuevo carácter (requiere desplazamiento a la derecha).
7.	Eliminar un carácter (requiere desplazamiento a la izquierda).
La Condición de Corte en Bucles de Recorrido:
A diferencia de los vectores numéricos, donde los bucles for requieren conocer el tamaño máximo o límite del define, el recorrido de una cadena se realiza de forma óptima mediante un bucle while cuya condición de corte es la detección del carácter nulo.
Sintaxis del bucle estándar: while (palabra(i) != '\0')
Este bucle se ejecutará dinámicamente tantas veces como caracteres válidos tenga la palabra, deteniéndose exactamente al llegar al centinela.
Peculiaridad de la Lectura con scanf:
En el código de la página 6 y 9 se presenta la lectura mediante el especificador de formato %s:
Sintaxis: scanf("%s", &nombre);
Nota crítica de cátedra: Si bien el programa del PDF incluye el ampersand (&), en el estándar de C puro, el identificador de un arreglo ya funciona por sí mismo como la dirección de memoria base de la primera celda. Por ende, la sintaxis correcta estandarizada es scanf("%s", nombre).
Limitación técnica de examen: El uso de scanf con %s interrumpe la lectura al detectar el primer carácter de espacio en blanco, tabulador o salto de línea. Para leer cadenas que contengan espacios intercalados (como nombres y apellidos juntos), la biblioteca estándar provee funciones alternativas como fgets.
________________________________________
3.	IMPLEMENTACIÓN DE CÓDIGO EN TEXTO PLANO
A continuación se transcriben las dos metodologías de procesamiento expuestas en el material de estudio, adaptadas a funciones estructuradas sin formatos enriquecidos.
Código de Ejemplo 1: Carga por Bloque y Recorrido Vertical (Página 9)
Este programa lee una palabra completa por teclado y utiliza el centinela nulo para recorrerla e imprimir cada carácter en una línea diferente (formato columna).
#include <stdio.h>
#include <conio.h>
#include <string.h>
int main() {
char palabra(50);
int i = 0;
printf("Ingrese Palabra: \n");
scanf("%s", palabra);
printf("Visualizacion de la cadena en columna:\n");
// Recorrido controlado exclusivamente por el caracter nulo centinela
while (palabra(i) != '\0') {
printf("%c\n", palabra(i));
i++;
}
getch();
return 0;
}
Código de Ejemplo 2: Carga y Muestra Carácter por Carácter (Página 10)
Este programa procesa la cadena de forma manual y aislada mediante un tamaño prefijado por un DEFINE, forzando la lectura individual de cada byte del buffer de entrada.
#include <stdio.h>
#include <conio.h>
#define POS 5
int main() {
int i;
char car;
char nom(POS);
i = 0;
printf("Cargar una cadena caracter a caracter:\n");
while (i < POS) {
printf("Ingrese caracter %d: ", i + 1);
// El espacio antes de %c elimina los caracteres residuales o saltos de linea del buffer
scanf(" %c", &car);
nom(i) = car;
i++;
}
i = 0;
printf("\nMostrar la cadena caracter a caracter:\n");
while (i < POS) {
printf("caracter: %c\n", nom(i));
i++;
}
getch();
return 0;
}


ESTRUCTURA

UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD: ESTRUCTURAS DE REGISTRO (STRUCTS) Y ARREGLOS DE ESTRUCTURAS
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición Formal de Estructura o Registro (struct):
Una estructura es un tipo de dato compuesto y estático que agrupa un conjunto de variables lógicamente relacionadas bajo un mismo identificador común. A diferencia de los arreglos tradicionales, las variables agrupadas dentro de una estructura pueden pertenecer estricta y explícitamente a tipos de datos diferentes (heterogéneos).
Concepto de Campo o Miembro:
Cada uno de los componentes o variables individuales declaradas dentro de una estructura de registro se denomina formalmente campo o miembro. Cada campo posee su propio identificador y su propio tipo de dato primitivo o compuesto.
Diferencia Crítica entre Tipo de Estructura y Variable de Estructura:
La definición de una estructura no reserva espacio real en la memoria RAM del ordenador; actúa exclusivamente como una plantilla o molde de un nuevo tipo de dato personalizado. El espacio físico en el hardware solo se asigna cuando se declara formalmente una variable utilizando dicho tipo estructurado.
Sintaxis de Definición y Declaración Base:
Definición de la plantilla:
struct tiponuevo {
tipo1 campo1;
tipo2 campo2;
};
Declaración de la variable:
struct tiponuevo nombre_variable;
Ventajas de Abstracción frente a Arreglos Paralelos:
Para resolver problemas lógicos complejos (como una agenda telefónica o una lista de cuentas bancarias), la programación básica obligaría a declarar múltiples arreglos separados (paralelos) para nombres, apellidos y números. Dicha estrategia desorganiza el algoritmo y dificulta su legibilidad. El uso de estructuras unifica todos los atributos de una misma entidad en un único registro lógico.
Concepto de Arreglo de Estructuras:
Una única variable de estructura solo permite almacenar la información de una entidad individual. Para procesar y administrar grandes volúmenes de registros homogéneos, se declaran arreglos o vectores cuyos elementos internos son estructuras de datos en sí mismas.
Sintaxis: struct tiponuevo nombre_vector(TAMANIO);
________________________________________
2.	ANÁLISIS DE OPERACIONES Y ERRORES SINTÁCTICOS CRÍTICOS EN C
El Operador de Acceso por Punto:
Para leer, escribir o modificar de forma directa un campo específico de una estructura, se utiliza el operador de acceso por punto de forma explícita.
Sintaxis sobre variable simple: nombre_variable.campo1
Sintaxis sobre arreglo de estructuras: nombre_vector(i).campo1
Análisis del Error de Compilación Común (Páginas 9 y 10):
En la diapositiva número 9 se expone un programa con una falla de desbordamiento de memoria severa intencionada para examen. El fragmento declara el vector como struct agenda record(2), reservando memoria física exclusivamente para dos elementos lógicos (índices 0 y 1). Sin embargo, el código procede a realizar asignaciones manuales en los índices record(0), record(1) y record(2). La asignación en el índice 2 provoca una violación de acceso o desbordamiento fuera de los límites legales asignados por el hardware.
Solución académica correcta: Modificar la dimensión en la declaración inicial aumentando la capacidad del vector o empleando directivas de preprocesamiento, por ejemplo: struct agenda record(3).
Mecánica de Vaciado del Buffer de Entrada:
En los códigos de carga interactiva (Página 11), al combinar lecturas de cadenas de texto (usando gets) con lecturas de datos numéricos (como enteros a través de scanf), el residuo del carácter de salto de línea (Enter) queda atrapado físicamente en el buffer del teclado. Si no se remueve, la siguiente lectura de cadena leerá ese salto de línea vacío e ignorará la entrada del usuario.
Mecánica de vaciado: while(getchar() != '\n');
Este bucle lee y descarta de forma iterativa todos los bytes residuales del buffer hasta encontrar el fin de línea, garantizando la consistencia de las cargas secuenciales siguientes.
________________________________________
3.	CÓDIGO FUENTE DE RESOLUCIÓN - SISTEMA DE CONTROL DE CUENTAS (PÁGINAS 13-16)
A continuación se presenta la integración completa, modular y depurada del ejemplo de cuentas bancarias expuesto en las diapositivas finales. El código procesa cargas, visualizaciones tabuladas en formato de informe analítico y lógicas booleanas para estados contables.
#include <stdio.h>
#include <conio.h>
#define NRO 5
struct cuentas {
int nro_cuenta;
char nombre(30);
int saldo;
};
void cargarCuentas(struct cuentas cuen);
void mostrarRegistrosCargados(struct cuentas cuen);
void mostrarFormatoInforme(struct cuentas cuen);
void procesarEstadosCuentas(struct cuentas cuen);
int main() {
struct cuentas listadoCuentas(NRO);
printf("=== ETAPA DE CARGA DE ESTRUCTURAS ===\n");
cargarCuentas(listadoCuentas);
printf("\n=== REGISTROS INDIVIDUALES CARGADOS ===\n");
mostrarRegistrosCargados(listadoCuentas);
printf("\n=== FORMATO DE INFORME CONSOLIDADO ===\n");
mostrarFormatoInforme(listadoCuentas);
printf("\n=== ANALISIS DE ESTADO CONTABLE POR CLIENTE ===\n");
procesarEstadosCuentas(listadoCuentas);
getch();
return 0;
}
// Procesa la carga iterativa utilizando el operador punto sobre cada indice del vector
void cargarCuentas(struct cuentas cuen) {
int i;
for(i = 0; i < NRO; i++) {
printf("Ingrese datos de la Estructura Numero: %d\n", i + 1);
printf("Ingrese Nro de Cuenta: ");
scanf("%i", &cuen(i).nro_cuenta);
printf("Ingrese nombre del Cliente: ");
scanf("%s", cuen(i).nombre);
printf("Ingrese Saldo del Cliente: ");
scanf("%d", &cuen(i).saldo);
printf("\n");
}
}
// Muestra las estructuras individualmente en formato secuencial simple
void mostrarRegistrosCargados(struct cuentas cuen) {
int i;
for(i = 0; i < NRO; i++) {
printf("Nro Cuenta = %d\n", cuen(i).nro_cuenta);
printf("Cliente = %s\n", cuen(i).nombre);
printf("Saldo = %d\n", cuen(i).saldo);
printf("-----------------------\n");
}
}
// Emite un reporte tabulado imitando salidas de consola de nivel profesional
void mostrarFormatoInforme(struct cuentas cuen) {
int i;
printf("Nro. Cuenta Cliente Saldo\n");
printf("------------------------------------\n");
for(i = 0; i < NRO; i++) {
printf("%-15d %-14s %-d\n", cuen(i).nro_cuenta, cuen(i).nombre, cuen(i).saldo);
}
}
// Evalua saldos deudores o acreedores aplicando contadores de ocurrencias
void procesarEstadosCuentas(struct cuentas cuen) {
int i;
int deudor = 0;
int acreedor = 0;
for(i = 0; i < NRO; i++) {
if (cuen(i).saldo < 0) {
printf("El estado de la cuenta para el cliente: %s es: DEUDOR\n", cuen(i).nombre);
deudor++;
} else {
printf("El estado de la cuenta para el cliente: %s es: ACREEDOR\n", cuen(i).nombre);
acreedor++;
}
}
printf("\nEstadisticas Finales del Sistema:\n");
printf("Cantidad Total de Clientes Deudores: %d\n", deudor);
printf("Cantidad Total de Clientes Acreedores: %d\n", acreedor);
}
________________________________________

MATRICES
UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD: ARREGLOS MULTIDIMENSIONALES (MATRICES)
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición Formal de Matriz (Arreglo Bidimensional):
Una matriz se define técnicamente como una estructura de datos estática, homogénea y contigua que organiza sus celdas mediante múltiples subíndices o dimensiones. En el caso de las matrices bidimensionales, la estructura emula una tabla cuadriculada compuesta por filas y columnas.
Sintaxis de Definición y Asignación de Memoria:
Sintaxis base: tipo nombre_matriz(Filas)(Columnas);
Ejemplo de cátedra: int mat(4)(4);
En el hardware, la memoria RAM es unidimensional. Por lo tanto, C almacena las matrices siguiendo el criterio de Orden por Filas (Row-Major Order). Esto significa que los elementos de la fila 0 se ubican de forma consecutiva en la memoria física, seguidos inmediatamente por todos los elementos de la fila 1, y así sucesivamente.
Mecánica de Inicialización Explícita:
Al definir una matriz, se pueden ingresar los valores iniciales directamente usando llaves agrupadoras. El compilador de C procesa las asignaciones de forma secuencial de izquierda a derecha.
Inicialización lineal: int x(2)(3) = {3, 5, 7, -2, 0, 1};
Inicialización estructurada (Buena práctica):
int matriz1(5)(3) = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9},
{10, 11, 12},
{13, 14, 15}
};
El uso de llaves internas no afecta la compilación, pero mejora drásticamente la legibilidad del código fuente, delimitando de forma visual el inicio y fin de cada fila real.
Mecánica de Recorrido mediante Bucles Anidados:
Para procesar o acceder a las celdas de una matriz, es obligatorio anidar tantas estructuras repetitivas como dimensiones posea la estructura. En matrices bidimensionales se emplea un bucle externo (controlado tradicionalmente por la variable i) para fijar la fila activa, y un bucle interno (controlado por la variable j) para recorrer secuencialmente cada columna de dicha fila.
Regla Estricta para Pasar Matrices a Funciones:
Al modularizar algoritmos que utilicen matrices en C, el pasaje de parámetros se realiza por referencia implícita. Sin embargo, debido al cálculo interno de direccionamiento físico del compilador, es una obligación sintáctica declarar explícitamente el tamaño de la segunda dimensión (las columnas) en el encabezado del módulo.
Sintaxis válida: void procesar(int mat(COLUMNAS))
Si omitís el tamaño de las columnas en los parámetros, el compilador generará un error crítico ya que no podrá calcular cuántos bytes debe saltar en el hardware para avanzar de una fila a la siguiente.
________________________________________
2.	RESOLUCIÓN DE LA ACTIVIDAD A (PÁGINAS 11 Y 12)
Esta sección resuelve por completo el programa planteado en la diapositiva 11, implementando los procedimientos modulares exigidos en la página 12 mediante directivas DEFINE para parametrizar las dimensiones lógicas.
Código fuente de la Actividad A:
#include <stdio.h>
#include <conio.h>
#define FILAS 4
#define COLUMNAS 4
void cargarMatriz(int mat(COLUMNAS));
void mostrarMatriz(int mat(COLUMNAS));
void divisiblesEnCuatro(int mat(COLUMNAS), int contadorPar);
int main() {
int mat(FILAS)(COLUMNAS);
int par = 0;
printf("=== ETAPA DE CARGA MODULAR DE LA MATRIZ ===\n");
cargarMatriz(mat);
printf("\n=== VISUALIZACION DE LA MATRIZ TOTAL ===\n");
mostrarMatriz(mat);
printf("\n=== PROCESAMIENTO DE ELEMENTOS DIVISIBLES POR CUATRO ===\n");
divisiblesEnCuatro(mat, par);
getch();
return 0;
}
void cargarMatriz(int mat(COLUMNAS)) {
int i, j;
for(i = 0; i < FILAS; i++) {
for(j = 0; j < COLUMNAS; j++) {
printf("MATRIZ POSICION (%d)(%d): ", i, j);
scanf("%d", &mat(i)(j));
}
}
}
void mostrarMatriz(int mat(COLUMNAS)) {
int i, j;
for(i = 0; i < FILAS; i++) {
for(j = 0; j < COLUMNAS; j++) {
printf("%d\t", mat(i)(j));
}
printf("\n");
}
}
void divisiblesEnCuatro(int mat(COLUMNAS), int contadorPar) {
int i, j;
int cantidadDivisibles = 0;
for(i = 0; i < FILAS; i++) {
for(j = 0; j < COLUMNAS; j++) {
// Un numero es divisible por 4 si el resto de su division es cero
if(mat(i)(j) % 4 == 0) {
printf("Elemento divisible por 4 detectado en (%d)(%d): %d\n", i, j, mat(i)(j));
cantidadDivisibles++;
}
}
}
printf("Cantidad total de celdas divisibles por cuatro: %d\n", cantidadDivisibles);
}
________________________________________
3.	RESOLUCIÓN DE LA ACTIVIDAD B (PÁGINA 13)
Este programa realiza la transferencia lógica de datos heterogéneos desde una matriz hacia un vector unidimensional aplicando un filtro booleano de paridad, un algoritmo de control de unicidad para evitar elementos duplicados, y un ordenamiento descendente mediante el método de Selección Directa.
Código fuente de la Actividad B:
#include <stdio.h>
#include <conio.h>
#define MAX_F 3
#define MAX_C 3
#define MAX_ARR 9
void cargarMatrizDatos(int mat(MAX_C));
int extraerParesUnicos(int mat(MAX_C), int arr);
void ordenarDescendente(int arr, int tam);
void mostrarArregloPares(int arr, int tam);
int main() {
int matriz(MAX_F)(MAX_C);
int arregloPares(MAX_ARR);
int cantidadElementosReales = 0;
printf("=== CARGA DE MATRIZ DE ENTRADA ===\n");
cargarMatrizDatos(matriz);
cantidadElementosReales = extraerParesUnicos(matriz, arregloPares);
if(cantidadElementosReales > 0) {
printf("\n=== APLICANDO ORDENAMIENTO DE MAYOR A MENOR ===\n");
ordenarDescendente(arregloPares, cantidadElementosReales);
printf("\n=== ELEMENTOS PARES UNICOS ORDENADOS ===\n");
mostrarArregloPares(arregloPares, cantidadElementosReales);
} else {
printf("\nNo se detectaron elementos pares en la matriz original.\n");
}
getch();
return 0;
}
void cargarMatrizDatos(int mat(MAX_C)) {
int i, j;
for(i = 0; i < MAX_F; i++) {
for(j = 0; j < MAX_C; j++) {
printf("Ingrese valor para (%d)(%d): ", i, j);
scanf("%d", &mat(i)(j));
}
}
}
int extraerParesUnicos(int mat(MAX_C), int arr) {
int i, j, k;
int cantPares = 0;
int esRepetido;
for(i = 0; i < MAX_F; i++) {
for(j = 0; j < MAX_C; j++) {
// Validacion de elemento par
if(mat(i)(j) % 2 == 0) {
esRepetido = 0; // Falso
// Algoritmo de busqueda de duplicados dentro del arreglo destino
for(k = 0; k < cantPares; k++) {
if(arr(k) == mat(i)(j)) {
esRepetido = 1; // Verdadero
break;
}
}
// Si el valor par no existe en el vector, se procede a su insercion
if(esRepetido == 0) {
arr(cantPares) = mat(i)(j);
cantPares++;
}
}
}
}
return cantPares; // Retorna el tamaño logico real del vector generado
}
void ordenarDescendente(int arr, int tam) {
int i, j, indiceMaximo, auxiliar;
// Metodo de seleccion directa adaptado para criterio descendente
for(i = 0; i < tam - 1; i++) {
indiceMaximo = i;
for(j = i + 1; j < tam; j++) {
if(arr(j) > arr(indiceMaximo)) {
indiceMaximo = j;
}
}
if(indiceMaximo != i) {
auxiliar = arr(i);
arr(i) = arr(indiceMaximo);
arr(indiceMaximo) = auxiliar;
}
}
}
void mostrarArregloPares(int arr, int tam) {
int i;
for(i = 0; i < tam; i++) {
printf("Indice (%d) -> Valor: %d\n", i, arr(i));
}
}
________________________________________
4.	RESOLUCIÓN DE LA ACTIVIDAD C (PÁGINA 14)
Nota aclaratoria de cátedra para examen: La consigna plantea que dado un arreglo de 10 elementos se carguen en una matriz de 3 filas y 3 columnas. Dado que una matriz de 3x3 posee capacidad estricta para exactamente 9 elementos en el hardware, el algoritmo mapea y transfiere los primeros 9 elementos del vector base hacia la estructura bidimensional, descartando el excedente para evitar un desbordamiento físico.
Matemática de las Diagonales (Para matrices cuadradas de tamaño N):
Diagonal Principal: Se caracteriza porque el índice de la fila es igual al índice de la columna (i == j).
Diagonal Secundaria: Se caracteriza porque la suma de ambos índices es siempre constante e igual al tamaño de la dimensión menos uno (i + j == N - 1).
Código fuente de la Actividad C:
#include <stdio.h>
#include <conio.h>
#define TAM_VECTOR 10
#define N 3
void mapearVectorAMatriz(int arr, int mat(N));
void calcularSumatoriaDiagonales(int mat(N));
void mostrarEstructuras(int arr, int mat(N));
int main() {
// Inicializacion en etapa de definicion del arreglo de 10 elementos
int arregloOrigen(TAM_VECTOR) = {5, 12, 7, 3, 9, 21, 4, 8, 15, 99};
int matrizDestino(N)(N);
printf("=== PROCESAMIENTO GENERAL DE MATRICES CUADRADAS ===\n");
mapearVectorAMatriz(arregloOrigen, matrizDestino);
printf("\n=== CALCULOS DE DIAGONALES MATEMATICAS ===\n");
calcularSumatoriaDiagonales(matrizDestino);
printf("\n=== REPORTE FINAL DE ESTRUCTURAS ===\n");
mostrarEstructuras(arregloOrigen, matrizDestino);
getch();
return 0;
}
void mapearVectorAMatriz(int arr, int mat(N)) {
int i, j;
int contadorLineal = 0;
// Transfiere los primeros 9 elementos correlativos del vector a la matriz
for(i = 0; i < N; i++) {
for(j = 0; j < N; j++) {
mat(i)(j) = arr(contadorLineal);
contadorLineal++;
}
}
printf("Mapeo completado de forma exitosa. Se procesaron %d elementos.\n", contadorLineal);
}
void calcularSumatoriaDiagonales(int mat(N)) {
int i, j;
int sumaPrincipal = 0;
int sumaSecundaria = 0;
for(i = 0; i < N; i++) {
for(j = 0; j < N; j++) {
// Evaluacion de Diagonal Principal
if(i == j) {
sumaPrincipal = sumaPrincipal + mat(i)(j);
}
// Evaluacion de Diagonal Secundaria (para N = 3, i + j debe ser igual a 2)
if(i + j == N - 1) {
sumaSecundaria = sumaSecundaria + mat(i)(j);
}
}
}
printf("Sumatoria de los elementos de la Diagonal Principal: %d\n", sumaPrincipal);
printf("Sumatoria de los elementos de la Diagonal Secundaria: %d\n", sumaSecundaria);
}
void mostrarEstructuras(int arr, int mat(N)) {
int i, j;
printf("Elementos contenidos en el Arreglo de Origen:\n");
for(i = 0; i < TAM_VECTOR; i++) {
printf("%d ", arr(i));
}
printf("\n\nElementos distribuidos en la Matriz Destino de 3x3:\n");
for(i = 0; i < N; i++) {
for(j = 0; j < N; j++) {
printf("%d\t", mat(i)(j));
}
printf("\n");
}
}
________________________________________
ENTRADA Y SALIDA DE DATOS

UNIVERSIDAD TECNOLÓGICA NACIONAL
FACULTAD REGIONAL RESISTENCIA
TÉCNICO UNIVERSITARIO EN PROGRAMACIÓN
MATERIA: PROGRAMACIÓN I - ENTRADA Y SALIDA DE DATOS
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición del Flujo de Entrada y Salida (I/O):
Es el mecanismo esencial que permite la transferencia bidireccional de información entre la unidad central de procesamiento de la computadora y los dispositivos periféricos estándar del sistema, como el teclado (entrada estándar o stdin) y el monitor (salida estándar o stdout).
Clasificación Académica de las Funciones de E/S:
Funciones de Caracteres Individuales:
Involucran las rutinas de bajo nivel getchar y putchar. Están diseñadas exclusivamente para procesar un único byte de información (tipo char) por cada ciclo de ejecución, aislando la entrada y salida de datos del buffer de forma atómica.
Funciones de Cadenas de Caracteres (Strings):
Comprenden las funciones gets y puts. Permiten la manipulación completa de secuencias de texto orientadas a buffers de caracteres de manera directa.
Funciones de Formato Complejo:
Representadas por scanf y printf. Poseen la arquitectura interna más compleja debido a su capacidad de interpretar múltiples tipos de datos simultáneamente (enteros, flotantes, cadenas y caracteres) mediante el uso de formateadores lógicos específicos.
________________________________________
2.	ANÁLISIS DE MECÁNICAS SINTÁCTICAS Y BIBLIOTECAS CRÍTICAS
Directivas de Preprocesamiento Obligatorias:
Para implementar operaciones de entrada y salida es un requisito mandatorio enlazar las cabeceras estándar del compilador:
1.	#include <stdio.h> (Standard Input Output Header): Provee las definiciones nativas y prototipos de printf, scanf, getchar, putchar, gets y puts.
2.	#include <conio.h> (Console Input Output): Requerida comúnmente en la cátedra para pausar la consola de comandos mediante la instrucción getch().
Comportamiento de la Función getchar():
Detiene el flujo del programa esperando que el buffer del teclado reciba un carácter seguido del salto de línea (Enter). Retorna el valor leído y lo asigna de forma directa a una variable de tipo char.
Comportamiento de la Función putchar():
Toma el valor de una variable de tipo char pasada como parámetro y lo imprime de forma inmediata en la posición activa del cursor dentro de la consola, sin agregar saltos de línea automáticos.
Diferencias en el Formateo Numérico con printf():
A diferencia de putchar, la función printf permite estructurar la salida mediante cadenas de control.
Sintaxis avanzada expuesta (Página 9): printf("%3d %7.4f", i, x);
Análisis del formateador:
•	%3d: Indica la impresión de un entero reservando un ancho mínimo de tres espacios en la pantalla.
•	%7.4f: Determina que el número de coma flotante ocupará un ancho total de siete caracteres en la interfaz, destinando exactamente cuatro dígitos fijos para la representación decimal posterior al punto.
________________________________________
3.	PROGRAMA UNIFICADO EN TEXTO PLANO
A continuación se desarrolla una solución estructurada que integra ordenadamente todos los ejemplos funcionales y mecánicas de lectura/escritura expuestas a lo largo de la presentación académica de la FRRE.
#include <stdio.h>
#include <conio.h>
int main() {
char caracterIndividual;
char bufferNombre(10);
char caracterIntermedio;
int valorEntero;
float valorFlotante;
// Bloque 1: Demostracion de funciones individuales (getchar y putchar)
printf("=== MODULO 1: MANEJO DE CARACTERES INDIVIDUALES ===\n");
printf("Ingrese un caracter por teclado: ");
caracterIndividual = getchar();
// Limpieza de buffer necesaria para eliminar el salto de linea remanente de la lectura anterior
while(getchar() != '\n');
printf("El caracter ingresado es: ");
putchar(caracterIndividual);
printf("\n\n");
// Bloque 2: Demostracion de manejo de cadenas de texto (gets y puts)
printf("=== MODULO 2: MANEJO DE CADENAS DE CARACTERES ===\n");
printf("Ingrese su nombre por teclado: ");
gets(bufferNombre);
printf("El nombre ingresado es: ");
puts(bufferNombre);
printf("El nombre ingresado formateado con printf es %s:\n\n", bufferNombre);
// Bloque 3: Entrada mixta con formato (scanf con delimitadores de tipo)
printf("=== MODULO 3: ENTRADA Y SALIDA MIXTA FORMATEADA ===\n");
printf("Ingrese un caracter aislado: ");
caracterIntermedio = getchar();
printf("Ingrese un valor flotante decimal: ");
scanf("%f", &valorFlotante);
printf("Ingrese un valor entero: ");
scanf("%d", &valorEntero);
printf("\nMostrar los valores ingresados de forma tabulada:\n");
printf("Salida de caracter individual: ");
putchar(caracterIntermedio);
printf("\n");
printf("Salida numerica tabulada (Ancho de 3 para entero, 7 con 4 decimales para flotante):\n");
printf("%3d %7.4f\n", valorEntero, valorFlotante);
getch();
return 0;
}


ESTRUCTURA DE DATOS
UNIVERSIDAD TECNOLÓGICA NACIONAL
CÁTEDRA DE PROGRAMACIÓN I
UNIDAD 2: CLASIFICACIÓN GENERAL DE LAS ESTRUCTURAS DE DATOS
1.	FUNDAMENTOS TEÓRICOS DE NIVEL UNIVERSITARIO
Definición Conceptual de Estructura de Datos:
Una estructura de datos es una metodología técnica para organizar, disponer y almacenar datos en la memoria de una computadora, con el objetivo de permitir un acceso y una manipulación lógica eficiente. La disposición de la estructura determina que sea óptima para la resolución de ciertas operaciones y de baja eficiencia para otras.
Criterio de Clasificación por la Administración de Memoria:
Estructuras Estáticas:
Son aquellas estructuras de datos en las que el tamaño absoluto ocupado en la memoria RAM se define estrictamente antes de que el programa inicie su fase de ejecución (en tiempo de compilación). Dicha dimensión física queda fijada en el hardware y resulta imposible modificar su capacidad o expandir sus límites durante la ejecución del programa.
Estructuras Dinámicas:
Son aquellas estructuras de datos en las que el tamaño de la memoria utilizada puede modificarse y gestionarse de forma flexible y dinámica durante el tiempo de ejecución del programa. Permiten solicitar o liberar espacio del sistema de acuerdo con los requerimientos instantáneos del algoritmo.
________________________________________
2.	DESGLOSE DEL MAPA DE CLASIFICACIÓN EXIGIDO EN EXAMEN
A partir del esquema formal expuesto en el material de la cátedra (Página 4), las estructuras se subclasifican taxonómicamente bajo los siguientes grupos lógicos:
Subgrupo de Estructuras Estáticas Primitivas:
Representan las unidades atómicas y esenciales de almacenamiento provistas por el compilador:
•	Entero (int): Almacena valores numéricos sin componentes decimales.
•	Real (float / double): Almacena valores aritméticos de coma flotante.
•	Booleano (bool): Representa estados de verdad o condiciones lógicas.
•	Carácter (char): Almacena un único byte que representa un símbolo de la tabla ASCII.
Subgrupo de Estructuras Estáticas Compuestas:
Agrupaciones organizadas basadas en los tipos primitivos con límites estáticos fijos en RAM:
•	Arreglos: Colecciones finitas, homogéneas y ordenadas de elementos situados en celdas contiguas.
•	Strings: Cadenas ordenadas de caracteres de longitud finita que concluyen con un elemento nulo.
•	Archivos o Ficheros: Colecciones ordenadas de datos estructurados guardados en dispositivos no volátiles.
•	Registros (structs): Agrupaciones de campos lógicamente relacionados que manejan tipos heterogéneos.
Subgrupo de Estructuras Dinámicas Lineales:
Estructuras donde los componentes ocupan lugares sucesivos y adyacentes, vinculados de manera lineal de forma que cada elemento posee un único sucesor lógico y un único predecesor en el flujo:
•	Listas enlazadas: Secuencias de nodos enlazados donde cada elemento contiene el dato y el puntero de dirección del nodo siguiente.
•	Pilas (LIFO): Estructuras de acceso restringido bajo la regla Último en entrar, Primero en salir, controladas por operaciones de apilar (push) y desapilar (pop).
•	Colas (FIFO): Estructuras de acceso restringido bajo la regla Primero en entrar, Primero en salir, controladas por operaciones de encolar y desencolar.
Subgrupo de Estructuras Dinámicas No Lineales (Multienlazadas):
Estructuras de ramificación compleja donde cada elemento puede estar interconectado con múltiples componentes, rompiendo la secuencialidad lineal:
•	Árboles: Estructuras que representan datos organizados en relaciones jerárquicas, donde cada nodo tiene un único antecesor y puede tener varios sucesores. Se dividen en árboles generales y árboles binarios (máximo dos sucesores).
•	Grafos: Estructuras matemáticas abstractas formadas por un conjunto de puntos (denominados nodos o vértices) interconectados de forma libre por un conjunto de líneas (denominadas aristas o arcos).
________________________________________
3.	COMPORTAMIENTO HARDWARE: MEMORIA VOLÁTIL VS. NO VOLÁTIL
Un concepto analítico fuerte en las evaluaciones teóricas de la UTN radica en clasificar la persistencia física de los datos manipulados por el software:
El Buffer de Memoria RAM (Memoria Volátil):
Las variables primitivas, los arreglos, las estructuras y los nodos dinámicos residen temporalmente dentro de la memoria RAM del ordenador. Tienen un ciclo de vida estrictamente ligado al hilo de ejecución del proceso. No sobreviven a la finalización del programa y son eliminados por completo al interrumpirse el suministro eléctrico del computador.
El Almacenamiento Permanente (Memoria No Volátil):
Los archivos o ficheros representan la única estructura estática compuesta diseñada para almacenar los datos de manera permanente dentro de dispositivos físicos secundarios (discos magnéticos o de estado sólido). Esto garantiza la persistencia absoluta de la información; los datos continúan existiendo de manera consistente y pueden ser accedidos en el futuro, incluso después de que el programa creador haya concluido o la máquina sea apagada.
________________________________________
EXPLICACIONES
#busqueda binaria con eliminacion de elemento
#include <stdio.h>

int main()
{
	int lista[9]= {0, 4,5 ,7, 32, 40, 77, 100,123};
	int i,inicio,final,medio,num; 
	
	for(i = 0; i < 9; i++)
     		printf("Digito %d:%d\n",i,lista[i]);
	/*busqueda binaria*/
	printf("Ingresar el numero a buscar:\n");
	scanf("%d",&num);
	inicio = 0;
	final = 9 - 1; /*n-1, n es la cantidad de elementos del arreglo*/
	
	medio=0;
	while ((inicio <= final) && num!=lista[medio])
	{
		medio = (inicio + final) / 2;
		if (num > lista[medio])
			inicio = medio + 1;
		else
			final = medio - 1;
	}
	
	if (num == lista[medio])
	   {
		printf(" %d encontrado en la posicion %d\n",num,medio);
        final=9;
		
		while(medio < final)
		{
			lista[medio]=lista[medio+1];
	        medio++;	
		}
		
		   
	   }
	
	else
		printf(" %d no esta en el arreglo\n",num);
	
return 0;
}
PASO A PASO MECÁNICO DEL CÓDIGO DE BÚSQUEDA Y ELIMINACIÓN
1. DECLARACIÓN (Establecer las herramientas)
c
int lista[9]= {0, 4, 5, 7, 32, 40, 77, 100, 123};
int i, inicio, final, medio, num; 
int dimensionActual = 9;
Usa el código con precaución.
•	La lógica: Primero tenés que crear las variables. Lo que declarás acá determina qué podés usar después.
•	El arreglo (lista[9]): Reserva 9 celdas consecutivas en la memoria RAM y las llena con esos números ordenados.
•	Variables de control (inicio, final, medio): Son simples enteros que vas a usar como "punteros de índice" para moverte por las celdas del arreglo en la búsqueda.
•	num: La caja vacía donde vas a guardar el número que el usuario quiere buscar.
•	dimensionActual: Un contador que empieza en 9. Lo usás al final para restarle 1 cuando borres el elemento, avisándole al programa que la lista ahora es más corta.
2. MOSTRAR EL ARREGLO INICIAL (Regla de Lectura)
c
for(i = 0; i < dimensionActual; i++)
    printf("Digito %d:%d\n", i, lista[i]);
Usa el código con precaución.
•	La lógica: Usás la variable i como un índice que arranca en 0 y suma de a uno (i++) hasta llegar a 8. En cada vuelta, lista[i] entra a la celda actual y te muestra el número en el monitor.
3. PREPARAR LA BÚSQUEDA BINARIA (Setear los extremos)
c
printf("Ingresar el numero a buscar:\n");
scanf("%d", &num);
inicio = 0;
final = dimensionActual - 1;
Usa el código con precaución.
•	La lógica: Guardás el número a buscar en num usando el &. Para poder aplicar la búsqueda binaria (partir a la mitad), necesitás definir las fronteras de tu lista: la variable inicio apunta a la primera celda (0) y la variable final apunta a la última celda válida (8, que es 9 - 1).
4. EL BUCLE DE BÚSQUEDA BINARIA (Partir a la mitad)
c
medio = (inicio + final) / 2;
while ((inicio <= final) && (num != lista[medio]))
{
    if (num > lista[medio])
        inicio = medio + 1;
    else
        final = medio - 1;
        
    medio = (inicio + final) / 2;
}
Usa el código con precaución.
•	La lógica: El bucle while se repite mientras los extremos no se crucen (inicio <= final) y mientras no hayas encontrado el número (num != lista[medio]).
•	Condición 1 (num > lista[medio]): Si el número que buscás es más grande que el que está parado en el medio, la mitad izquierda ya no te sirve. Entonces, la variable inicio se mueve a la derecha (medio + 1) para acortar el rango.
•	Condición 2 (else): Si el número buscado es más chico, la mitad derecha no sirve. Entonces, la variable final se mueve a la izquierda (medio - 1).
•	Recálculo: Al final de la vuelta, volvés a calcular el medio con los nuevos extremos para volver a partir la lista a la mitad en la siguiente vuelta.
5. EL BLOQUE DE ELIMINACIÓN (Pisar el elemento)
c
if (num == lista[medio])
{
    while (medio < dimensionActual - 1)
    {
        lista[medio] = lista[medio + 1];
        medio++;    
    }
    dimensionActual--;
}
Usa el código con precaución.
•	La lógica: Si al salir del while anterior se cumple que num == lista[medio], significa que lo encontraste y la variable medio tiene guardada la posición exacta del elemento que querés borrar.
•	El desplazamiento (lista[medio] = lista[medio + 1]): Este es el paso clave. En lugar de borrar, lo que hacés es sobrescribir. La celda actual (medio) agarra y copia el valor de la celda que tiene a su derecha (medio + 1), pisando el número viejo.
•	El avance (medio++): Hacés que la variable medio avance una posición para que en la siguiente vuelta el elemento de la celda de más a la derecha pise al de su izquierda. Esto se repite en cadena como un dominó.
•	El límite (dimensionActual - 1): El bucle frena antes de llegar a la última celda. Esto evita el error de tu código original, impidiendo que el programa intente leer una celda 9 que no existe en el arreglo.
•	Achicar la lista (dimensionActual--): Le restás 1 al tamaño de la lista. Así, en el próximo for, el programa solo va a mostrar hasta la posición 7, dejando afuera el último casillero que quedó duplicado al final del desplazamiento.
 
