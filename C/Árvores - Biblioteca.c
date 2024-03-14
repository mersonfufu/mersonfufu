 /**
  * mersonfufu@gmail.com
  *
  * Basic (and not-so-basic) functions for tree operations
  *
  * Here's a translation of that language from
  * an underdeveloped country 2 help you read
  *
  * Functions:
  * alocarNoh                   = alloc a new node
  * alturaNoh                   = counts the height of the tree
  * buscarNoh                   = search for a value
  * imprimirArvoreEmOrdem       = print inorder
  * imprimirArvorePosOrdem      = print postorder
  * imprimirArvorePreOrdem      = print preorder
  * imprimirArvoreFormatada     = embellished print
  * imprimirArvoreNivelada      = print by levels
  * imprimirArvoreComParenteses = print with parenthesis
  * inserirNoh                  = insert a new node
  * inserirNohArvoreBalanceada  = insert a new balanced node
  * profundidadeNoh             = depth of the node
  * quantidadeNohs              = count nodes
  * quickSort                   = sorting algorithm. the best in my humble opinion
  * removerArvore               = delete entire tree
  * removerNoh                  = delete a single node
  * somaFolhas                  = sum the leaf nodes
  * somaInterna                 = sum the branch nodes
  *
  * Some words:
  * esquerda = left
  * direita  = right
  * arvore   = tree
  * raiz     = root
  * valor    = value
  * inicio   = start
  * fim      = end
  * 
  */

/**
 * @file arvore.h
 * @brief Este arquivo contém as declarações das funções de operações em árvores binárias.
 *
 */
typedef struct no stNo;
stNo * alocarNoh(int);
int alturaNoh(stNo *);
void buscarNoh(stNo *, int);
void imprimirArvoreEmOrdem(stNo *);
void imprimirArvorePosOrdem(stNo *);
void imprimirArvorePreOrdem(stNo *);
void imprimirArvoreFormatada(stNo *, int);
void imprimirArvoreNivelada(stNo *, int);
void imprimirArvoreComParenteses(stNo *);
stNo * inserirNoh(stNo *, stNo *);
stNo * inserirNohArvoreBalanceada(stNo *, int *, int, int);
int profundidadeNoh(stNo *, int, int);
int quantidadeNohs(stNo *);
void quickSort(int *, int, int);
stNo * removerArvore(stNo *);
stNo * removerNoh(stNo *, int);
int somaFolhas(stNo *);
int somaInterna(stNo *);

/**
 * @file arvore.c
 * @brief Código para operações em uma árvore binária
 * 
 * Este arquivo contém as implementações de funções para criar, buscar, imprimir
 * e realizar outras operações em uma árvore binária.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura de um nó da árvore
 * 
 * A estrutura "no" representa um nó da árvore binária. Ele contém dois ponteiros
 * para os filhos esquerdo e direito, além do valor armazenado neste nó.
 */
struct no {
    struct no *esquerda, *direita;
    int valor;
};

/**
 * @def criar_arvore(valor)
 * @brief Macro para criar uma árvore
 * 
 * Este macro define uma forma conveniente de criar uma árvore binária, usando
 * a função "alocarNoh".
 */
#define criar_arvore(valor) alocarNoh(valor)

/**
 * @brief Aloca um nó para a árvore
 * 
 * A função "alocarNoh" aloca dinamicamente um nó para a árvore binária, inicializando
 * seu valor com o parâmetro "valor".
 * 
 * @param valor Valor a ser armazenado no nó
 * @return Ponteiro para o nó alocado
 */
stNo * alocarNoh(int valor){
    stNo *aux = (stNo *) calloc(1, sizeof(stNo));
    aux->valor = valor;
    return aux;
}

/**
 * @brief Calcula a altura de um nó na árvore
 * 
 * A função "alturaNoh" calcula e retorna a altura de um nó na árvore binária, dada
 * sua raiz.
 * 
 * @param raiz Ponteiro para a raiz da árvore
 * @return Altura do nó na árvore
 */
int alturaNoh(stNo *raiz){
    if(!raiz)
        return 0;
    int aux1 = alturaNoh(raiz->esquerda);
    int aux2 = alturaNoh(raiz->direita);
    return aux1 > aux2 ? aux1 + 1 : aux2 + 1;
}

/**
 * @brief Busca um nó em uma árvore binária de busca.
 * 
 * @param raiz A raiz da árvore a ser buscada.
 * @param valor O valor do nó a ser buscado.
 * @note Se o nó for encontrado, imprime 'V'. Se o nó não for encontrado mas a árvore tiver filhos em ambos os lados, imprime 'I'.
 */
