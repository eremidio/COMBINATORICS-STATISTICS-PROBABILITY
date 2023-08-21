//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO steinhaus_johnson_trotter.hpp
//CONMPILAR ESTE PROGRAMA COM O COMANDO:  g++ -o steinhaus_johnson_trotter steinhaus_johnson_trotter.cpp


//Cabeçalho
#include"steinhaus_johnson_trotter.hpp" 

//Função principal
int main(){
//Instanciando um objeto da classe eexecutando o algoritmo
steinhaus_johnson_trotter permutator;
permutator.run();
//Finalizando o programa
return 0;
          }
