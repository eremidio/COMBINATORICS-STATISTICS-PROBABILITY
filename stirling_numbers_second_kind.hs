--VAMOS CRIAR UM PROGRAMA QUE CALCULA OS NÚMEROS DE STIRLING DO SEGUNDO TIPO
--RODAR ESTE PROGRAMA COM O COMANDO> runghc stirling_numbers_second_kind.hs

{-
OS NÚMEROS DE STIRLING DO SEGUNDO TIPO S(n,k) CONTABILIZAM DE QUANTAS MANEIRAS DIFERENTES UM CONJUNTO DE n OBJETOS PODE SER
DIVIDO EM k SUBCONJUNTOS NÃO VAZIOS. 

OS NÚMEROS DE STIRLING SO SEGUNDO TIPO APARECEM EM AVÁRIOS PROBLEMAS EM ANÁLISE COMBINATÓRIA, POSSUINDO RELAÇÃO DIRETA COM OS NÚMEROS DE BELL, COM A DISTRIBUIÇÃO DE POISSON E COM O NÚMERO DE PONTOS FIXOS EM UMA DISTRIBUIÇÃO UNIFORME. 

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind

-}


---FUNÇÕES
--Função que calcula o fatorial de um número
factorial::Integer->Integer
factorial n = product[1..n] 

--Função que calcula um termo da soma 
term::Integer->Integer->Integer->Integer
term n k i= div ((-1)^(k-i)* (i^n)) (factorial (k-i)*factorial i)

--Função que calcula os números de Stirling do segundo tipo
stirling_number_second_kind::Integer->Integer->Integer
stirling_number_second_kind n k = sum[term n k i | i<-[0..k]]



--FUNÇÃO PRINCIPAL
main::IO()
main=do
    putStr("Digite um número inteiro: ")
    n1<-getLine
    let n = read n1::Integer
    putStr("Digite um número inteiro: ")
    k1<-getLine
    let k = read k1::Integer
    putStrLn("S("++show n++","++show k++") = "++show(stirling_number_second_kind n k)++".")

