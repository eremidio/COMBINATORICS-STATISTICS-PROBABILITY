//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO mersenne_twister.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o mersenne_twister mersenne_twister.cpp


//Cabeçalho
#include"mersenne_twister.hpp"


//Função principal
int main(){
//Instanciando um objeto da classe
mersenne_twister generator;
//Executando o algoritmo
generator.run();
//Finalizando a aplicação
return 0;
          }
