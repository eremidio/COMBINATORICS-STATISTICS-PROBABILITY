//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO binary_search.hpp
//COMPILAR ESTE PROGRAMA COM: g++ -o binary_search binary_search.cpp    


//Cabeçalho
#include"quicksort.hpp"
#include"binary_search.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//Função principal
int main(){
//Semente para geração de números aleatórios
srand(time(NULL));

//Definição de variáveis
int n, i, alvo;
cout<<"Digite quantos elementos você incluirá na lista de inteiros gerados aleatoriamente: ";
cin>>n;

//Definindo o array
int * lista;
lista=new int[n];

//Definindo elementos no array
for(i=0; i<n; i++){
lista[i]=rand()%15000;

//TESTE USE UM // APÓS O MESMO
//cout<<lista[i]<<" ";
//if(i==(n-1))
//cout<<'\n';
                  };
//Ordenando elementos no array
quicksort::quicksort<int>(lista, 0, (n-1));

//Checando se um elemento em específico está lista
cout<<"Digite um valor para checar se ele está incluso na lista: ";
cin>>alvo;

bool checking=binary_search<int>(lista, alvo, n);
if(checking==true)
cout<<"Valor encontrado na lista!\n";
else
cout<<"Valor não encontrado na lista!\n";

//Finalizando a aplicação
delete[] lista;
return 0;
          }
