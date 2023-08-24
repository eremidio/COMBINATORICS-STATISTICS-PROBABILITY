//VAMOS CRIAR UM PROGRAMA QUE TESTAS ROTINAS CRIADAS NO ARQUIVO linear_congruence_generator.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o linear_congruence_generator linear_congruence_generator.cpp

//Cabeçalho
#include<iostream>
#include"linear_congruence_generator.hpp"
using namespace std;


//Função principal
int main(){ 
//Executandos os algoritmo de geração de string binária
cout<<"\nMétodo dos Geradores de Congruência Linear\n";
lcg_algorithm();
cout<<"\nVariante de Lehmer\n";
lcg_lehmer_variant();

//Finalizando 
return 0;
          };



