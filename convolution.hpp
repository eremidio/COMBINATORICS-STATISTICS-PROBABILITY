//VAMOS CRIAR UM PROGRAMA QUE CALCULA A CONVOLUÇÃO DE DOIS CONJUNTOS

/*
A CONVOLUÇÃO  DE DOIS CONJUNTOS A, B CORRESPONDE A UMA ESPÉCIE DE PRODUTOS DE DOIS CONJUNTOS.
DADOS DOIS CONJUNTOS A=(A(0), A(1), ..., A(n)) E B=(B(0), B(1), ..., B(m)). 
A CONVOLUÇÃO DE A COM B DENOTADA POR A*B É O CONJUNTO:
A*B={A(0)*B(m), A(0)*B(m-1)+A(1)*B(m), ..., A(n-1)*B(0)+A(n)*B(1), A(n)*B(0)}

SE A POSSUIR n ELEMENTOS  E B m ELEMENTOS A CONVOLUÇÃO A*B, POSSUI m+n-1 ELEMENTOS NO TOTAL.

EXISTEM VÁRIAS APLICAÇÕES DESTE CONCEITOS EM MATEMÁTICA:
DADOS O CONJUNTOS A E B DE COEFICIENTES DE DOIS POLINÔMIOS, A CONVOLUÇÃO A*B NOS DÁ OS COEFICIENTES DOS PRODUTOS DESTES POLINÔMIOS.
SE A SOMA DOS ELEMENTOS DE UM CONJUNTO É IGUAL A 1, A CONVOLUÇÃO A*B CORRESPONDE A UM MÉDIA PONDERADA DADA UMA DISTRIBUIÇÃO DE PROBABILIDADES ESPECIFICADAS PELOS ELEMENTOS DO COJUNTO CUJA SOMA É 1.

ESTE CONCEITO É GENERALIZADO PARA CONJUNTOS E FUNÇÕES CONTÍNUAS E É DE IMPORTÂNCIA EM VARIÁS ÁREAS COMO: TRANSFORMADAS INTEGRAIS, ESTATÍSTICA, ENTRE OUTROS.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Convolution

*/



//***************************************************************************************************************************
//CABEÇALHO
#if !defined CONVOLUTION_H
#define CONVOLUTION_H

#pragma once
#include<vector>
#include<iostream>

//***************************************************************************************************************************
//FUNÇÕES
//Função que determina a convolução de dois conjuntos
template<typename T>
std::vector<T> convolution(std::vector<T> v1, std::vector<T> v2){
//Variáveis locais
int result_size = v1.size()+v2.size()-1;
std::vector<T> result;
int index_a, index_b, i, j, k;
T temp;
//Procedimentos
//Ajuste de variáveis para a primeira iteração
index_a=0;
index_b=v2.size()-1; 


//Calculando n-ésimo elemento do vetor de convolução
for(i=0; i<result_size-1; ++i){
if(index_a<=(v1.size()-1)){
temp=0;
for(j=index_a, k=index_b; j>=0 && k>=0; --j, --k){
temp+=v1[j]*v2[k];
                                                 };
//TESTE USE UM // APÓS O MESMO
//std::cout<<"v2.size"<<v2.size()<<"\n";
//std::cout<<"temp"<<temp<<"\n";

//Adicionando elementos ao resultado final e atualizandoos indexes
result.push_back(temp);
index_a++;
                          };

if(index_a>(v1.size()-1)){
temp=0;
for(j=index_a, k=index_b; j>=0 && k>=0; --j, --k){
temp+=v1[j]*v2[k];
                                                 };
//TESTE USE UM // APÓS O MESMO
//std::cout<<"temp"<<temp<<"\n";

//Adicionando elementos ao resultado final e atualizando os indexes
result.push_back(temp);
index_b--;
                          };

                            };

//Resultado
return result;
                                                                };

//Função que printa os elementos de um vetor
template<typename T>
void print_vector(std::vector<T> vector_items){

std::cout<<"{";
for(auto y:vector_items)
std::cout<<y<<",";
std::cout<<"}\n";
                                              };
#endif
