#include <stdio.h> 
#include <conio.h> 

unsigned long long int factorial(int n);
long int resp;
	
int main (){ 
	int valor; 
	long int result; 
	printf("\n Ingrese numero:"); 
	scanf("%d",&valor); 
	if (valor < 0) {
		printf("Error");}
	else { 
		result=factorial(valor); 
		printf("\n El factorial de %d es %llu",valor,result); } 
getch(); 
return 0;
}
	
unsigned long long int factorial(int n){
	if(n==1 || n==0){ 
	return 1;
	}
	else{ 
	resp = n * factorial(n-1);
	return (resp);
	}
}
	
