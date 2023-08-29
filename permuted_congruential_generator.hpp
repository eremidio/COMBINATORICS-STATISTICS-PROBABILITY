/*VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE GERAÇÃO DE NÚMEROS ALEATÓRIOS BASEADO NA PERMUTAÇÃO DE BITS DE UM
NÚMERO*/

/*
O ALGORITMO DE PERMUTAÇÃO DE BITS É UMA ADAPTAÇÃO DO ALGORITMO DE GERADORES LINEARES NO QUAL A MANIPULAÇÃO DE BITS É EMPREGADA 
AFIM DE MELHORAR A EQUIDISTRBUIÇÃO DE VALORES GERADOS PELA RELAÇÃO LINEAR A MENOS DE UMA CONGRUÊNCIA.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Permuted_congruential_generator
*/ 

//***************************************************************************************************************************
//CABEÇALHO 
#ifndef PERMUTED_CONGRUENTIAL_GENERATOR_H
#define PERMUTED_CONGRUENTIAL_GENERATOR_H
#include<stdint.h>
#include<inttypes.h>
#include<iostream>

//***************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
uint32_t pcg_algorithm(uint64_t, uint64_t, uint64_t);
static uint32_t bit_shift(uint32_t, unsigned);

//***************************************************************************************************************************
//FUNÇÕES
//Função que permuta os bits em um inteio de 32 bits
static uint32_t bit_shift(uint32_t n, unsigned r){
return (n>>r)|(n<<(-r&31));
                                                 };

//Função que usa um gerador de congruência lineares para geração de números alaetórios
//Usamos aqui a variante XSH-RR
//(64→32 bits) count = (int)(x >> 59); x ^= x >> 18; return bit_shift((uint32_t)(x >> 27), counter);
uint32_t pcg_algorithm(uint64_t state, uint64_t multiplier, uint64_t increment){
//Variáveis
uint64_t x= state;
unsigned counter= (x>>59); //5=64-59

//Procedimentoos
state=(x*multiplier)+increment;
x ^= x >> 18; 
return bit_shift((uint32_t)(x >> 27), counter); 
                                                                               };

//***************************************************************************************************************************
//FIM DO HEADER
#endif
