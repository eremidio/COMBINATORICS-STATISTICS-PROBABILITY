//VAMOS CRIAR PROGRAMA QUE TESTA AS ROTINAS QUE CALCULAM AS PERMUTAÇÕES EM UM DADO CONJUNTO CRIADAS NO ARQUIVO permutations.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o random_permutations random_permutations.cpp

//Cabeçalho
#include<iostream>
#include"random_permutations.hpp"
using namespace std;

//Função principal
int main(){
//Inicializando um objeto da classe de permutações
permutations<int> trial;
//Computando as permutações
trial.run();

//Finalizando a aplicação
return 0;
          };
