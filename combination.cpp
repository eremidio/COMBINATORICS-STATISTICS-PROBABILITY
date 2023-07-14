//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO combination.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o combination combination.cpp

//Cabeçalho
#include<iostream>
#include"combination.hpp"
using namespace std;

//Função principal
int main(){
//Inicializando um objeto da classe de permutações
combinations<char> trial1;
//Computando as permutações
trial1.run();
//Finalizando a aplicação
return 0;
          };
