#include <stdio.h>

/*En un hospital existen 3 áreas: Urgencias, Pediatría y Traumatología. 
El presupuesto anual del hospital se reparte de la siguiente manera: 
	Área  		Presupuesto 
	Urgencias  		37%
	Pediatría  		42% 
	Traumatología 	21% 
Obtener la cantidad de dinero que recibirá cada área para cualquier monto presupuestal.*/ 

int main() {
	float presupuesto, urg, ped, trau;
	inicio:
	printf("Ingrese el presupuesto anual: ");
	scanf("%f", &presupuesto);
	if(presupuesto>0){
		urg = presupuesto*0.37;
		ped = presupuesto*0.42;
		trau = presupuesto*0.21;
		printf("--------------------------------\n");
		printf("|%-15s | %-20s\n|", "AREA","PRESUPUESTO");
		printf("%-15s | $%19.2f\n|", "Urgencias",urg);
		printf("%-15s | $%19.2f\n|", "Pediatria",ped);
		printf("%-15s | $%19.2f|", "Traumatologia",trau);
	}else{
		printf("Error. Debe agregar un valor mayor a 0\n");
		goto inicio;
	}
	
	return 0;
}

