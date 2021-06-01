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

void progresso(int numero){
	switch(numero){
		case  10000000:
		case  15000000:
		case  20000000:
		case  25000000:
		case  30000000:
		case  35000000:
		case  40000000:
		case  45000000:
		case  50000000:
		case  55000000:
		case  60000000:
		case  65000000:
		case  70000000:
		case  75000000:
		case  80000000:
		case  85000000:
		case  90000000:
		case  95000000:
		case 100000000:
		case 150000000:
		case 200000000:
		case 250000000:
		case 300000000:
		case 350000000:
		case 400000000:
		case 450000000:
		case 500000000:
		case 550000000:
		case 600000000:
		case 650000000:
		case 700000000:
		case 750000000:
		case 800000000:
		case 850000000:
		case 900000000:
		case 950000000:
		case 999999999:
			printf("Testando %d milhoes...\n", numero / 1000000);
	}
}

int main(){
	int aux, numero = 1, i, soma;
	int cpf[11] = {0}, somas[99] = {0};
	
	FILE *arquivo = fopen("CPF-Somas.txt", "w");
	if(!arquivo)
		return 1;
	
	while(numero <= 999999999){
		progresso(numero);
		aux = numero;
		for(i = 8 ; i >= 0 ; i--){
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
		
		//somas
		soma = 0;
		for(i = 0 ; i <= 10 ; i++)
			soma += cpf[i];
		somas[soma] = 1;
		
		numero++;
	}
	
	for(i = 0 ; i <= 99 ; i++)
		somas[i] == 1 ? fprintf(arquivo, "Soma = %d\n", i) : 0;
	
	fclose(arquivo);
	arquivo = NULL;
	return 0;
}