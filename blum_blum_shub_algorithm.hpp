//VAMOS CRIAR UM PROGRAMA QUE IMPLMENTA O ALGORITMO BLUM-BLUM-SHUB PARA GERA UMA SEQUÊNCIA DE BITS PSEUDO-ALEATÓRIA

/*
O ALGORITMO DE BLUM-BLUM-SHUB É USADO PARA GERA UMA SEQUÊNCIA DE BITS CRIPTOGRAFICAMENTE SEGURA.
O MÉTODO BASEIA-SE NA RELAÇÃO DE RECORRÊNCIA: X(n+1) = [X(n)]² (mod m). NESTE ALGORITMO m=pq, ONDE p E q SÃO DOIS NÚMEROS
PRIMOS QUE SATISFAZEM AS RELAÇÕES p=3 (mod 4) E q=3 (mod 4) ISTO GARANTE QUE A SEQUÊNCIA POSSUI GRANDES PERÍODOS. PARA GARANTIR 
QUE O ALGORITMO FUNCIONE BEM É RECOMENDÁVEL UMA CHECAGEM ADICIONAL QUE GARANTA QUE mdc(φ(p-1), φ(q-1))<< m, ONDE φ É A FUNÇÃO
TOTIENTE DE EULER.

O VALOR INICIAL X(0) DEVE SER COPRIMO COM m, ISTO É, mdc(X(0), m)=1. O ALGORITMO COMPUTA PARA CADA X(n+1) SUA CONGRUÊNCIA MÓDULO 2 GERANDO ASSIM ASEQUÊNCIA DE BITS REQUERIDA.

OS VALORES DA SEQUÊNCIA DE INTEIROS X(i)'s PODEM SER COMPUTADOS TAMBÉM DIRETAMENTE VIA A RELAÇÃO:
X(n)={X(0)^[2^n (mod λ(m))]} (mod m).
NESTA FÓRMULA λ(m) É A FUNÇÃO TOTIENTE REDUZIDA OU FUNÇÃO DE CARMICHAEL QUE PARA A ESCOLHA PARTICULAR DE m NESTE ALGORITMO É
DADA POR λ(m)=λ(pq)= mmc((p-1), (q-1)) = [(p-1)(q-1)]/mdc((p-1), (q-1)).



PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Blum_Blum_Shub
*/

//****************************************************************************************************************
//CABEÇALHO
#ifndef BLUM_BLUM_SHUB_H
#define BLUM_BLUM_SHUB_H
#include"bit_parity.h"
#include"euler_totient_function.h"
#include<random>
#include<cmath>
#include<iostream>

//****************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
uint64_t generate_random_prime();
void blum_blum_shub(uint64_t);

//****************************************************************************************************************
//FUNÇÕES
//Função usada para se gerar um número inteiro aleatório da ordem 64 bits 
uint64_t generate_random_prime(){

  //Variáveis locais
  uint64_t result;

  //Procedimentos
    //Ajuste da distribuição de números aleatórios
    std::random_device generator_x;
    std::mt19937 gen(generator_x());
    std::uniform_int_distribution<uint64_t> bbs_distribution(1e6, 9e7);

  //Resultado
  result=bbs_distribution(generator_x);
  return result;
                                };

//Função que implementa o algoritmo de Blum-Blum-Shub
//Usaremos as funções is_prime e gcd_euclides que estão definidas no arquivo euler_totient_function.h
void blum_blum_shub(uint64_t bit_size){

  //Variáveis locais
  uint64_t prime1, prime2;
  uint64_t m, previous, next;
  short bit_array[500000]; 


  //Procedimentos
    //Selecionando dois números primos entre 10^6 e 10^7
    pick1:
    prime1=generate_random_prime();

    if(gauss_euler_primality_test(prime1)==false || (prime1%4)!=3)
      goto pick1;

    pick2:
    prime2=generate_random_prime();

    if(gauss_euler_primality_test(prime2)==false || (prime2%4)!=3)
      goto pick1;


    //Calculando o congruente e checando se os valores selecionados são bons
    m=prime1*prime2;

    if(gcd_euclides(euler_totient_function(prime1-1), euler_totient_function(prime2-1))>(m/100))
      goto pick1;

    //Gerando uma semente inicial coprima com o congruente
    pick3:
      previous=generate_random_prime();

    if(gcd_euclides(previous, m)!=1)
      goto pick3;

    //Loop principal
      //Computando o primeiro bit
      bit_array[0] = even_parity_bit(previous);

      //Demais termos na sequência
      for(uint64_t i=1; i<bit_size; ++i){
        next=((previous%m)*(previous%m))%m;
        bit_array[i] = even_parity_bit(previous);

      //Atualizando variáveis para próxima iteração
      previous=next;
                                        };


    //Printando a string binária gerada
    for(uint64_t j=0; j<bit_size; ++j)
      std::cout<<bit_array[j];
    std::cout<<"\n";

                                      };

//****************************************************************************************************************
//FIM DO HEADER
#endif
