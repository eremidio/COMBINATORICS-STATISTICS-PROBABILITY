//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DO GERADOR DE CONGRUÊNCIAS LINEARES

/*
O ALGORITMO DO GERADOR DE CONGRUÊNCIAS LINEARES US UMA FUNÇÃO LINEAR A MENOS DE UMA RELAÇÃO DE COMGRUÊNCIA f(x)=ax+b (mod m)
PARA PRODUZIR UMA STRING DE BITS PSEUDOALEATÓRIAS.

O ALGORITMO BASEIA-SE NA RELAÇÃO RECURSIVA X(i+1)=aX(i)+b (mod m), COM i=0, 1, 2,...; COM mdc(a,m)=1. SE b=0 A RELAÇÃO
RECURSIVA É DITA PURAMENTE MULTIPĹICATIVA. É IMPORTANTE NOTAR QUE ESTA EQUAÇÃO É PERIÓDICA COM PERÍODO MÁXIMO n. PARA FINS
COMPUTACIONAIS NORMALMENTE SE USA m=2^32 OU m=2^64. 

A ESCOLHA DOS PARÂMETROS a, b, m INFLUENCIA NA QUALIDADE DO GERADOR DE STRINGS BINÁRIAS ALEATÓRIAS. EM PARTICULAR É
RECOMENDÁVEL QUE mdc(b, n)=1, PARA EVITAR QUE TODOS OS X(i)'s TENHAM A MESMA PARIDADE. SE mdc((a-1), m)=1, O VALOR INICIAL DE
X(0) DEVE SER TAL QUE mdc(X(0)-(b/(a-1)), m) = 1.

O TEOREMA DE HULL-DOBELL ESPECIFICA TRÊS CONDIÇÕES PARA QUE A SEQUÊNCIA DE NÚMEROS GERADOS TENHA PERIODICIDADE MÁXIMA:
mdc(b, m)= 1; a=1 (mod p) PARA TODO PRIMO p QUE DIVIDE m; a=1 (mod 4) SE m FOR MÚLTIPLO DE 4.

UM CASO DE PARTICULAR IMPORTÂNCIA SÃO OS GERADORES DE LEHMER NO QUAIS b=0. NESTE CASO É RECOMNDÁVEL ESCOLHER m=p^k, ONDE p É UM NÚMERO PRIMO E a UMA RAÍZ PRIMITIVA DE m. ALÉM DISSO p NÃO PODE DIVIDIR X(0).

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Linear_congruential_generator

*/

//******************************************************************************************************************** 
//CABEÇALHO
#ifndef LINEAR_CONGRUENCE_GENERATOR_H
#define LINEAR_CONGRUENCE_GENERATOR_H
#include<iostream>
#include<stdint.h>
#include<cassert>
#include<random>

//CONSTANTES GLOBAIS
#define BINARY_STRING_SIZE 100000

//******************************************************************************************************************** 
//DECLARAÇÃO DE FUNÇÕES
uint64_t euclides_algorithm(uint64_t, uint64_t);
uint64_t generate_key();
void lcg_algorithm();
void lcg_lehmer_variant();

//******************************************************************************************************************** 
//FUNÇÕES
//Função que implementa o algoritmo de Euclides para testes de coprimalidade
uint64_t euclides_algorithm(uint64_t a, uint64_t b){
if(b==0)
return a;
else
return euclides_algorithm(b, a%b);
                                                   };

//Função usada para se gerar um número inteiro aleatório da ordem 64 bits 
uint64_t generate_random_number(uint64_t number){
//Variáveis locais
uint64_t result;

//Ajuste da distribuição de números aleatórios
std::random_device generator_x;
std::mt19937 gen(generator_x());
std::uniform_int_distribution<int64_t> lcg_distribution(1, number-1);

//Resultado
result=lcg_distribution(generator_x);
return result;
                                                };

//Função que implementa o algoritmo do gerador linear
void lcg_algorithm(){
//Variáveis locais
uint64_t a, b, m, previous, next;
uint64_t i;//Variável de iteração
uint64_t bit_size;
int bits[BINARY_STRING_SIZE];
int tuning;

//Procedimentos
//Recebendo um input do usuário
std::cout<<"Digite o números de bits a serem incluidos em sua string binária: ";
std::cin>>bit_size;
assert(bit_size<=BINARY_STRING_SIZE);

std::cout<<"Digite o fator multiplicativo a ser usado no cálculo: ";
std::cin>>a;
std::cout<<"Digite o fator de incremento a ser usado no cálculo: ";
std::cin>>b;
std::cout<<"Digite o fator de congruência a ser usado no cálculo: ";
std::cin>>m;
std::cout<<"Digite um inteiro positivo a ser como gerador inicial de bits ";
std::cin>>previous;

//Otimzação de parâmetros
std::cout<<"Digite '0' para prosseguir com a simulação ou '1' para otimizar os parâmetros da simulação: ";
std::cin>>tuning;

if(tuning==1){
while(euclides_algorithm(a, m)!=1)
a=generate_random_number(m);
while(euclides_algorithm(b, m)!=1)
b=generate_random_number(m);
             };

//Gerando a sequência de bits
//Registrando o primeiro bit
if(previous%2==0)
bits[0]=0;
else
bits[0]=1;

for(i=1; i<bit_size; ++i){
next = ((a%m)*(previous%m))%m;
next+=(b%m);
next%=m;

//Registrando o bit
if(next%2==0)
bits[i]=0;
else
bits[i]=1;

//Atualizando variáveis para a próxima iteração
previous = next;
                         };


//Printando o string de bits gerado
std::cout<<"String de bits gerada:\n";
for(i=0; i<bit_size; ++i)
std::cout<<bits[i];
std::cout<<"\n";
                    };



//Função que implmenta a variuante de Lehmer do algoritmo de geração de congruentes lineares
void lcg_lehmer_variant(){
//Variáveis locais
uint64_t a, b, m, previous, next;
uint64_t i;//Variável de iteração
uint64_t bit_size;
int bits[BINARY_STRING_SIZE];

//Procedimentos
//Recebendo um input do usuário
std::cout<<"Digite o números de bits a serem incluidos em sua string binária: ";
std::cin>>bit_size;
assert(bit_size<=BINARY_STRING_SIZE);

std::cout<<"Digite o fator de congruência a ser usado no cálculo.\n(Usar um primo ou uma potência de número primo): ";
std::cin>>m;
std::cout<<"Digite o fator multiplicativo a ser usado no cálculo.\n(Este fator multiplicativo deve ser preferencialmente uma raíz primitiva do fator de congruência): ";
std::cin>>a;
std::cout<<"Digite um inteiro positivo a ser como gerador inicial de bits.\n(Este inteiro não pode ser divisível pelo primo no fator de congruência): ";
std::cin>>previous;


//Gerando a sequência de bits
//Registrando o primeiro bit
if(previous%2==0)
bits[0]=0;
else
bits[0]=1;

//Loop principal
for(i=1; i<bit_size; ++i){
next = ((a%m)*(previous%m))%m;

//Registrando o bit
if(next%2==0)
bits[i]=0;
else
bits[i]=1;

//Atualizando variáveis para a próxima iteração
previous = next;
                         };


//Printando o string de bits gerado
std::cout<<"String de bits gerada:\n";
for(i=0; i<bit_size; ++i)
std::cout<<bits[i];
std::cout<<"\n";
                          };

//******************************************************************************************************************** 
//FIM DO HEADER
#endif
