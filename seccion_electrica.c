#include <stdio.h>
#include <math.h>

/*El valor de la seccion (s) de un conductor se determina en 
funcion de la corriente electrica (l) y la conducividad (c) del
material (tenga en cuenta que c=l/s). Además si la seccion obtenida
es menor a 1 se le incrementa un 50% por razones de seguridad. Calcule 
la seccion*/

int main() {

    float s, l, c, incremento;

    printf("Ingrese el valor de la corriente electrica: ");
    scanf("%f", &l);
    do{
        printf("Ingrese el valor de la conductividad: ");
        scanf("%f", &c);
        if(c==0){
            printf("Error. La conductividad debe ser distinto a cero\n");
        }
    } while(c==0);
    s = l/c;
    if(s>=1){
        printf("el valor de la seccion es: %.3f\n", s);
    } else{
        incremento = s * 1.50;
        printf("el valor de la seccion incrementrada es: %.3f\n", incremento);
    }
    return 0;
}