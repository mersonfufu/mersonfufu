#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
	char nome[50];
	float salario;
} FUNCIONARIO;

int main(){
	int numero;
	FILE *arq = NULL;
	FUNCIONARIO *f = NULL;
	f = malloc(3 * sizeof(FUNCIONARIO));
	f[0].codigo = 1000;
	strcpy(f[0].nome, "Cadeu Ponteiro");
	f[0].salario = 3000;
	f[1].codigo = 2000;
	strcpy(f[1].nome, "Hemerson Infeliz");
	f[1].salario = 1000;
	f[2].codigo = 3000;
	strcpy(f[2].nome, "Adriano Suicida");
	f[2].salario = 1500;
	arq = fopen("dados.dat", "wb");
	if(arq == NULL){
		printf("Arquivo nao pode ser criado");
		return 0;
	}
	fwrite(&numero, sizeof(FUNCIONARIO), 3, arq);
	fread(&f, sizeof(FUNCIONARIO), 1, arq);
	while(!feof(arq)){
		printf("Codigo:%d\n", f.codigo);
		printf("Nome:%s\n", f.nome);
		printf("Salario:%f\n", f.salario);
		fread(&f, sizeof(FUNCIONARIO), 1, arq);
	}
	printf("\n");
	fclose(arq);
	remove("arquivo.teste.txt");
	arq = NULL;
	free(f);
	f = NULL;
	return 0;
}