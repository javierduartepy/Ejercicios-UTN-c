#estructura1
#include <stdio.h>

int main()
{
	struct estructura_amigo
	{
		char nombre[30];
		char apellido[40];  
		char telefono[10]; 
		int edad;
	};	
		struct estructura_amigo amigo;	/* Declaramos la variable amigo con esa estructura */
		
		
			
			printf( "Escribe el nombre del amigo: " );  
			scanf( "%s", &amigo.nombre );
			printf( "Escribe el apellido del amigo: " ); 
			scanf( "%s", &amigo.apellido );
			printf( "Escribe el n�mero de tel�fono del amigo: " );  
			scanf( "%s", &amigo.telefono );
			printf( "Mi amigo %s %s tiene el n�mero: %s.\n", amigo.nombre, amigo.apellido, amigo.telefono );
			
	
	
	return 0;
}

