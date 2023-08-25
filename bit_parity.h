//VAMOS CRIAR UM PROGRAMA QUE CALCULA O BIT DE PARIDADE DE UM DADO NÚMERO INTEIRO

/*
DADO UM NÚMERO INTEIRO PODEMOS EXPRESSÁ-LO EM NOTAÇÃO BINÁRIA COMO UMA STRING DE 0's E 1's. STRINGS COM UM NÚMERO ÍMPAR DE 0 DE
1's SÃO DITAS DE PARIDADE ÍMPAR, CASO CONTRÁRIO SÃO DITAS DE PARIDADE PAR.

A PARIDADE DE STRINGS BINÁRIAS É MUITO ÚTIL EM UMA SÉRIE DE PROBLEMAS E APLICAÇÕES. UM EXEMPLO IMPORTANTE É A IMPLEMENTAÇÃO 
DE MECANISMOS DE AUTOCORREÇÃO (RECUPERAÇÃO DE DADOS) EM ARQUIVOS COMO NOS CHAMADOS CÓDIGOS DE HAMMING. 

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Parity_bit
                          https://en.wikipedia.org/wiki/Hamming_code

*/


//*************************************************************************************************************************
//CABEÇALHO
#ifndef BIT_PARITY_H
#define BIT_PARITY_H
#include<stdint.h>
#include<inttypes.h>

//*************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
int even_parity_bit(uint64_t);
int odd_parity_bit(uint64_t);

//*************************************************************************************************************************
//FUNÇÕES
//Bit de paridade par
int even_parity_bit(uint64_t number){
//Variáveis locais
int one_bit_counter=0;
//Procedimentos
//Loop principal
while(number>0){
if(number&1)
one_bit_counter++;

number>>=1;
               };

//Resultados
if(one_bit_counter&1)
return 1;
else
return 0;
                                    };

//Bit de paridade ímpar
int odd_parity_bit(uint64_t number){
//Variáveis locais
int one_bit_counter=0;
//Procedimentos
//Loop principal
while(number>0){
if(number&1)
one_bit_counter++;

number>>=1;
               };

//Resultados
if(one_bit_counter&1)
return 0;
else
return 1;
                                   };

//*************************************************************************************************************************
//FIM DO HEADER
#endif
