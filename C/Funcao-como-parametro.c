#include <stdio.h>

typedef int (*Operacao)(int, int);
int opera(int a, int b, Operacao o){return o(a,b);}

int soma      (int a, int b){return a + b;}
int multiplica(int a, int b){return a * b;}

int main(){
  printf("%d\n", opera(2, 5, soma));
  printf("%d\n", opera(4, 6, multiplica));
  return 0;
}