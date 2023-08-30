//VAMOS CRIAR UM PROGRAMA QUE IMPLMENTA O ALGORITMO DE SUBTRAÇÃO PARA GERA NÚMEROS ALEASTÓRIOS
//COMPILAR ESTE PRGRAMA COM O COMANDO:  g++ -o subtract_with_carry subtract_with_carry.cpp

/*
O ALGORITMO DA SUBTRAÇÃO É BASEADO NA SEGUINTE RELAÇÃO RECURSIVA X(i)= [X(i-s)-X(i-r)-C] (mod m), ONDE C=0 SE 
X(i-s)-X(i-r)-C>0 OU C=1 SE X(i-s)-X(i-r)-C<0.
m= 2^w ONDE w É O NÚMERO DE BITS DO NÚMEROS A SEREM GERADOS.

OS NÚMEROS GERADOS DEVEM SR DO TIPO UNSIGNED.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Subtract_with_carry#cite_note-3
 
*/ 

//*********************************************************************************************************************
//CABEÇALHO
#include<vector>
#include<iostream>
#include<cstdint>
#include<string>
#include<cassert>
#include<fstream>
using namespace std;

//*********************************************************************************************************************
//FUNÇÃO PRICIPAL
int main(){
//Variáveis locais
fstream file_record;
string filename;
vector<uint_fast64_t> shift_vector;
uint_fast64_t s, r, carry=0, n, seed, next;
uint_fast64_t i;

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
//Recebendo input dos usuário
cout<<"Digite o número de valores iniciais serem usados no experimento: ";
cin>>n;
cout<<"Usuário digite um inteiro para iniciar a sequência: ";
cin>>seed;
cout<<"Usuário digite o valor do maior ciclo: ";
cin>>r;
cout<<"Usuário digite o valor do menor ciclo: ";
cin>>s;

//Restrição
assert(r<n && s<n && s<r);

//Preenchendo o vetor de inteiros
shift_vector.resize(0);
for(i=0; i<n; ++i){
if(i==0)
shift_vector.push_back(seed);
else
shift_vector.push_back(((shift_vector[i-1]%2305843009213693951)*(shift_vector[i-1]%2305843009213693951)+(shift_vector[i-1]%2305843009213693951))%2305843009213693951);
                  };

//Loop principal
for(i=0; i<n; ++i){
next=shift_vector[(i-s)%n]- shift_vector[(i-r)%n]-carry;
if(next>0)
file_record<<next<<'\n';

if(next<0)
carry=1;
else
carry=0;
                  };

//Finalizando a aplicação
cout<<"Números pseudoaleatórios gerados com sucesso!\n";
file_record.close();
return 0;

          }
