//VAMOS CRIAR PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO bit_parity.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o bit_parity bit_parity.c


//Cabeçalho
#include"bit_parity.h"
#include<stdio.h>

//Função principal
int main(){
//Variáveis locais
int64_t number;

//Procedimento
//Recebendo input do usuário
printf("Digite um número inteiro: ");
scanf("%li", &number);

//Calculando o bit de paridade
printf("Bit de paridade par: %i\n", even_parity_bit(number));
printf("Bit de paridade ímpar: %i\n", odd_parity_bit(number)); 

//Resultado
return 0;
          } 
