//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO modular_binomial_coefficient.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o modular_binomial_coefficient modular_binomial_coefficient.cpp -O2


//Cabeçalho
#include"modular_binomial_coefficient.hpp"
#include<vector>
#include<iostream>
using namespace std;

//Função principal
int main(){
//Variáveis locais
vector<uint64_t> factors, digits;
uint64_t n, k, m, base;

//Procedimentos
//Recebendo input do usuário
cout<<"Digite um inteiro: ";
cin>>n;
cout<<"Digite um inteiro: ";
cin>>k;
cout<<"Digite um inteiro: ";
cin>>m;
cout<<"Digite um inteiro: ";
cin>>base;

//Teste 1: fatoração
factorize(factors, n);
for(auto x:factors)
cout<< x<<" ";
cout<<'\n';

//Teste 2: expansão em uma base
expand_in_base(digits, n, base);
for(auto y:digits)
cout<< y<<" ";
cout<<'\n';

//Teste 3: cálculo de coeficientes binomiais modulares usando abordagens elementares
cout<<"C("<<n<<","<<k<<") mod "<<m<<" = "<<binomial_modular_coefficient1(n, k, m)<<'\n'; 

//Teste 4: cálculo de coeficientes binomiais modulares usando o pequeno teorema de Fermat
cout<<"C("<<n<<","<<k<<") mod 211 = "<<binomial_modular_coefficient2(n, k, 211)<<'\n'; 

//Teste 5: cálculo de coeficientes binomiais modulares usando o pequeno teorema de Fermat e o teorema de Lucas
cout<<"C(1578, 754) mod 103 = "<<binomial_modular_coefficient3(1758, 754, 103)<<'\n'; 

//Finalizando a aplicação
return 0;
          }
