//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS RORINAS CRIADAS NO ARQUIVO set_partition.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o set_partition set_partition.cpp -fpermissive

//Cabeçalho
#include"set_partition.hpp"

//Função principal
int main(){
//Instanciando um objeto da classe e executando o algoritmo
set_partition<char> my_test;
my_test.run();

//TESTES USE UM // APÓS O MESMO
//my_test.set_bit_vector(7);
//my_test.print_subset(6);
//Finalizando a aplicação
return 0;

          }
