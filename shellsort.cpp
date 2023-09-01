//Vamos criar um programa para testar o módulo shellsort

/*Cabeçalho com arquivos mestres e namespaces usados*/
#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include"shellsort.hpp"
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
lista[i]=rand()%1000;
                 

//Exibindo elementos não ordenados
//for(i=0; i<n; i++)
//cout<<"lista["<<i<<"]= "<< lista[i]<< endl;

//Ordenando elementos no array
shellsort::shellsort<int>(lista, n);

//Exibindo elementos ordenados
for(i=0; i<n; i++)
cout<<"lista["<<i<<"]= "<< lista[i]<< endl;
//Limpando o cachê de memória
delete []lista;
return 0;
}
