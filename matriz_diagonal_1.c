#include <stdio.h>

int main() {
	int i, j;
	int n=3;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i){
				printf("1");
			}else{
				printf("0");
			}
		}
		printf("\n");
	}
	
	
	
	return 0;
}

