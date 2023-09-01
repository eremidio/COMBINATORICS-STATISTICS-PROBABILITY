//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DA BUSCA BINÁRIA EM UM ARRAY ORDENADO DE ELEMENTOS


//*************************************************************************************************************************
//CABEÇALHO
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H


//*************************************************************************************************************************
//FUNÇÕES
//Função que checa se um determinado elemento está em um array ordenado
template<typename T>
bool binary_search(T array[], T target, int n){
//Variáveis locais
int mid = ((n-1)/2), upper=(n-1), lower=0;

int i;

//Procedimentos
//Loop principal
while(true){
//Fimdo loop principal
if(array[mid]==target)
return true;
if(lower==mid || upper==mid)
return false;

//Comparado o valor desejado com o elemento do meio do array
if(array[mid]>target){
upper=mid;
mid=(upper+lower)/2;
                     };

if(array[mid]<target){
lower=mid;
mid=(upper+lower)/2;
                     };

           };
                                              };


//*************************************************************************************************************************
//FIM DO HEADER
#endif

