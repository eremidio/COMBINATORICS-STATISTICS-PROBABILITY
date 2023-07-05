/*Vamos criar um arquivo mestre com o algotitmo bubble sort para ordenar seus elementos númericos em forma crescente ou decrescente*/

//Cabeçalho
#include<algorithm>
#include<utility>


namespace bubblesort{

template<class T>
void bubblesort(T array[], int n){
//Definição de variáveis auxialiares
int i , j;
//Condicional 
if (n>=2){
 for(i=0; i<n;i++)
  {for(j=1;i+j<n; j++){
   if(array[i]>array[i+j]){
    std::swap(array[i], array[i+j]);
                      };
                     };
   };
        };

                                  };



}
