#include <stdio.h>
#include <math.h>

/*elabore un algoritmo que determine el mayor de 4 valores*/

int main() {
	int num, mayor, i;

    for (i = 1; i<=4; i++){
        printf("Ingrese los valores: ", i); //i es para indicar en la vuelta que estoy
        scanf("%d", &num);
        if(i == 1){
            mayor = num;
        } else if (num > mayor){
            mayor = num;
        }
    }
    printf("El mayor de los 4 valores es: %d\n", mayor);

    return 0;
}