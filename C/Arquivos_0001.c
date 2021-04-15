/**
 * @file main.c
 * @brief Este programa abre um arquivo "teste.txt" no modo de escrita e escreve números lidos do teclado no arquivo.
 * 
 * O programa verifica se o arquivo "teste.txt" pode ser aberto. Se o arquivo não puder ser aberto,
 * é exibida a mensagem "Arquivo não encontrado" na saída padrão. Caso contrário, o programa lê números do teclado
 * até que o final de arquivo (EOF) seja alcançado e escreve cada número em uma nova linha no arquivo.
 * Finalmente, o arquivo é fechado.
 */
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
	}
	fclose(arq);
	arq = NULL;
	return 0;
}