//VAMOS CALCULAR O VALOR DE PI USANDO UMA INTEGRAÇÃO PELO MÉTODO DE MONTE CARLO EM DUAS DIMENSÕES
//COMPILAR ESTE PROGRAMA COMO COMANDO: g++ -o monte_carlo_integration_3d monte_carlo_integration_3d.cpp

/*
DADO UMA REGIÃO Ω DE VOLUME V. A INTEGRAÇÃO DE MONTE CARLO USA UMA AMOSTRAGEM NO INTERIOR DE Ω PARA ESTIMARO VALOR DE UMA
INTEGRAL DEFINIDA NO INTERIOR DE UMA DADA REGIÃO. O TEOREMA DOS GRANDES NÚMEROS ASSEGURA QUE PAA UM NPUMERO DE PONTOS N 
TENDENDO A INFINITO O VALOR DA INTEGRAL DEFINIDA É APROXIMADAMENTE:
I = (V/M).Σf(x(i)), ONDE x(i) DENOTA UM CONJUNTO DE PONTOS ALEATORIAMENTE SELECIONADOS NO DOMÍNIO DE INTEGRAÇÃO.

ERROS DE DESVIO PADRÃO SÃO DA ORDEM DE N^(1/2).

O MÉTDO DE INTEGRAÇÃO DE MONTE CARLO POSSUI A VANTAGEM DE NÃO NECESSITAR UM NÚMERO SUFICIENTEMENTE GRANDE DE PONTOS PARA
OBTER UMA VALOR RAZOÁVEL. EMBORA ESTIMATIVAS PRECISAS SEJAM MAIS COMPILACADAS DE SEREM ESTIMADAS, UMA VEZ QUE A AMOSTRAGEM
IGNORA ASPECTOS FUNDAMENTAIS DAFUNÇÃO A SER INTEGRADA.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Monte_Carlo_integration

NESTA SIMULAÇÃO VAMOS INTEGRAR A FUNÇÃO:
f(x,y,z)={ 1 se x²+y²+z²<1 ou x²+y²+z²=1
         { 0 caso contrário

A INTEGRAÇÃO SERÁ FEITA NO INTERIOR DE UM CUBO COM x,y,z NO INTERVALO [-1,1]. USAMOS QUE O VOLUME DA ESFERA  EM 3D É DADO POR :
V=(4/3)πR³ ONDE R É O RAIO DA ESFERA, NO CASO R=1, OS CENTROS DO CUBO E DA ESFERA COINCIDEM.
O VOLUME DO CUBO É IGUAL A 2³=8, PORTANTO A RAZÃO ENTRE O VOLUME DO CURBO E DA ESFERA NESTE CASO É π/6. 

*/

//****************************************************************************************************************************
//CABEÇALHO
#include<iostream>
#include<random>
using namespace std;


//****************************************************************************************************************************
//FUNÇÕES
//Função a ser integrada
bool distance(double x, double y, double z){
if( ((x*x)+(y*y)+(z*z)) <=1.0)
return true;
else 
return false;
                                           };

double montecarlo_integration(long long unsigned n){
//Gerador de números aleatórios
default_random_engine generator_x;
mt19937 gen(generator_x());
uniform_real_distribution<double> distribution(-1.0, 1.0);
//Variáveis locais
long long unsigned sphere_points=0;
double x, y, z;
double volume=6.0;
//Procedimentos
//Escolhendo um ponto aleatoriamente no interior do cubo e computando os pontos localizados no interior da esfera
for(long long unsigned i=0; i<n; ++i){
x=distribution(generator_x);
y=distribution(generator_x);
z=distribution(generator_x);

if(distance(x,y,z)==true)
sphere_points++;
                                     };

return (volume/n)*sphere_points;

                                                   };

//****************************************************************************************************************************
//FUNÇÃO PRINCIPAL
int main(){
//Variáveis locais
long long unsigned points;

//Procedimento
//Recebendo inpu do usuário
cout<<"Digite quantos pontos você deseja usar na sua integração: ";
cin>>points;

//Calculando o valor de pi 
cout<<"O valor de π usando "<<points<<" pontos de integração é "<<montecarlo_integration(points)<<"\n";

//Finalizando a aplicação
return 0;
          }
