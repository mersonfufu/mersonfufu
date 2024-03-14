#define alocar_vetor(quantidade, tamanho) calloc(quantidade, tamanho)
#define testar_alocacao(vetor) if(!vetor){printf("Erro de alocassaum\n");return 1;}

#include <stdio.h>
#include <stdlib.h>

int busca_substring(char *, char *);

int main(){
    char buffer[31], cont, i;
    char *stringptr = NULL, *substringptr = NULL;

    printf("Entre sentenca... ");
    scanf("%[^\n]s", buffer);
    cont = sprintf(buffer, "%s", buffer);
    stringptr = (char *) alocar_vetor(cont, sizeof(char));
    testar_alocacao(stringptr);
    for(i = 0; i < cont ; i++)
        stringptr[i] = buffer[i];
    
    printf("Entre subsentenca... ");
    scanf("\n");
    scanf("%[^\n]s", buffer);
    cont = sprintf(buffer, "%s", buffer);
    substringptr = (char *) alocar_vetor(cont, sizeof(char));
    testar_alocacao(substringptr);
    for(i = 0; i < cont ; i++)
        substringptr[i] = buffer[i];

    cont = busca_substring(stringptr, substringptr);

    cont == -1 ? printf("-1") : printf("A substring \"%s\" aparece %d vez", substringptr, cont);
    cont > 1 ? printf("es\n") : printf("\n");

    free(stringptr);
    free(substringptr);
    stringptr = substringptr = NULL;

    return 0;
}

/**
 * busca_substring
 * 
 * procura uma substring numa string dada
 *
 * @param *stringptr vetor de caracteres a ser pesquisado
 * @param *substringptr vetor de caracteres a pesquisar
 * @return o numero de vezes que substringptr aparece em stringptr
 *
 */
int busca_substring(char *stringptr, char *substringptr){
    int i, j, total = -1;
    for(i = 0 ; stringptr[i] != '\0' ; i++){
        j = 0;
        if(stringptr[i] != substringptr[j])
            continue;
        else {
            for(j ; substringptr[j] != '\0' ; j++)
                if(substringptr[j] != stringptr[i + j])
                    continue;
                else if(substringptr[j + 1] == '\0')
                    if(total == -1)
                        total = 1;
                    else
                        total++;
        }
    }
    return total;
}