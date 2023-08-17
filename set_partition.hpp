//VAMOS CRIAR UMA RORINA QUE GERA PARTIÇÕES DE UM CONJUNTO 

//***********************************************************************************************************************,
//CABEÇALHO
#ifndef SET_PARTITION_H
#define SET_PARTITION_H
#include<vector>
#include<cmath>
#include<stdint.h>
#include<iostream>
#include<algorithm>
#include<utility>


//***********************************************************************************************************************,
//CLASSE COM O ALGORITMO DE PARTIÇÃO DE UM CONJUNTO
template<typename T>
class set_partition{
public:
//Membros da classe
std::vector<T> basic_set;
std::vector<int> bit_vector;
int64_t set_size;
int64_t index_array[50];
int64_t lead_index;

//Métodos da classe
void run();//Função principal
void setup();//Função que recebe input do usuário
void set_indexes();//Função que ajusta um array de inteiros usados no algoritmo
void set_bit_vector(int64_t);//Função que converte um inteiro em um vetor de bits
void print_subset(int64_t);//Função que printa um subconjunto de uma partição
void update_indexes(); //Função qua atualiza os arrays de indexes

                   };

//***********************************************************************************************************************,
//MÉTODOS DA CLASSE
//Função principal
template<typename T>
void set_partition<T>::run(){
//Recebendo input do usuário
setup();
//Ajustando o array de inteiros
set_indexes();

//Loop principal
while(index_array[1]>0){
//Printando uma partição na tela
for(auto x:index_array){
if(x>0)
print_subset(x);
                       };
std::cout<<"\n";

//Atualizando o index de inteiros
update_indexes();
                       };

print_subset(index_array[0]);
std::cout<<"\n";

                            };

//Função que recebe input do usuário
template<typename T>
void set_partition<T>::setup(){
//Variáveis locais
T element;
//Procedimentos
//Recebendo input do usuário
std::cout<<"Quantos elementos você inserir no seu conjunto: ";
std::cin>>set_size;

basic_set.resize(0);

for(int64_t i=0; i<set_size; ++i){
std::cout<<"Digite o "<<(1+i)<<"º do elemento do conjunto:\n";
std::cin>>element;
basic_set.push_back(element);
                                 };


//TESTE, USE UM //APÓS O MESMO
//for(auto y:basic_set)
//std::cout<<y<<" ";
//std::cout<<"\n";

                              };


//Função que ajusta um array de inteiros usados no algoritmo
template<typename T>
void set_partition<T>::set_indexes(){
//Ajustandos os elementos do array em 0
for(int j=0; j<50; j++)
index_array[j]=0;

//Variáveis locais
int64_t power2=static_cast<int64_t>(std::pow(2, (set_size-1)));
int i=0;
//Procedimentos
while(power2>=1){
index_array[i]=power2;
++i;
power2/=2;
                };


//TESTE, USE UM //APÓS O MESMO
//for(auto y:index_array)
//std::cout<<y<<" ";
//std::cout<<"\n";
                                   };

//Função que converte um inteiro em um vetor de bits
template<typename T>
void set_partition<T>::set_bit_vector(int64_t n){
//Ajuste de vetores de bits
bit_vector.resize(0);
//Adicionando os bits ao vetor de bits
while(n>0){
//Testando a paridade do último bit
if(n&1)
bit_vector.push_back(1);
else
bit_vector.push_back(0);

//Atualizando a variável;
n>>=1;
          };

//Completando o array de bits com zeros
while(bit_vector.size()<set_size)
bit_vector.push_back(0);

//Reveterndo a string the bits
std::reverse(bit_vector.begin(), bit_vector.end());
                                                };


//Função que printa um subconjunto de uma partição
template<typename T>
void set_partition<T>::print_subset(int64_t n){
//Ajustando o array de bits 
set_bit_vector(n);

//Printando elementos do vetor na tela
std::cout<<"{";
for(int i=0; i<set_size; ++i)
if(bit_vector[i]==1)
std::cout<<basic_set[i]<<",";
std::cout<<"} ";
                                              };

//Função qua atualiza os arrays de indexes
template<typename T>
void set_partition<T>::update_indexes(){
//Encontrando o último index não nulo no array de inteiros
for(int64_t i=49; i>=0; --i){
if(index_array[i]==0)
continue;

if(index_array[i]>0)
lead_index=i;
break;
                            };
if(lead_index ==0)
return;

//Variáveis locais
int64_t temp1 = index_array[lead_index];
int64_t temp2 = index_array[lead_index-1];

//Atualizando o array de indexes
index_array[lead_index]=(temp1-1);
index_array[lead_index-1] = (temp2+1);

//TESTE, USE UM //APÓS O MESMO
//for(auto y:index_array)
//std::cout<<y<<" ";
//std::cout<<"\n";
                                       }; 



//***********************************************************************************************************************,
//FIM DO HEADER
#endif
