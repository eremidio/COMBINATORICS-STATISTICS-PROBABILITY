//VAMOS CRIAR UM PROGRAMA QUE IMPLMENTAUM ALGORITMO QUE GERA AS PERMUTAÇÕES EM UM DADO CONJUNTO

/*
DADO UM CONJUNTO COM n ELEMENTOS EXISTEM AO TODO n! PERMUTAÇÕES (DIFERENTES DISPOSIÇÕES) DESTES ELEMENTOS CASO NÃO HAJA ELEMENTOS REPETIDOS.

EM CASO DE REPETIÇÕES O RESULTADO FINAL É DIVIDIDO PELO FATORIAL DO NÚMERO DE REPETIÇÕES DOS ELEMENTOS.

NO PRESENTE ALGORITMO USAREMOS HASHING  E UM GERADOR DE NÚMEROS ALEATÓRIOS.
*/

//**************************************************************************************************************************
//CABEÇALHO
#ifndef PERMUTATION_H
#define PERMUTATION_H
#include<vector>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<algorithm>
#include<iostream>


//***************************************************************************************************************************
//FUNÇÕES AUXILIARES
//Fatorial
int factorial(int n){
if(n==1 || n==0)
return 1;
else
return n*factorial(n-1);
                    };

//**************************************************************************************************************************
//CLASSE
//Estrutura contendo um elemento e um index associado
template<typename T>
struct element{
public:
T value;
int index;
              };

//Classe contendo a classe de permutações
template<typename T>
class permutations{
public:
//Membros da classe
int set_size;
int hash_value;
int attempts;
int total_permutations;
std::vector<element<T>> set_vector;
std::vector<int> hash_vector;

//Métodos da classe
void setup();//Função que recebe input do usuário
void generate_permutations();//Função que gera índices para transposições
int hash_function();//Função que calcula um valor hash para cada permutação
void show_permutation();//Função que exibe permutações
void run();//Função principal
                  };

//**************************************************************************************************************************
//MÉTODOS DA CLASSE
template<typename T>
void permutations<T>::setup(){
//Definindo o tamanho do conjunto a ser permutado
std::cout<<"Digite quantos elementos você vai incluir em seu conjunto:\n";
std::cin>>set_size;
//Variáveis locais 
int element_index=1;
T element_value;
element<T> set_elements; 
int i; //Variável de interação

//Recebendo os elementos que compõe o conjunto
for(i = 0; i<set_size; ++i){
std::cout<<"Digite qual elemento será adicionado ao conjunto:\n";
std::cin>>element_value;
set_elements.value=element_value;
set_elements.index=element_index;
set_vector.push_back(set_elements);
element_index++;
                       };
                           };


//Função que gera uma permutação de elementos
template<typename T>
void permutations<T>::generate_permutations(){
//Semente para geração de números aleatórios
srand(time(NULL));
//Variáveis locais
int index1, index2;
//Procedimentos
//Gerando uma transposição aleatoriamente
transpose:
index1=rand()%set_size;
index2=rand()%set_size;
if(index2==index1)
index2=(index2+1)%set_size;

std::swap(set_vector[index1], set_vector[index2]);

//Checando se a tranposição gerada é válida
hash_value=hash_function();
for(auto y:hash_vector){
//Permutação repetida
if(y==hash_value){
attempts++;
if(attempts>(total_permutations*10))
return;

goto transpose;
                 };
                       };

//Caso uma permutação tenha sido encontrada
hash_vector.push_back(hash_value);
show_permutation();


                                             };

//Função que gera um valor hash para determinar se um permutação foi computada ou não
template<typename T>
int permutations<T>::hash_function(){
//Variáveis locais
int i;
hash_value = 0; 
//Computando o valor hash de uma dada disposição
for(i=0; i<set_vector.size(); ++i){
if((i%2)==0)
hash_value+=(i+1)*(set_vector[i].index*set_vector[i].index*set_vector[i].index+set_vector[i].index);
if((i%2)==1)
hash_value-=(i+1)*(set_vector[i].index*set_vector[i].index*set_vector[i].index+set_vector[i].index);

                                  };
return hash_value;
                                    };


//Função que exibe uma permutação dos elementos
template<typename T>
void permutations<T>::show_permutation(){
std::cout<<"{";
for(auto y:set_vector)
std::cout<<y.value<<",";
std::cout<<"}\n";
                                        };

//Função principal
template<typename T>
void permutations<T>::run(){
//Recebendo input do usuário
setup();
//Determinado o número de permutaçoẽs total
total_permutations=factorial(set_size);
attempts=0;
//Adicionando o primeiro elemento a permutação (transformação identidade)
hash_value=hash_function();
hash_vector.push_back(hash_value);
show_permutation();
total_permutations--;

//Loop principal
while(total_permutations>0){
generate_permutations();
total_permutations--;
if(attempts==(total_permutations*10))
return;
                           };

                           };
//**************************************************************************************************************************
//FIM DO HEADER
#endif
