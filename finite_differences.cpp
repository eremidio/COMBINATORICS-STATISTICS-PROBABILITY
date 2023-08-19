//VAMOS IMPLEMENTAR UM PROGRAMA QUE CALCULA DIFERENÇAS FINITAS DA FUNÇÃO f(x)=x^n
//COMPILAR ESTE PROGRAMA COM COMANDO: g++ -o finite_differences finite_differences.cpp

/*
DADA UMA FUNÇÃO f(x) COM DOMÍNIO NOS REAIS E DADO UM INTERVALO DE COMPRIMENTO n EM SEU DOMÍNIO. A DIFERENÇA FINITA DESTA FUNÇÃO
É DEFINIDA COMO Δf(x)=[f(x+n)-f(x)]/n. O CASO DA DERIVADA NO CONTINUO CORRESPONDE AO LIMITE n-->0.

DIFERENÇAS FINITAS FORNCEM O VALOR EXATO DA DERIVADA DE UMA FUNÇÃO POLINOMIAL, QUE CORRESPONDE AO TERMO INDEPENDENTE DE n.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Finite_difference


*/

//****************************************************************************************************************************
//CABEÇALHO
#include<vector>
#include<iostream>
#include<cmath>
#include<stdint.h>
using namespace std;


//****************************************************************************************************************************
//FUNÇÕES
//Função que calcula diferenças finitas
vector<uint64_t> finite_difference(vector<uint64_t> previous){

//Variáveis locais
vector<uint64_t> result;

//Procedimentos
result.resize(0);

for(int i=1; i<previous.size(); ++i)
result.push_back(previous[i]-previous[i-1]);

return result;
                                                             };

//Função que inicializa um vetor de inteiros a uma dada potência
vector<uint64_t> initialize(int n){
//Variáveis locais
vector<uint64_t> result;

//Procedimentos
result.resize(0);

for(int i=1; i<(n*2); i++)
result.push_back(pow(i, n));

return result;
                                  };

///Função que printa um vetor de inteiros
void print(vector<uint64_t> array){
for(auto y:array)
cout<<y<<" ";
cout<<"\n";
                                  };


//****************************************************************************************************************************
//FUNÇÃO PRINCIPAL
int main(){
//Variáveis locais
vector<uint64_t> previous, next;
uint64_t n, i;

//Procedimentos
//Recebendo input do usuário
cout<<"Digite um número inteiro: ";
cin>>n;
//Inicializando um array de inteiros
previous=initialize(n);
//Loop principal
for(i=0; i<=n; ++i){
print(previous);
next.resize(0);
next=finite_difference(previous);


//Atualizando variáveis para a próxima iteração
previous.swap(next);
                   };

//Finalizando a  aplicação
return 0;
          }
