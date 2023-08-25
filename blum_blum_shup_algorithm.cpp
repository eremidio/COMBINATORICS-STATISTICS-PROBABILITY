//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO blum_blum_shup_algorithm.hpp
//COMPILAR ESTE PROGRAMA COM O ARQUIVO: g++ -o blum_blum_shup_algorithm blum_blum_shup_algorithm.cpp


//Cabeçalho
#include"blum_blum_shup_algorithm.hpp"
#include<iostream>
using namespace std;

//Função principal
int main(){
//Executando o algoritmo 
cout<<"String binária de 100 dígitos:\n";
blum_blum_shub(100);
cout<<"String binária de 500 dígitos:\n";
blum_blum_shub(500);
cout<<"String binária de 2000 dígitos:\n";
blum_blum_shub(2000);

//Finalizando a aplicação
return 0;
          }
