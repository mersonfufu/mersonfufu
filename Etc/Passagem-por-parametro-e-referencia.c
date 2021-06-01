#include <stdio.h>

void troca_numeros(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	troca_numeros(&a, &b);
	printf("%d%d", a, b);
	return 0;
}