void buscarNoh(stNo *raiz, int valor){
    if(!raiz)
        return;
    if(raiz->esquerda && raiz->direita){
        printf("I\n");
        return;
    }
    if(raiz->valor == valor){
        printf("V\n");
        return;
    }
    if(raiz->valor > valor)
        return buscarNoh(raiz->esquerda, valor);
    return buscarNoh(raiz->direita, valor);
}

/**
 * @brief Imprime os valores de uma árvore binária em ordem
 * 
 * Percorre a árvore recursivamente em ordem, imprimindo os valores de cada nó.
 * 
 * @param raiz O ponteiro para a raiz da árvore
 */
void imprimirArvoreEmOrdem(stNo *raiz){
	// RED = pre-ordem ou prefixa. ERD = ordem ou infixa. EDR = pos-ordem ou posfixa.
    if(raiz){
        imprimirArvoreEmOrdem(raiz->esquerda);
		printf("%d ", raiz->valor);
        imprimirArvoreEmOrdem(raiz->direita);
    }
}

/**
 * @brief Imprime os valores de uma árvore binária na ordem pós-ordem
 * 
 * Percorre a árvore recursivamente em ordem pós-ordem, imprimindo os valores de cada nó.
 * 
 * @param raiz O ponteiro para a raiz da árvore
 */
void imprimirArvorePosOrdem(stNo *raiz){
	// RED = pre-ordem ou prefixa. ERD = ordem ou infixa. EDR = pos-ordem ou posfixa.
    if(raiz){
        imprimirArvorePosOrdem(raiz->esquerda);
        imprimirArvorePosOrdem(raiz->direita);
		printf("%d ", raiz->valor);
    }
}

/**
 * @brief Imprime os valores de uma árvore binária na ordem pré-ordem
 * 
 * Percorre a árvore recursivamente em ordem pré-ordem, imprimindo os valores de cada nó.
 * 
 * @param raiz O ponteiro para a raiz da árvore
 */
void imprimirArvorePreOrdem(stNo *raiz){
	// RED = pre-ordem ou prefixa. ERD = ordem ou infixa. EDR = pos-ordem ou posfixa.
    if(raiz){
		printf("%d ", raiz->valor);
        imprimirArvorePreOrdem(raiz->esquerda);
        imprimirArvorePreOrdem(raiz->direita);
    }
}

/**
 * @brief Imprime os valores de uma árvore binária de forma formatada
 * 
 * Percorre a árvore recursivamente, imprimindo os valores de cada nó e adicionando traços para indicar a hierarquia.
 * 
 * @param raiz O ponteiro para a raiz da árvore
 * @param traco O número de traços a serem adicionados antes de cada valor de nó
 */
void imprimirArvoreFormatada(stNo *raiz, int traco){
    int i;
    if(raiz){
        imprimirArvoreFormatada(raiz->direita, traco + 3);
        for(i = 0; i < traco; i++)
            printf("-");
        printf("%d\n", raiz->valor);
        imprimirArvoreFormatada(raiz->esquerda, traco + 3);
    }
}

/**
 * @brief Imprime os valores de uma árvore binária em ordem de nível
 * 
 * Percorre a árvore em ordem de nível, imprimindo os valores de cada nó.
 * 
 * @param raiz O ponteiro para a raiz da árvore
 * @param telementos O número total de elementos na árvore
 */
void imprimirArvoreNivelada(stNo *raiz, int telementos){
    stNo **vetor = (stNo **) calloc(telementos, sizeof(stNo *));
    vetor[0] = raiz;
    int contador = 1, passo = 0;
    while(contador < telementos){
        if(!vetor[passo]->esquerda && !vetor[passo]->direita)
            passo++;
        else {
            int nulo;
            for(nulo = 0; nulo < telementos; nulo++)
                if(!vetor[nulo])
                    break;
            if(!vetor[passo]->esquerda || !vetor[passo]->direita){
                if(!vetor[passo]->direita)
                    vetor[nulo] = vetor[passo]->esquerda;
                else
                    vetor[nulo] = vetor[passo]->direita;
                contador++;
                passo++;
            } else {
                vetor[nulo] = vetor[passo]->esquerda;
                vetor[nulo + 1] = vetor[passo]->direita;
                contador += 2;
                passo++;
            }
        }
    }
    for(contador = 0; contador < telementos; contador++)
        printf("%d ", vetor[contador]->valor);
}

/**
 * @brief Imprime os valores da árvore com seus respectivos parênteses.
 * 
 * @param raiz Ponteiro para a raiz da árvore.
 */
