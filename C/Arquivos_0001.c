#include <stdio.h>

int main(){
	FILE *arq;
	arq = fopen("teste.txt", "w");
	if(arq == NULL){
		fprintf(stdout, "Arquivo nao encontrado\n");
		return 0;
	} else {
		int numero;
		while(fscanf(stdin, "%d", &numero) != EOF)
			fprintf(arq, "Numero:%d\n", numero);
		//fprintf(arq,"Arquivo encontrado\n");
	}
	fclose(arq);
	arq = NULL;
	return 0;
}