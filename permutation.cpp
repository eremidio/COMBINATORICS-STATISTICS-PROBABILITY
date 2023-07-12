//PROGRAMA PARA TESTAR AS ROTINAS DEFINIDAS NO ARQUIVO permutation.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o permutation permutation.cpp


//VAMOS CRIAR PROGRAMA QUE TESTA AS ROTINAS QUE CALCULAM AS PERMUTAÇÕES EM UM DADO CONJUNTO CRIADAS NO ARQUIVO permutations.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o permutation permutation.cpp

//Cabeçalho
#include<iostream>
#include"permutation.hpp"
using namespace std;

//Função principal
int main(){
//Inicializando um objeto da classe de permutações
permutations<char> trial;
//Computando as permutações
trial.run();

//Finalizando a aplicação
return 0;
          };
