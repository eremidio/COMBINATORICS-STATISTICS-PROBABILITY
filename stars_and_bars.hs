--VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA A SOLUÇÃO DO PROBLEMA CONCHECIDO COMO STARS AND BARS

{-
O PROBLEMA DE ANÁLISE COMBINATÓRIA CONHECIDO COMO STARS AND BARS BASEIA-SE NA SEGUINTE IDEIA: 
EXISTEM n BOLAS QUE SÃO INDISTIGUIVÉIS ENTRE SI E ESTAS BOLAS SERÃO POSTAS EM k CAIXAS DISTINTAS.
SE CAIXAS VAZIAS SÃO PERMITIDAS, ESTE PROBLEMA SE RESUME A CONTAGEM DE COMPOSIÇÕES DE UM NÚMERO INTEIRO (QUE INCLUI PARTIÇÕES E
POSSÍVEIS PERMUTAÇÕES DOS ELEMENTOS EM SUAS PARTIÇÕES). CASO CAIXAS VAZIAS SEJAM NÃO INCLUSAS ESTE PROBLEMA SE REDUZ AO CÁLCULO
DE COMPOSIÇÕES FRACAS DE UM INTEIRO.

EXEMPLO: SEJAM 4 BOLAS E 3 CAIXAS.
PARA O CASO DE CAIXAS NÃO VAZIAS TEMOS: *|**|* ; **|*|* ; *|*|**. (3 no total)
SE CAIXAS VAZIAS FOREM PERMITIDAS TEMOS: ****|| ; |****|; ||****; ***|*| ; *|***|; |*|*** ; *|***| ; ***|*|; |***|* ;
**|**| ; **| |**; |**|**; *|**|* ; **|*|* ; *|*|**. (15 no total)

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Composition_(combinatorics)
                          https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)

-} 


--FUNÇÕES
--Função que calcula o fatorial de um número
factorial::Integer->Integer
factorial n = product[1..n] 

--Combinação simples
combination::Integer->Integer->Integer
combination n m
    | n<m = error "Lista de argumentos inválida."
    | n>=m = div (factorial n) ((factorial (n-m))*(factorial m))


--Composições
composition::Integer->Integer->Integer
composition n k= combination (n-1) (k-1)


--Composições fracas
weak_composition::Integer->Integer->Integer
weak_composition n k= combination (k+n-1) (n)


--FUNÇÃO PRINCIPAL
main::IO()
main = do
    putStrLn("Usuário digite um número inteiro correspondendo ao número de bolas indistinguíveis: ")
    n<-readLn
    putStrLn("Usuário digite um número inteiro correspondendo ao número de caixas distinguíveis: ")
    k<-readLn
    putStrLn("Número de arranjos com "++show n++" bolas e "++ show k ++" caixas não vazias: "++show(composition n k ))
    putStrLn("Número de arranjos com "++show n++" bolas e "++ show k ++" caixas: "++show(weak_composition n k ))


