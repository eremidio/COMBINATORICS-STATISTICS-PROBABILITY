//VAMOS CRIAR UM PROGRAMA EM C++ QUE USA O ALGORITMO DE VON NEUMANN PARA GERA NÚMEROS PSEUDO ALEÁTÓRIOS
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o von_neumann_middle_algorithm von_neumann_middle_algorithm.cpp

/*
O ALGORITMO DE VON NEUMANN É USADO PARA GERAR NÚMEROS PSEUDOALEATÓRIOS.
A IDEIA BÁSICA DO ALGORITMO É USAR UM NÚMERO DE QUATRO DIGITOS E ELEVÁLO AO QUADRADO. EM SEGUIDA TOMA-SE OS ALGARISMOS CENTRAIS
E UMA NOVA SEMENTE É GERADA PARA A PRÓXIMA INTERAÇÃO.

SE N(1), N(2), ..., N(n) FOR A SEQUÊNCIA GERADA POR ESTE ALGORITMO É POSSÍVEIL MOSTRAR QUE EXISTE UM k INTEIRO TAL QUE PARA m 
INTEIRO TÊM-SE N(k+m) = N(m) SE m>M, ONDE M É CONSTANTE. SE ALGUM TERMO NESTA SEQUÊNCIA FOR MENOR QUE 10 O ALGORITMO GERA UMA
SEQUÊNCIA DE 0's.

PARA MAIORES INFORMAÇÕES: https://hbfs.wordpress.com/2017/11/21/the-middle-square-method-generating-random-sequences-viii/

*/


//***************************************************************************************************************************
//CABEÇALHO
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include"divisibility.h"
using namespace std;

//***************************************************************************************************************************
//FUNÇÕES
//Função que extrai os digitos centrais de um número inteiro e produz outro número inteiro
uint64_t middle_cut(uint64_t seed){
//Variáveis locais
uint64_t grown_seed = seed*seed;
int number_digits = digits_counter(grown_seed);
int start_digit = number_digits/4;
int end_digit = number_digits-(number_digits/4);
uint64_t next_number;

//Calculando o próximo número da sequência
next_number = extract_digits_interval(grown_seed, start_digit, end_digit);

return next_number;
                                  };


//***************************************************************************************************************************
//FUNÇÃO PRINCIPAL
int main(){
//Variáveis locais
string filename;
fstream file_record;
uint64_t seed, next_number, iterations;
uint64_t i;//variável de iteração

//Procedimentos
//Abrindo um arquivo para registrar os resultados dos experimento
cout<<"Usuário digite o nome de um arquivo com a extensão para registrar os resultados do experimento:\n-->";
getline(cin, filename);
filename+=".txt";
file_record.open(filename, ios::in|ios::out|ios::app);

if(file_record.is_open()==false){
cout<<"Erro ao abrir o arquivo!\n";
exit(0);
                                };

//Recebendo input do usuário para iniciar o algoritmo
cout<<"Usuário digite um inteiro com 4 digitos para iniciar a sequência: ";
cin>>seed;
cout<<"Digite o número de termos a serem gerados no experimento: ";
cin>>iterations;

//Registrando a smente inicial para gera números pseudoaletórios
file_record<<seed<<"\n";

//Loop principal
for(i=0; i<iterations; ++i){
next_number= middle_cut(seed);
file_record<<next_number<<"\n";

//Ajuste de variáveis para a próxima iteração
seed=next_number;
                           };

//Finalizando a aplicação
cout<<"Números pseudoaleatórios gerados com sucesso!\n";
file_record.close();
return 0;


          }
