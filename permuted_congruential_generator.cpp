//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO:  permuted_congruential_generator.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o permuted_congruential_generator permuted_congruential_generator.cpp


//Cabeçalho
#include"permuted_congruential_generator.hpp"
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;


//Função principal
int main(){
//Variáveis locais
uint64_t state, increment, multiplier, seed, maximum;
uint32_t random;
fstream file_record;
string filename;
//Procedimentos
//Recebendo input do usuário
cout<<"Digite o nome do arquivo no qual serão registrados os resultados do experimento: ";
cin>>filename;
filename+=".txt";
    //Abrindo o arquivo para resgistrar os dados
    file_record.open(filename, ios::in|ios::out|ios::app);
    if(file_record.is_open()==false){
    cout<<"Erro ao abrir arquivos para registro de dados!";
    exit(0);
                                    };
cout<<"Digite quantos números você vai gerar neste experimento: ";
cin>>maximum;
cout<<"Digite uma semente inicial para geração de números aleatórios: ";
cin>>seed;
cout<<"Digite o valor do incremento usado para geração de números aleatórios: ";
cin>>increment;
cout<<"Digite o valor do fator multiplicativo usado para geração de números aleatórios: ";
cin>>multiplier;

//Loop principal
for(uint64_t i=0; i<maximum; ++i){
state=seed+increment;
random = pcg_algorithm(state, multiplier, increment);
file_record<<random<<'\n';
seed = ((random*random)%9878789665631321)-time(NULL);
                                 };

   


//Finalizando a aplicação
file_record.close();
return 0;
          }
