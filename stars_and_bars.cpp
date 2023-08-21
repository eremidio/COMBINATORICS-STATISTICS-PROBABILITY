//VAMOS CRIAR UM PROGRAMA EM C++ QUE IMPLEMENTA O ALGORITMO STARS AND BARS, DIUSTRBUINDO N BOLAS EM 5 CAIXAS
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o stars_and_bars stars_and_bars.cpp


//*************************************************************************************************************************
//CABEÇALHO
#include<iostream>
using namespace std;


//*************************************************************************************************************************
//FUNÇÕES
//Função que implementa o algoritmo de sdistribuição de n bolas em k caixas usando recursão
void stars_and_bars(int n, int k){
//Caso trivial apenas uma caixa
if(k==1)
cout<<"Caixa: 1 -- "<<n <<" bolas.\n";
cout<<"----------------------------------------\n";

//Caso geral:
if(k>1){
//Variáveis locais
int i;
//Loop principal
for(int i = 1; i<=n; i++){

//Distribuindo as n bolas em k caixas com chamadas recursivas da função
cout<<"Caixa : "<< k<<" -- "<< i<<" bolas.\n";
//Chamada recursiva da função
stars_and_bars((n-i), (k-1));
                         };

       };
                                         };

//*************************************************************************************************************************
//FUNÇÃO PRINCIPAL
int main(){
//Variáveis locais
int balls, boxes;
//Procedimentos
//Recebendo input do usuário
cout<<"Digite o número de bolas: ";
cin>>balls;
cout<<"Digite o número de caixas: ";
cin>>boxes;
//Executando o algoritmo
stars_and_bars(balls, boxes);

//Finalizando a aplicação
return 0;
          }

