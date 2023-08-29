//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE MERSENNE TWISTER PARA GERAR NÚMEROS ALEATÓRIOS

/*
O ALGORITMO DE MERSENNE TWISTER É DOS ALGORITMOS MAIS EFICIENTES ṔARA A GERAÇÃO DE NÚMEROS PSEUDO ALEATÓRIOS.
O ALGORITMO USA UM ARRAY DE VALORES INICIAIS QUE É MANIPULADO VIA MANIPULAÇÃO DE BITS PARA GERA UMAOYUTREA SEQUÊNCIA DE NÚMEROS
PSEUDO ALEATÓRIOS.

ESTE ALGORITMO APRESENTAUMA EXCELENTE EQUIDISTRBUIÇÃO DE VALORES CONSIDERANDO-SE OS BITS DE MAIOR SIGNFICÂNCIA E PARA VALORES
OTIMIZADOS DE PARÂMETROS PODE GERAR SEQUÊNCIAS DE VALORES COM GRANDE PERÍODOS SEM REPETIÇÃO.

PARA MAIORES INFORMAÇÕES: http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/ARTICLES/mt.pdf
                          https://en.wikipedia.org/wiki/Mersenne_Twister

*/ 


//*************************************************************************************************************************
//CABEÇALHO
#ifndef MERSENNE_TWISTER_H
#define MERSENNE_TWISTER_H
#include<stdint.h>
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cmath>

//CONSTANTES GLOBAIS
#define TEST_RUN 1000000 //Número de valores gerados em cada simulação

//*************************************************************************************************************************
//CLASSE DO ALGORITMO
class mersenne_twister{
public:
//Membros da classe
uint64_t w;//Número de bits usados
uint64_t n;//Grau de recorrência
uint64_t m;//Offsert usado na relação de recorrência
uint64_t r;//Numero  de bitsna mascára inferior
uint64_t a;//Coeficiente da da matrix de inversão de bits
uint64_t b, c;//Bitmasks
uint64_t s, t; //Bit shifts
uint64_t u, d, l;//Parâmetros adicionais da simulação
uint64_t seed;//Valor inicial usado para gerar números aleatórios
uint64_t upper_mask, lower_mask;//Mácaras de bits usadas para concatenação de vetores
uint64_t number_generated;//Valores dos números a serem gerados
uint64_t * value_array;
std::fstream file_record;
std::string filename;

//Construtores e detruidores da classe
mersenne_twister(){
value_array=NULL;
std::cout<<"Usuário digite o nome de um arquivo com a extensão para registrar os resultados do experimento:\n-->";
std::getline(std::cin, filename);
filename+=".txt";
file_record.open(filename, std::ios::in|std::ios::out|std::ios::app);
                  };

~mersenne_twister(){
free(value_array);
file_record.close();
                   };

//Métodos da classe
void run();//Função principal
void setup();//Função que recebe input do usuário
void generate_numbers();//Função que define o valor do array de inteiros que define o estado do gerador de npumeros aleatórios
void generate_bit_mask();//Função que gera máscaras de bits usadas para concatenar bits de dois números distintos
void update_generator();//Função que atualiza a matriz do gerador
void extract_number(uint64_t);//Função que extrai um número inteiro da matriz do gerador de inteiros
                      };

//*************************************************************************************************************************
//MÉTODOS DO ALGORITMO
//Função principal
void mersenne_twister::run(){
//Recebendo input dos usuários e ajustando coeficientes usados na simulação
setup();
//Gerando valores iniciais para a simulação
generate_numbers();
//Gerando as máscara de bits para concatenar 2 números inteiros
generate_bit_mask();
//Atualizando a matriz do gerador e gerando números pseudo aleatórios
number_generated=0;
while(number_generated<TEST_RUN)
update_generator();

                            };

