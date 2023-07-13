//VAMOS CRIAR UM AQRUIVO QUE IMPLMENTA UMA ROTINA PARA CALCULAR PERMUTAÇÕES EM UM CONJUNTO

//***************************************************************************************************************************
//CABEÇALHO
#if !defined PERMUTATION_H1
#define PERMUTATION_H1
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>

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


//Classe de permutações em um elemento
template<typename T>
class permutations{
public:
//Membros
int hash_value;
int set_size;
int shift_index;
std::vector<int> hash_vector;
std::vector<element<T>> set_vector;
std::vector<element<T>> shifted_set_vector;

//Métodos da classe
void setup();//Função que recebe input do usuário
void shift_set();//Função que realiza um shift do conjunto a ser permutado
void generate_permutations();//Função que gera índices para transposições
int hash_function();//Função que calcula um valor hash para cada permutação
bool validate_permutation();//Função que detecta permitações repetidas
void show_permutation();//Função que exibe permutações
void run();//Função principal

                  };

//***************************************************************************************************************************
//MÉTODOS DE CLASSE

//Função que recebe input do usuário
template<typename T>
void permutations<T>::setup(){
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
set_vector.push_back(set_element);
                       };
                           };

//Função que translada os elementos de um vetor
template<typename T>
void permutations<T>::shift_set(){
//Ajuste de variável
shifted_set_vector.resize(0);
//Transladando os elementos do vetor
for(int i = 0; i<set_size; ++i)
shifted_set_vector.push_back(set_vector[(i+shift_index)%set_size]);
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
hash_value+=(prime_seed[i]+1)*(shifted_set_vector[i].index*shifted_set_vector[i].index*shifted_set_vector[i].index+shifted_set_vector[i].index);
if((i%2)==1)
hash_value-= (prime_seed[i]+1)*(shifted_set_vector[i].index*shifted_set_vector[i].index*shifted_set_vector[i].index+shifted_set_vector[i].index);

                                  };
return hash_value;
                                    };

//Função que checa se uma permutação é repetida
template<typename T>
bool permutations<T>::validate_permutation(){
for(auto y:hash_vector){
if(y==hash_value)
return false;//Permutação repetida
                       };
return true;//Nova permutação encontrada
                                            };


//Função que exibe uma permutação dos elementos
template<typename T>
void permutations<T>::show_permutation(){
std::cout<<"{";
for(auto y:shifted_set_vector)
std::cout<<y.value<<",";
std::cout<<"}\n";
                                        };

//Função que gera permutações dos elementos
template<typename T>
void permutations<T>::generate_permutations(){
//Variáveis locais
int index1, index2;

//Procedimento 
//Iterando sobre possíveis valores do vetor altenado e checando por novas permutações
for(index1 = 0; index1<set_size; ++index1){
for(index2 = index1; index2<set_size; ++index2){
//Testando se a transposição produz novas pemutações
std::swap(shifted_set_vector[index1], shifted_set_vector[index2]);
hash_value=hash_function();
if(validate_permutation()==true){
hash_vector.push_back(hash_value);
show_permutation();
                                };

std::swap(shifted_set_vector[index1], shifted_set_vector[index2]);//Retornando a configuração inicial
                                          };
                                          };
                                             };

//Função principal
template<typename T>
void permutations<T>::run(){
//Ajuste de Variáveis
int trial_run=1;
shift_index=0;
setup();
//Loop principal
mainloop:
for(int i=0; i<=set_size; ++i){
shift_set();
generate_permutations();
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
