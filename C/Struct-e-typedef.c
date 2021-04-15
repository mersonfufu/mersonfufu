#include <stdio.h>
#include <string.h>

int main(){
	//struct
	struct DATA {
		int dia;
		int mes;
		int ano;
		char local[13];
	};
	struct DATA hoje;
	//typedef
	typedef struct {
		int dia;
		int mes;
		int ano;
		char local[13];
	} FERIADO;
	FERIADO OnzeNove;
	//struct
	hoje.dia = 9;
	hoje.mes = 11;
	hoje.ano = 2017;
	strcpy(hoje.local, "goiania");
	//typedef
	OnzeNove.dia = 11;
	OnzeNove.mes = 9;
	OnzeNove.ano = 2001;
	strcpy(OnzeNove.local, "goiania");
	//struct
	printf("%s,%d/%d/%d\n",
		hoje.local,
		hoje.dia,
		hoje.mes,
		hoje.ano
	);
	//typedef
	printf("%s,%d/%d/%d\n",
		OnzeNove.local,
		OnzeNove.dia,
		OnzeNove.mes,
		OnzeNove.ano
	);
	return 0;
}