//VAMOS CRIAR UM PROGRAMA PARA CALCULAR COEFICIENTES BINOMIAIS A MENOS DE UMA CONGRUÊNCIA DE UM PRIMO EM C++ (NOS RESTRINGIREMOS A INTEIROS DE 64-BITS)

/*
PARA REFERÊNCIAS:
https://9to5science.com/n-choose-k-bmod-m-using-chinese-remainder-theorem
https://fishi.devtail.io/weblog/2015/06/25/computing-large-binomial-coefficients-modulo-prime-non-prime/

*/


//*******************************************************************************************************************************************************************
//CABEÇALHO
#ifndef MODULAR_BINOMIAL_COEFFICIENT_H
#define MODULAR_BINOMIAL_COEFFICIENT_H
#include"mod_bin_exponentiation.h" //Inclui os headers <stdint.h>, <inttypes.h> e <stdlib.h>
#include<iostream>
#include<cassert>
#include<vector>
#include<cmath>

//*******************************************************************************************************************************************************************
//DECLARAÇÕES DE FUNÇÕES
void factorize(std::vector<uint64_t>&, uint64_t);
void expand_in_base(std::vector<uint64_t>&, uint64_t, uint64_t);
bool is_prime(uint64_t);
uint64_t binomial_modular_coefficient1(uint64_t, uint64_t, uint64_t);
uint64_t binomial_modular_coefficient2(uint64_t, uint64_t, uint64_t);
uint64_t binomial_modular_coefficient3(uint64_t, uint64_t, uint64_t);

//*******************************************************************************************************************************************************************
//FUNÇÕES
//Função que calcula fatores primos de um inteiro de 64 bits
void factorize(std::vector<uint64_t>& prime_vector, uint64_t n){
//Variáveis locais
uint64_t i;
uint64_t limit=std::sqrt(n);

//Procedimentos
//Ajuste de variáveis
prime_vector.resize(0);

//Cálculo de fatores 2 e 3
while((n%2)==0){
prime_vector.push_back(2);
n/=2;
               };

while((n%3)==0){
prime_vector.push_back(3);
n/=3;
               };

//Cálculo de fatores ímpares usando uma otimização 6k+1
for(i=5; i<=(limit+1); ++i){
while((n%i)==0){
prime_vector.push_back(i);
n/=i;
               };

while((n%(i+2))==0){
prime_vector.push_back((i+2));
n/=(i+2);
                   };


                           };

//Fatores maiores que n^(1/2)
if(n>1)
prime_vector.push_back(n);
                                                               };

//Função que determina a expansão em um número numa dada base
void expand_in_base(std::vector<uint64_t>& digits_vector, uint64_t n, uint64_t base){
//Casos bases
if(n==base){
digits_vector.resize(0);
digits_vector.push_back(1);
digits_vector.push_back(0);
return;
           };

if(n<base){
digits_vector.resize(0);
digits_vector.push_back(n);
return;
          };

//Variáveis locais
uint64_t power_base=1;
uint64_t n_= n;
uint64_t i;

//Procedimentos
//Calculando a menor potência maior que um dado número
while(power_base<n)
power_base*=base;
power_base/=base;

//Ajuste de variáveis
digits_vector.resize(0);

//Cálculo dos dígitos do número numa dada base
while(n_>0){
digits_vector.push_back(n_/power_base);
n_%=power_base;
if(n_==0)
digits_vector.push_back(0);
power_base/=base;
           };
                                                                                    };

//Função que determina se um número é primo ou não
bool is_prime(uint64_t n){
//Casos triviais
if(n<2)
return false;
if(n==2 ||n==3)
return true;

if((n%2)==0 || (n%3)==0)
return false;

//Variáveis locais
uint64_t limit=std::sqrt(n);
uint64_t i;

//Procdimentos 
//Loop principal
for(i=5; i<=(limit+2); ++i){
if((n%i)==0 || (n%(i+2))==0)
return false;
                           };
return true;
                         };

//Função que usa uma abordagem básica adequada para n<100
uint64_t binomial_modular_coefficient1(uint64_t n, uint64_t k, uint64_t m){
//Casos triviais
if(k==0 || k==n)
return 1;
if(k==1 || k==(n-1))
return (n%m);
//Recursão
if(k>(n/2))
return binomial_modular_coefficient1(n, (n-k), m);

//Caso geral: k>1
//Variáveis locais
__int128_t coefficient=n;
uint64_t i=1;

//Procedimentos
for(i=1; i<=k; ++i){
coefficient*=(n-i);
coefficient/=(i+1);
                   };

//Resultado
return (coefficient%m);
                               
                                                                          };

//Função que usa o pequeno teorema de Fermat para congruente primo
uint64_t binomial_modular_coefficient2(uint64_t n, uint64_t k, uint64_t m){
//Variáveis locais
uint64_t numerator=1, denominator, denominator_factorial=1;
uint64_t exponent=(m-2);
uint64_t i;
//Procedimentos
//Cálculo do numerador
for(i=n; i>=(n-k+1); --i)
numerator=mul_mod(numerator, i, m);

//Cálculo do denominador
for(i=2; i<=n; ++i)
denominator_factorial=mul_mod(denominator_factorial, i, m);
denominator=mod_bin_pow(denominator_factorial, exponent, m);

//Rsultado
return numerator*denominator;                         
                                                                          };


//Função que usa o teorema de Lucas para o cálculo envolvendo números grandes
uint64_t binomial_modular_coefficient3(uint64_t n, uint64_t k, uint64_t m){
//Variáveis locais
std::vector<uint64_t> digits_n, digits_k;
uint64_t result=1;
int i, j;

//Procedimentos
//Calculando os digitos de n e k na base m
expand_in_base(digits_n, n, m);
expand_in_base(digits_k, k, m);

//Ajuste de variáveis
i=(digits_n.size()-1);
j=(digits_k.size()-1);

//Loop principal, i>=j
while(j>=0){
result=result*binomial_modular_coefficient2(digits_n[i], digits_k[j], m);
//Atualizando variáveis para a próxima iteração
j--;
i--;
           };

//Resultado
return result;
                                                                          };

//*******************************************************************************************************************************************************************
//FIM DO HEADER
#endif


