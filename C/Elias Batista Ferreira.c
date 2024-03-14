#define d_max_letras 20
#include <stdio.h>

void imprimir_cartao(char *vetor, char extra[3]){
	printf("%s", vetor);
	printf("%s", extra);
}

int main(){
	int dd, mm;
	char cabecalho[5][d_max_letras] = {"Obrigado pelo", "Tenha um", "Tenha uma", "Parabens pelo seu", "Parabens pela sua"};
	char adjetivos[5][d_max_letras] = {"feliz", "otimo", "horrivel", "louco", "triste"};
	char  ocasioes[5][d_max_letras] = {"aniversario", "dia", "conquista", "gravidez", "Natal e ano novo"};
	
	printf("Digite o mes atual [1~12]... ");
	scanf("%d", &mm);
	printf("Digite o dia atual [1~31]... ");
	scanf("%d", &dd);
	printf("\n");
	
	if(mm == 3 & dd == 28){
		imprimir_cartao(cabecalho[3], " ");
		imprimir_cartao(ocasioes[0], "!");
		printf("\n");
	}
	
	imprimir_cartao(cabecalho[1], " ");
	imprimir_cartao(adjetivos[1], " ");
	imprimir_cartao(ocasioes[1], " :)");
	printf("\n");
	
	return 0;
}