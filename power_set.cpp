//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS SUBROTINAS DEFINIDAS NO HEADER power_set.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o power_set power_set.cpp

//Cabeçalho
#include<iostream>
#include"power_set.hpp"
using namespace std;

//Função principal
int main(){
//Inicializando um objeto da classe de permutações
power_set_class<char> trial;
//Computando as permutações
trial.run();

//Finalizando a aplicação
return 0;
          };



