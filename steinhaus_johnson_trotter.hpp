//VAMOS IMPLEMENTAR O ALGORITMO DE STEINHAUS-JOHNSON-TROTTER PARA GERA PERMUTAÇÕES DE UM CONJUNTO

/*
PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Steinhaus–Johnson–Trotter_algorithm
                          https://www.geeksforgeeks.org/johnson-trotter-algorithm/

*/ 

//*****************************************************************************************************************
//CABEÇALHO
#ifndef STEINHAUS_JOHNSON_TROTTER_H
#define STEINHAUS_JOHNSON_TROTTER_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>


//*****************************************************************************************************************
//FUNÇÕES AUXILIARES
//Função que calcula o fatorial de um número
int factorial(int n){
//Variáveis locais
int result=1;
//Procedimentos
for(int i=2; i<=n; ++i)
result*=i;

return result;
                    };
//*****************************************************************************************************************
//CLASSE DO ALGORITMO
class steinhaus_johnson_trotter{
public:
//Membros da classe
std::vector<int> basic_set;
int biggest_index, shift_index1, shift_index2;
bool left_to_right;
int n, biggest, indexer1, indexer2;
int permutation_number;

//Métodos da classe
void run();//Função principal
void setup();//Função que recebe input do usuário e ajusta variáveis em seus valores iniciais
void print_permutation();//Função que printa uma permutação
void generate_permutations();//Função que gera permutações usando o algorimo de Steinhaus_Johnson_Trotter

                               };

//*****************************************************************************************************************
//MÉTODOS DA CLASSE
void steinhaus_johnson_trotter::run(){
//Recebendo input do usuário e ajustando variáveis
setup();
//Executando o algoritmo de Steinhaus_Johnson_Trotter
generate_permutations();
                                     };

//Função que recebe input do usuário e ajusta variáveis em seus valores iniciais
void steinhaus_johnson_trotter::setup(){
//Recebendo input do usuário
std::cout<<"Digite quantos elementos terá nos eu conjunto: ";
std::cin>>n;
//Ajuste de variáveis
biggest = (n-1);
biggest_index = (n-1);
shift_index1 = 0;
shift_index2 = 0;
indexer1=0;
indexer2=1;
left_to_right = false;
permutation_number=factorial(n);

basic_set.resize(0);
for(int i = 0; i<n; ++i)
basic_set.push_back(i);

//Printando a primeira permutação
print_permutation();

                                       };

//Função que printa uma permutação do conjunto
void steinhaus_johnson_trotter::print_permutation(){
std::cout<<"{";
for(auto y:basic_set)
std::cout<<y<<" ";
std::cout<<"}\n";

                                                   };

//Função que gera permutações usando o algorimo de Steinhaus_Johnson_Trotter
void steinhaus_johnson_trotter::generate_permutations(){
//Variáveis locais
int control = 1;
int i, j;

//Prcedimentos
//Loop principal
while(control<permutation_number){
//Permutando o maior elemento para a esquerda
if(left_to_right==false){
while(biggest_index>=0){
std::swap(basic_set[biggest_index], basic_set[biggest_index-1]);
print_permutation();
control++;
//Checando se todas permutações foram geradas
if(control==permutation_number)
return;
else{
biggest_index--;
if(biggest_index==0){
left_to_right=true;
break;
                    };
    };
                      };
                        };

//Permutando elementos no conjunto
for(i=0; i<basic_set.size(); ++i){
if(basic_set[i]==indexer1)
shift_index1=i;
if(basic_set[i]==indexer2){
shift_index2=i;
break;
                               };
                                 };

//Gerando nova permutação
std::swap(basic_set[shift_index1], basic_set[shift_index2]);
print_permutation();
control++;
//Checando se todas permutações foram geradas
if(control==permutation_number)
return;

//Atualizando variáveis
indexer1=(indexer1+1)%n;
indexer2=(indexer2+1)%n;

//Permutando o maior elemento para a esquerda
if(left_to_right==true){
while(biggest_index<0){
std::swap(basic_set[biggest_index], basic_set[biggest_index+1]);
print_permutation();
control++;
//Checando se todas permutações foram geradas
if(control==permutation_number)
return;
else{
biggest_index++;
if(biggest_index==(n-1)){
left_to_right=false;
break;
                    };
    };
                      };
                       };

//Permutando elementos no conjunto
for(i=0; i<basic_set.size(); ++i){
if(basic_set[i]==indexer1)
shift_index1=i;
if(basic_set[i]==indexer2){
shift_index2=i;
break;
                               };
                                 };

//Gerando nova permutação
std::swap(basic_set[shift_index1], basic_set[shift_index2]);
print_permutation();
control++;
//Checando se todas permutações foram geradas
if(control==permutation_number)
return;

//Atualizando variáveis
indexer1=(indexer1+1)%n;
indexer2=(indexer2+1)%n;
                                 };
                                                       };

//*****************************************************************************************************************
//FIM DO HEADER
#endif