void imprimirArvoreComParenteses(stNo *raiz){
    if(raiz){
        printf("%d(", raiz->valor);
        imprimirArvoreComParenteses(raiz->esquerda);
        imprimirArvoreComParenteses(raiz->direita);
        printf(")");
    }
}

stNo * inserirNoh(stNo *raiz, stNo *no){
    if(!raiz)
        return no;
    if(no->valor < raiz->valor)
        raiz->esquerda = inserirNoh(raiz->esquerda, no);
    else
        raiz->direita = inserirNoh(raiz->direita, no);
    return raiz;
}

stNo * inserirNohArvoreBalanceada(stNo *arvore, int *vetor, int inicio, int fim){
    if(inicio > fim)
        return;
    if(inicio == fim){
        arvore = inserirNoh(arvore, alocarNoh(vetor[inicio]));
        return;
    }
    int meio = (inicio + fim) / 2;
    arvore = inserirNoh(arvore, alocarNoh(vetor[meio]));
    inserirNohArvoreBalanceada(arvore, vetor, inicio, meio - 1);
    inserirNohArvoreBalanceada(arvore, vetor, meio + 1, fim);
}

int profundidadeNoh(stNo *raiz, int valor, int profundidade){
    if(!raiz)
        return 0;
    if(raiz->valor == valor)
        return profundidade;
    profundidade++;
    if(raiz->valor > valor)
        return profundidadeNoh(raiz->esquerda, valor, profundidade);
    return profundidadeNoh(raiz->direita, valor, profundidade);
}

int quantidadeNohs(stNo *raiz){
    if(!raiz)
        return 0;
    return 1 + quantidadeNohs(raiz->esquerda) + quantidadeNohs(raiz->direita);
}

void quickSort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim;
	int pivot = vetor[(inicio + fim) / 2];
	int aux;
	do {
		while(vetor[i] < pivot)
			i++;
		while(vetor[f] > pivot)
			f--;
		if(i <= f){
			aux = vetor[i];
			vetor[i++] = vetor[f];
			vetor[f--] = aux;
		}
	} while(i < f);
	if(inicio < f)
		quickSort(vetor, inicio, f);
	if(i < fim)
		quickSort(vetor, i, fim);
}

stNo * removerArvore(stNo *raiz){
    if(raiz){
        removerArvore(raiz->esquerda);
        removerArvore(raiz->direita);
        free(raiz);
    }
    return NULL;
}

stNo * removerNoh(stNo *raiz, int valor){
    // Lado = 0: maior da esquerda. Lado = 1: menor da direita
    int lado = 1;
    stNo *no = raiz, *paiNo = NULL;
    stNo *sub = NULL, *paiSub = NULL;
    while(no){
        if(no->valor == valor)
            break;
        paiNo = no;
        if(no->valor > valor)
            no = no->esquerda;
        else
            no = no->direita;
    }
    if(!no)
        return raiz;
    if(!no->esquerda || !no->direita)
        if(!no->esquerda)
            sub = no->direita;
        else
            sub = no->esquerda;
    else {
        if(lado){
            // Menor da direita
            paiSub = no;
            sub = no->direita;
            while(sub->esquerda){
                paiSub = sub;
                sub = sub->esquerda;
            }
            if(paiSub != no){
                paiSub->esquerda = sub->direita;
                sub->direita = no->direita;
            }
            sub->esquerda = no->esquerda;
        } else {
            // Maior da esquerda
            paiSub = no;
            sub = no->esquerda;
            while(sub->direita){
                paiSub = sub;
                sub = sub->direita;
            }
            if(paiSub != no){
                paiSub->direita = sub->esquerda;
                sub->esquerda = no->esquerda;
            }
            sub->direita = no->direita;
        }
    }
    if(!paiNo){
        free(no);
        return sub;
    }
    if(paiNo->valor > valor)
        paiNo->esquerda = sub;
    else
        paiNo->direita = sub;
    free(no);
    return raiz;
}

int somaFolhas(stNo *raiz){
    if(!raiz)
        return 0;
    if(!raiz->esquerda && !raiz->direita)
        return raiz->valor;
    return somaFolhas(raiz->esquerda) + somaFolhas(raiz->direita);
}

int somaInterna(stNo *raiz){
    if(!raiz)
        return 0;
    if(!raiz->esquerda && !raiz->direita)
        return 0;
    return raiz->valor + somaInterna(raiz->esquerda) + somaInterna(raiz->direita);
}

int main(){
	stNo *arvore = alocarNoh(10);
	imprimirArvoreEmOrdem(arvore);
	return 0;
}