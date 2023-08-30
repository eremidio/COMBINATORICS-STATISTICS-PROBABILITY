//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE FIBONNACCI PARA GERAÇÃO DE NÚMEROS ALEATÓRIOS
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o lagged_fibonacci_generator lagged_fibonacci_generator.cpp


/*
O ALGORITMO DE FIBONACCI USA UMA RELAÇÃO RECURSIVA DO TIPO F(n)=F(n-s)*F(n-r) (mod m). ONDE * DENOTA UMA OPERAÇÃO BINÁRIA COMO ADIÇÃO, SUBTRAÇÃO, MULTIPLICAÇÃO, BITWISE XOR, PARA COMBINAR DOIS NÚMEROS INTEIROS; r E s SÃO DOIS INDEXES QUE DETERMINAM O
GRAU DE RECORRÊNCIA USADO NA RELAÇÃO; m É UM FATOR DE CONGRUÊNCIA QUE DETERMINA O INTERVALO DE VALORES A SER GERADO 0,...,
(m-1).

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Lagged_Fibonacci_generator

*/


//************************************************************************************************************************
//CABEÇALHO
#include<iostream>
#include<fstream>
#include<stdint.h>
using namespace std;


//************************************************************************************************************************
//FUNÇÕES
//Função que concatena dois números usando bitwise xor
uint64_t get_next_value(uint64_t n1, uint64_t n2, uint64_t m){
return ((n1%m)+(n2%m))%m;
                                                             };

//************************************************************************************************************************
//FUNÇÃO PRINCIPAL
int main(){
//Variáveis locais
string filename;
fstream file_record;
uint64_t seed1, seed2, next_number, iterations;
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
cout<<"Usuário digite um inteiro para iniciar a sequência: ";
cin>>seed1;
cout<<"Usuário digite um inteiro para iniciar a sequência: ";
cin>>seed2;
cout<<"Digite o número de termos a serem gerados no experimento: ";
cin>>iterations;

//Registrando a sementes iniciais para gera números pseudoaletórios
file_record<<seed1<<'\n';
file_record<<seed2<<'\n';

//Loop principal
for(i=0; i<iterations; ++i){
next_number= get_next_value(seed1, seed2, 2305843009213693951);
file_record<<next_number<<"\n";

//Ajuste de variáveis para a próxima iteração r=1, s=2
seed2=seed1;
seed1=next_number;
                           };

//Finalizando a aplicação
cout<<"Números pseudoaleatórios gerados com sucesso!\n";
file_record.close();
return 0;
          }

