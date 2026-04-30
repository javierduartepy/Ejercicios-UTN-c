#include <stdio.h>
#include <math.h>

/*La nota final en una escuela se obtiene en funcion de 3 notas. La nota
final del primer examen, la nota del segundo examen y una nota de concepto
del profesor. La nota del primer examen se pondera como 30% de la nota
final, la del segundo examen como el 50% y la de concepto como el 20% 
de la nota final. Elabore un algortimo que, en base a esas tres notas
, determine si el alumno aprobo (nota >= 6)*/

int main() {
    float nota1, nota2, nota3, nota_alumno, suma_examen, suma_alumno;
    float nota1_max, nota2_max, nota3_max, nota_total, nota;
    do{
        printf("Ingrese la nota del primer examen y la nota que obtuvo el alumno: \n");
        scanf("%f %f", &nota1_max, &nota1);
        printf("Ingrese la nota del segundo examen y la nota que obtuvo el alumno: \n");
        scanf("%f %f", &nota2_max, &nota2);
        printf("Ingrese la nota del concepto y la nota que obtuvo el alumno: \n");
        scanf("%f %f", &nota3_max, &nota3);
        if(nota1<0 || nota2<0 || nota3<0 || nota1_max<0 || nota2_max<0 || nota3_max<0){
            printf("Error. Las notas deben ser mayores a cero\n");
        }
    } while(nota1<0 || nota2<0 || nota3<0 || nota1_max<0 || nota2_max<0 || nota3_max<0);
    suma_examen = nota1_max+nota2_max+nota3_max;
    suma_alumno = nota1+nota2+nota3;
    nota_alumno=(nota1*0.30)+(nota2*0.50)+(nota3*0.20);
    nota_total=(nota1_max*0.30)+(nota2_max*0.50)+(nota3_max*0.20);
    nota=(nota_alumno/nota_total)*10;

    printf("la nota es : %.f\n", nota); 
    if(nota>=6){
        printf("El alumno ha aprobado\n");
    } else{
        printf("El alumno ha desaprobado\n");
    }
    printf("\n                  RESUMEN DE CALIFICACIONES                  \n");
    printf("=============================================================\n");
    printf("|%-17s | %-21s | %-14s |\n", "CONCEPTO","NOTA TOTAL DEL EXAMEN","NOTA OBTENIDA");
    printf("|-----------------------------------------------------------|\n");
    printf("|%-17s | %21f | %14f |\n","PRIMER EXAMEN",nota1_max,nota1);
    printf("|%-17s | %21f | %14f |\n","SEGUNDO EXAMEN", nota2_max, nota2);
    printf("|%-17s | %21f | %14f |\n","TERCER EXAMEN",nota3_max, nota3);
    printf("|-----------------------------------------------------------|\n");
    printf("|%-17s | %21f | %14f |\n","PUNTAJE FINAL", suma_examen, suma_alumno);
    printf("|-----------------------------------------------------------|\n");
    printf("|%17s   %21f | %14f |\n","LA NOTA OBTENIDA ES DE:", nota);
    printf("------------------------------------------------------------|\n");


    return 0;
}