//VAMOS CRIAR UM ARQUIVO QUE IMPLEMENTA O ALGORITMO SHELLSORT PARA CLASSIFICAR ELEMENTSO EM UM ARRAY 


/*Cabeçalho*/
#include<utility>
#include<algorithm>


//Algoritmo Shellsort

namespace shellsort{

template<class T>
void shellsort(T array[], int n){
//Variáveis locais
int gap, i ,j;
//Procedimento
for(gap=n/2; gap>0; gap/=2){

for(i=gap; i<n; ++i){

for(j=i-gap; j>=0; j-=gap){
if(array[j]>array[j+gap])
std::swap(array[j], array[j+gap]);
else
continue;
                          };

                    };

                           };
                                };

                   }//fim do namespoace shell sort
