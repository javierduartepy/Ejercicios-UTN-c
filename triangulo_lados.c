#include <stdio.h>
#include <math.h>

/* Elaborar un algoritmo para determinar el tipo de triangulo dado
el tamaño de sus lados*/

int main() {
	float a,b,c;

    printf("Ingrese un valor para a: ");
    scanf("%f", &a);
    printf("Ingrese un valor para b: ");
    scanf("%f", &b);
    printf("Ingrese un valor para c: ");
    scanf("%f", &c);

    if(a != b){
        if(b == c){
            printf("Es un triangulo isosceles");
        } else {
            if (a == sqrt((b*b)+(c*c)) || b == sqrt((a*a)+(c*c)) || c == sqrt((a*a)+(b*b))){
                printf("Es un triangulo escaleno-rectangulo");
            }else{
                printf("Es un triangulo escaleno");
            }            
        }
    }else{
        printf("Es un triangulo equilatero");
    }
    return 0;
}