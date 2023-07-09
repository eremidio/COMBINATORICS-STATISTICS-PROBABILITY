//PROGRAMA PARA TESTAR A FUNÇÕES DEFINIDAS EM combinatorics.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o combinatorics combinatorics.c

//Cabeçalho
#include"combinatorics.h" 
#include<stdio.h>

//Função principal
int main(){
//Variáveis locais
int n, k;
uint64_t array[] = {1,2,3,4};
//Procedimentos
//Recebendo input dos usuários
printf("Digite um número: ");
scanf("%d", &n);
printf("Digite um número: ");
scanf("%d", &k);

//Printando os resultados na tela
printf("Permutações(%d)=%d\n", n, (int)permutation(n));
printf("Permutações com elementos repetidos(%d|1,2,3,4)=%d\n", n, (int)repeated_permutation(n, array, 4));
printf("Arranjos simples(%d,%d)=%d\n", n, k, (int)arrangement(n, k));
printf("Combinações simples(%d,%d)=%d\n", n, k, (int)combination(n, k));

//Finalizando a aplicação
return 0;
          }
