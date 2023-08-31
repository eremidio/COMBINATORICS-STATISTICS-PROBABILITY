 //Vamos criar um programa para testar o módulo mergesort

/*Cabeçalho com arquivos mestres e namespaces usados*/
#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include"mergesort.hpp"
using namespace std;

int main(){
//Semente para geração de números aleatórios
srand(time(NULL));

//Definição de variáveis
int n, i;
cout<<"Digite quantos elementos você incluirá no array: ";
cin>>n;

//Definindo o array
int * lista;
lista=new int[n];

//Definindo elementos no array
for(i=0; i<n; i++)
lista[i]=rand()%100000;
                 

//Exibindo elementos não ordenados
//for(i=0; i<n; i++)
//cout<<"lista["<<i<<"]= "<< lista[i]<< endl;

//Ordenando elementos no array
mergesort::mergesort<int>(lista, 0, (n-1));

//Exibindo elementos ordenados
for(i=0; i<n; i++)
cout<<"lista["<<i<<"]= "<< lista[i]<< endl;
//Limpando o cachê de memória
delete []lista;
return 0;
           }
  
