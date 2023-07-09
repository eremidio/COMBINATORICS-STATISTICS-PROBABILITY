--VAMOS ESCREVER UM PROGRAMA QUE IMPLEMENTA O ALGORITMO QUICKSORT EM C++


--FUNÇÕES
quickSort :: (Ord a) => [a] -> [a] --Type casting um símbolo que se refere a elementos ordenáveis
quickSort [] = []
quickSort (x:xs) = quickSort smaller ++ [x] ++ quickSort larger --SELECIONANDO UM ELEMENTO DA LISTA E SEPARANDO-A EM DUAS SUBLISTAS DE ELEMENTOS MAIORTES E MENORES QUE O DADO ELEMENTO
    where --Claúsula que define duas sublistas
      smaller = filter (< x) xs --Sublista dos elementos menores que um dado elemento
      larger = filter (>= x) xs --Sublista dos elementos maiores que um dado elemento

--FUNÇÃO PRINCIPAL
main::IO()
main = do
 print(quickSort [1..3])
 print(quickSort [1,4,2,3,1,2,3])

