//PROGRAMA QUE USA A BIBLIOTECA boost PARA CALCULAR O TRIANGULO DE PASCAL
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o pascal_triangle pascal_triangle.cpp

//Cabeçalho
#include<iostream>
#include<stdint.h>
#include<vector>
using namespace std;

//Calculando a n-ésima linha do trângulo de Pascal, usando recursão a n-ésima linh será obtida a partirda (n-1)-ésima linha
vector<uint64_t>get_nth_line(uint64_t n){
//Variáveis locais
vector<uint64_t> current_line;
//Adicionandoo primeiro elemento da linha atual
current_line.push_back(1);

//Caso base
if(n==0)
return current_line;

//Definindo os demais elementos recursivamente
vector<uint64_t> previous_line = get_nth_line(n - 1);

for (uint64_t i = 1; i < previous_line.size(); ++i)
current_line.push_back(previous_line[i] + previous_line[i - 1]);

// Adicionando o último elemento da linha atual
current_line.push_back(1);

//Resultado
return current_line;
                                        };

//Função que printa uma linha do triângulo de Pascal
void print_line(vector<uint64_t> line){
for(auto y:line)
cout<<y<<" ";
cout<<"\n";
                                      };

//Função principal
int main(){
//Variáveis locais
uint64_t line_number, i;
vector<uint64_t> line;
//Procedimentos
//Recebendo input do usuário
cout<<"Digite quantas linhas do triângulo de pascal você deseja exibir: ";
cin>>line_number;
//Printando o triângulo de pascal na tela
for(i=0; i<line_number; ++i){
line=get_nth_line(i);
print_line(line);
                            };

//Finalizando a aplicação
return 0;
          }