//Função que recebe input dos usuários
void mersenne_twister::setup(){
std::cout<<"Digite quantos bits terá os números gerados nesta simulação: ";
std::cin>>w;
std::cout<<"Digite qual o grau de recorrência usado nesta simulação nesta simulação: ";
std::cin>>n;
std::cout<<"Digite um valor de offset usado na relação de recorrência: ";
std::cin>>m;
std::cout<<"Digite quantos bits serão usados para mascara os bits inferiores de um número: ";
std::cin>>r;
std::cout<<"Digite o valor do coeficiente da matriz de inversão de bits usadas nesta simulação: ";
std::cin>>a;
std::cout<<"Digite o valor do parâmetro b (bitmask) usado nesta simulação: ";
std::cin>>b;
std::cout<<"Digite o valor do parâmetro c (bitmask) usado nesta simulação: ";
std::cin>>c;
std::cout<<"Digite o valor do parâmetro d (bitmask) usado nesta simulação: ";
std::cin>>d;
std::cout<<"Digite o valor do parâmetro u (bitshift) usado nesta simulação: ";
std::cin>>u;
std::cout<<"Digite o valor do parâmetro s (bitshift) usado nesta simulação: ";
std::cin>>s;
std::cout<<"Digite o valor do parâmetros t (bitshift) usado nesta simulação: ";
std::cin>>t;
std::cout<<"Digite o valor do parâmetros l (bitshift) usado nesta simulação: ";
std::cin>>l;
std::cout<<"Digite o valor inicial usado nesta simulação: ";
std::cin>>seed;
                              };

//Função que define o valor do array de inteiros que define o estado do gerador de npumeros aleatórios
void mersenne_twister::generate_numbers(){
//Alocando espaço para o array de inteiros de n bits
value_array = (uint64_t*)realloc(value_array, n*sizeof(uint64_t));

//Variáveis locais
uint64_t f;
std::cout<<"Digite o valor da constante multiplicativa f usada para gerar valores iniciais nesta simulação: ";
std::cin>>f;

//Definindos os elementos no array 
//Primeiro elemento
while((std::log2(seed)+1)<w)
seed<<=1;
value_array[0]=seed;

//TESTE USE UM // APÓSO MESMO
//file_record<<value_array[0]<<"\n";

//Loop principal
for(int i=1; i<=(n-1); ++i){
value_array[i]=f*(value_array[i-1]^(value_array[i-1]>>(w-2)))+i;

//TESTE USE UM // APÓSO MESMO
//file_record<<value_array[i]<<"\n";
                           };
                                         };


//Função que gera máscaras de bits usadas para concatenar bits de dois números distintos
void mersenne_twister::generate_bit_mask(){
//Ajuste de variáveis
upper_mask=1;

//Mascára de bits superiores
for(int i=1; i<w; ++i){
upper_mask<<=1;
if(i==(w-r))
upper_mask-=1;
                      };

//Ajuste de variáveis
lower_mask=(~upper_mask);

//TESTE USE UM // APÓS OS MESMOS
//std::cout<<"Upper mask: "<<upper_mask<<"\n";
//std::cout<<"Lower mask: "<<lower_mask<<"\n";
                                          };

//Função que atualiza a matriz do gerador
void mersenne_twister::update_generator(){
//Variáveis locais
uint64_t y;

//Loop principal
for(int i=0; i<n; ++i){
y=((value_array[i]&upper_mask)|(value_array[(i+1)%n]&lower_mask));

//Caso 1: números ímpares
if(value_array[i]&1){
value_array[i]=((value_array[(i+1)%n]^(y>>1))^a);
extract_number(value_array[i]);
                    }
//Caso 2: números pares
else{
value_array[i]=(value_array[(i+1)%n]^(y>>1));
extract_number(value_array[i]);
    };


if(number_generated==TEST_RUN)
return;
                      };
                                         };

/*Função que extrai um número inteiro da matriz do gerador de inteiros por meio da manipulação de bits da entradas da matriz
do gerador*/
void mersenne_twister::extract_number(uint64_t x){
//Atualizando variáveis
number_generated++;

//Variáveis locais
uint64_t y;

//Mascarando os bits do número gerado
y=x;
y=(y^(y>>u));
y=((y^(y<<s))&b);
y=((y^(y>>t))&c);
y=(y^(y>>l));

//Resgistrando o número em questão
file_record<<y<<'\n';
                                                 };

//*************************************************************************************************************************
//FIM DO HEADER
#endif
