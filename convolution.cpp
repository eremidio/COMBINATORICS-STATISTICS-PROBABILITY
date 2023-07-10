//VAMOS CRIAR UMA FUNÇÃO QUE CALCULA CONVOLUÇÃO  de dois conjuntos
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o convolution convolution.cpp

//Cabeçalho
#include<iostream>
#include<vector>
#include"convolution.hpp"
using namespace std;


//Função principal
int main(){
//Inicializando vetores de inteiros
vector<double> a={2,2};
vector<double> b={0.5,0.5};
vector<double> c=convolution<double>(a, b);

//Exibindo os resultados
cout<<"a = ";
print_vector<double>(a);
cout<<"b = ";
print_vector<double>(b);
cout<<"c= a*b = ";
print_vector<double>(c);

//Finalizando a aplicação
return 0;
          }
