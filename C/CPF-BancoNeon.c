 /**
  * mersonfufu@gmail.com
  * 7:34 PM 3/29/2020
  *
  * Possibilidades:
  * 10, 11, 12
  * 21, 22, 23
  * 32, 33, 34
  * 43, 44, 45
  * 54, 55, 56
  * 65, 66, 67
  * 76, 77, 78
  * 87, 88, 99
  */

#include <stdio.h>

int main(){
	int aux, meio = 0, fim, i, soma;
	int cpf[11] = {0};

	FILE *arquivo = fopen("CPF-BancoNeon.txt", "w");
	if(!arquivo)
		return 1;
	
	scanf("%d", &aux);
	scanf("%d", &fim);
	
	//desmembrar 3 primeiros
	for(i = 2 ; i >= 0 ; i--){
		cpf[i] = aux % 10;
		aux /= 10;
	}
	
	while(meio <= 999999){
		aux = meio;
		for(i = 8 ; i >= 3 ; i--){
			cpf[i] = aux % 10;
			aux /= 10;
		}
		
		//digito-10
		soma = 0;
		for(i = 0 ; i < 9 ; i++)
			soma += cpf[i] * (10 - i);
		soma % 11 == 0 || soma % 11 == 1 ? (cpf[9] = 0) : (cpf[9] = 11 - soma % 11);
		
		//digito-11
		soma = 0;
		for(i = 0 ; i < 10 ; i++)
			soma += cpf[i] * (11 - i);
		soma % 11 == 0 || soma % 11 == 1 ? (cpf[10] = 0) : (cpf[10] = 11 - soma % 11);
		
		//saida
		if (cpf[9] * 10 + cpf[10] == fim){
			//regiao fiscal
			fprintf(arquivo, "[");
			switch(cpf[8]){
				case 0:
					fprintf(arquivo, "RS");
					break;
				case 1:
					fprintf(arquivo, "DF, GO, MS, MT ou TO");
					break;
				case 2:
					fprintf(arquivo, "AC, AM, AP, PA, RO ou RR");
					break;
				case 3:
					fprintf(arquivo, "CE, MA ou PI");
					break;
				case 4:
					fprintf(arquivo, "AL, PB, PE ou RN");
					break;
				case 5:
					fprintf(arquivo, "BA ou SE");
					break;
				case 6:
					fprintf(arquivo, "MG");
					break;
				case 7:
					fprintf(arquivo, "ES ou RJ");
					break;
				case 8:
					fprintf(arquivo, "SP");
					break;
				case 9:
					fprintf(arquivo, "PA ou SC");
					break;
			}
			fprintf(arquivo, "] ");
			//cpf valido
			for(i = 0; i <= 10 ; i++){
				fprintf(arquivo, "%d", cpf[i]);
				if(i == 2 || i == 5)
					fprintf(arquivo, ".");
				if(i == 8)
					fprintf(arquivo, "-");
			}
			fprintf(arquivo, "\n");
		}
		//interacao
		meio++;
	}
	
	fclose(arquivo);
	arquivo = NULL;
	return 0;
}