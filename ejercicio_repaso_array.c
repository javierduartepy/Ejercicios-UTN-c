#ejercicio_repaso_array
#include <stdio.h>

int main() 

{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
	int i,acum,pos,bus;
	float prom;
	i=0;
	acum=0;
	
	for (i=0;i<10;i++)
		printf("%i -",a[i]);
		
	for (i=0;i<10;i++)
		acum=acum+a[i];
	
	
	printf("\n\nTotal sumatoria arreglo:%i",acum);
	
	prom=acum/10;
	
	printf("\n\n Promedio:%f",prom);
	
	printf("\n\nIgrese posici�n a buscar");
	scanf("%i",&pos);
		
	if (pos < 0 || pos >9) printf("\n Posici�n fuera de rango");
	else printf("\n Valor %i en la posici�n % i",a[pos],pos);
	
	printf("\n\nIngrese elemento a buscar");
	scanf("%i",&bus);
	/*busqueda para un arreglo sin elementos repetidos*/
	i=0;
	
	while (i<10 &&  a[i]!=bus)
		i++;
	
	if (i==10) printf ("\n Elemento no encontrado");
	else printf ("\n Elemento  encontrado");
   

return 0;


} 


