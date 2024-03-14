#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[48];
	int idade;
	double salario;
} FUNCIONARIO;

int main(){
	FUNCIONARIO *ptr = NULL;
	ptr = malloc(sizeof(FUNCIONARIO));
	strcpy(ptr->nome, "algo");
	ptr->idade = 200;
	ptr->salario = 503, 8;
	fprintf(stdout, "%s%d%f\n",
		ptr->nome,
		ptr->idade,
		ptr->salario
	);
	free(ptr);
	ptr = NULL;
	return 0;
}