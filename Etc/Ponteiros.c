#include <stdio.h>

int main(){
	int var = 8;
	int *pont = NULL;
	pont = &var;
	*pont = 4;
	printf("%p\n", pont);
	printf("%d\n", *pont);
	free(pont);
	pont = NULL;
	return 0;
}