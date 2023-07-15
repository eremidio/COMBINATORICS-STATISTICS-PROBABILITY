/*
A CARDINALIDADE DE UM CONJUNTO FINITO ω É IGUAL AO SEU NÚMERO DE ELEMENTOS E É DENONTADA POR |ω|.
O CONJUNTO DE TODOS OS SUBCONJUNTOS DE UM DADO CONJUNTO É CHAMADO DE CONJUNTO POTÊNCIA E É DENOTADO POR P(ω).
O SEGUINTE TEOREMA É FACILMENTE PROVADO USANDO-SE INDUÇÃO:
|P(ω)|=2^(|ω|).

PARA MAIORES REFERÊNCIAS: https://en.wikipedia.org/wiki/Power_set
*/

//***************************************************************************************************************************
//CABEÇALHO
#if !defined POWERSET_H
#define POWERSET_H
#include<vector>
#include<bitset>
#include<iostream>
#include<cmath>
#include<stdint.h>

//***************************************************************************************************************************
//CLASSE
//Classe com os métodos usandos nos cálculos de P(ω)

template<typename T>
class power_set_class{
public:
//Membros da classe
int set_size ;
uint64_t subset_number;
std::vector<T> set_vector;

//Métodos da classe
void setup();//Inicializando o conjunto
void print_subset();//Função que printa um subconjunto de um dado 
void run();//Função principal
                     };


//***************************************************************************************************************************
//MÉTODOS DA CLASSE
//Função que recebe input do usuário
template<typename T>
void power_set_class<T>::setup(){
//Definindo o tamanho do conjunto a ser permutado
std::cout<<"Digite quantos elementos você vai incluir em seu conjunto:\n";
std::cin>>set_size;
//Variáveis locais 
T element;

//Recebendo os elementos que compõem o conjunto
for(int i = 0; i<set_size; ++i){
std::cout<<"Digite qual elemento será adicionado ao conjunto:\n";
std::cin>>element;
set_vector.push_back(element);
                               };

//Calculando o número de subconjuntos distintos de um dado subcojunto
subset_number=std::pow(2, set_size);
                             
                               };

//Função que printa um subconjunto do conjunto 
template<typename T>
void power_set_class<T>::print_subset(){
//Variáveis locais
std::bitset<64> bit_index(subset_number);
//Printando os subcojuntos não vazios na tela
std::cout<<"{";
for(int i=0; i<set_size; ++i){
if(bit_index.test(i))//Testando se o bit em questão é 1
std::cout<<set_vector[i]<<", ";
                             };
std::cout<<"}\n";

                                       };

//Função principal
template<typename T>
void power_set_class<T>::run(){
//Ajuste de variável
setup();
subset_number--;

//Loop principal
while(true){
print_subset();
subset_number--;
if(subset_number==0)
break;
           };

//Printando o conjunto vázio
std::cout<<"{ }\n";

                              };

//***************************************************************************************************************************
//FIM DO HEADER
#endif

