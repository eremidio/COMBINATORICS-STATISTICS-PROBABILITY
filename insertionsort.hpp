//Vamos criar um arquivo mestre que contém o algoritmo insertionsort para ordenar elementos em um array

/*Cabeçalho*/
#include<utility>
#include<algorithm>

//Criaremos um namespace personalizado para o procedimento
namespace insertionsort{

template<class T>
void insertionsort(T array[], int n){
//Variáveis auxiliares
int i, j;

//Procedimentos executáveis
if(n>=2){
for (i=1; i<=n-1; i++){
for(j=0; j<i; j++){
if(array[i]<array[j]){
std::swap(array[i],array[j]);
continue;
                      };
                  };

                      };
        };

                                    };




                       }
