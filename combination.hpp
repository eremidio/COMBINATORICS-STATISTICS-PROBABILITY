//VAMOS CRIAR UM ARQUIVO PARA CALCULAR COMBINAÇÕES EM UM DADO CONJUNTO

/*
DADO UM UM CONJUNTO COM n DISTINTOS ELEMENTOS A COMBINAÇÃO SIMPLES C(n,k) COMPUTA QUANTOS SUBCONJUNTOS COM k ELEMENTOS
DISTINTOS ENTRE SI PODEMOS FORMAR DESTES CONJUNTOS.

SENDO n! O FATORIAL DE UM NÚMERO, ISTO É: n!=1.2.(...).(n-1).n; VALE A RELAÇÃO
C(n,k)= n!/(k!(n-k)!)

PARA MAIORES REFERÊNCIAS: https://en.wikipedia.org/wiki/Combination

*/


//***************************************************************************************************************************
//CABEÇALHO
#if !defined COMBINATION_H
#define COMBINATION_H
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
#include<cmath>

//***************************************************************************************************************************
//VARIÁVEIS GLOBAIS
const int prime_seed[] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

//***************************************************************************************************************************
//CLASSES
//Classe de elementos
template<typename T>
struct element{
T value;
int index;
              };


//Classe de combinações em um elemento
template<typename T>
class combinations{
public:
//Membros
int hash_value;
int set_size, combination_size;
int shift_index;
std::vector<int> hash_vector;
std::vector<element<T>> set_vector;
std::vector<element<T>> shifted_set_vector;
std::vector<element<T>> combination_vector;
//Métodos da classe
void setup();//Função que recebe input do usuário
void shift_set();//Função que realiza um shift do conjunto a ser permutado
void generate_combinations();//Função que gera índices para transposições
int hash_function();//Função que calcula um valor hash combinações repetidas
void show_combination();//Função que exibe permutações
void run();//Função principal
                  };

//***************************************************************************************************************************
//MÉTODOS DE CLASSE

//Função que recebe input do usuário
template<typename T>
void combinations<T>::setup(){
//Definindo o tamanho do conjunto a ser permutado
std::cout<<"Digite quantos elementos você vai incluir em seu conjunto:\n";
std::cin>>set_size;
//Variáveis locais 
T element_value;
element<T> set_element; 
int i; //Variável de interação

//Recebendo os elementos que compõe o conjunto
for(i = 0; i<set_size; ++i){
std::cout<<"Digite qual elemento será adicionado ao conjunto:\n";
std::cin>>element_value;
set_element.value=element_value;
set_element.index=(prime_seed[i]);
//Elementos repetidos devem ter o mesmo index
for (auto y:set_vector){
if(set_element.value==y.value)
set_element.index = y.index;
                       };

set_vector.push_back(set_element);
                           };

                             };

//Função que translada os elementos de um vetor
template<typename T>
void combinations<T>::shift_set(){
//Ajuste de variável
shifted_set_vector.resize(0);
//Transladando os elementos do vetor
for(int i = 0; i<set_size; ++i)
shifted_set_vector.push_back(set_vector[(i+shift_index)%set_size]);
                                 };

//Função que gera um valor hash para determinar se um combinação foi computada ou não
template<typename T>
int combinations<T>::hash_function(){
//Variáveis locais
int i;
hash_value = 0; 
//Computando o valor hash de uma dada disposição
for(i=0; i<combination_vector.size(); ++i)
hash_value+= combination_vector[i].index;
return hash_value;
                                    };

//Função que checa se uma permutação é repetida
template<typename T>
bool combinations<T>::validate_combination(){
for(auto y:hash_vector){
if(y==hash_value)
return false;//Combinação repetida
                       };
return true;//Nova combinação encontrada
                                            };


//Função que gera combinações dos elementos
template<typename T>
void combinations<T>::generate_combinations(){
//Variáveis locais
int index1, index2;

//Procedimento 
//Iterando sobre possíveis valores do vetor altenado e checando por novas permutações
for(index1 = 0; index1<set_size; ++index1){
for(index2 = index1; index2<set_size; ++index2){
//Testando se a transposição produz novas pemutações que serão usadas para geras as combinações
std::swap(shifted_set_vector[index1], shifted_set_vector[index2]);

//Preenchendo o vetor de combinações
combination_vector.resize(0);

for(int i=0; i<combination_size; ++i)
combination_vector.push_back(shifted_set_vector[i]);

//Checando por combinações repetidas
hash_value=hash_function();
if(validate_combination()==true){
hash_vector.push_back(hash_value);
show_combination();
                                };

std::swap(shifted_set_vector[index1], shifted_set_vector[index2]);//Retornando a configuração inicial
                                          };
                                          };
                                             };

//Função que exibe uma combinação dos elementos
template<typename T>
void combinations<T>::show_combination(){
std::cout<<"{";
for(auto y:combination_vector)
std::cout<<y.value<<",";
std::cout<<"}\n";
                                        };


//Função principal
template<typename T>
void combinations<T>::run(){
//Ajuste de Variáveis
int trial_run=1;
shift_index=0;
setup();
//Definindo o tamanho das combinações
std::cout<<"Digite quantos elementos você vai incluir em cada combinação:\n";
std::cin>>combination_size;
//Loop principal
mainloop:
for(int i=0; i<=set_size; ++i){
shift_set();
generate_combinations();
++shift_index;
                              };

//Checando por novas permutações
if(trial_run<2){
std::reverse(set_vector.begin(), set_vector.end());
trial_run++;
goto mainloop;
               };

                           };

//***************************************************************************************************************************
//FIM DO HEADER
#endif
