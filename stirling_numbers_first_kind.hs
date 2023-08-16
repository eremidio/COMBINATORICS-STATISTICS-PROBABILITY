--VAMOS IMPLEMENTAR UM PROGRAMA QUE CALCULA OS NÚMEROS DE STIRLING DO PRIMEIRO TIPO
--RODAR ESTE PROGRAMA COM O COMANDO: runghc stirling_numbers_first_kind.hs 

{-
OS NÚMEROS DE STIRLING DO PRIMEIROO TIPO s(n,k) SÃO DEFINIDOS COMO OS COEFICIENTES DE EXPANSÃO DO POLINÔMIO FATORIAL
P(x)= x(x-1)...(x-n+1) = Σ s(n,k)(x^k). |s(n,k)| REPRESENTA O NÚMERO DE PERMUTAÇÕES DE n ELEMENTOS COM k CICLOS DISJUNTOS.

POR EXEMPLO SEJAM O CONJUNTO {1,2,3}. O TAL DE PERMUTAÇÃO DE CONJUNTOS DESTES ELEMENTOS É IGUAL A 3!=6.
DESTAS HÁ UMA PERMUTAÇÃO COM CICLO 3 (123) A IDENTIDADE PORTANTO s(3,3)=1, TRÊS PERMUTAÇÕES DE CICLO 2 (1)(23)--> {1,3,2};
(2)(13)--> {3,2,1}; (3)(12)--> {2,1,3} E DUAS PERMUTAÇÕES DE CICLO 1 (132) --> {3,1,2} E (231) --> {2,3,1}.

OS NÚMEROS DE STIRLING DE PRIMEIRO TIPO POSSUEM RELAÇÃO DIRETA COM NÚMEROS DE STIRLING DE SEGUNDO TIPO E APARECEM EMUM CONJUNTO
DE RELAÇÕES IMPORTANTES ENVOLVENDO FUNÇÕES MATEMÁTICAS COMO A FUNÇÃO DE HURWITZ E A FUNÇÃO ZETA DE RIEMANN.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Stirling_numbers_of_the_first_kind
                          https://en.wikipedia.org/wiki/Stirling_number

-}


--FUNÇÕES
--Função que calcula recursivamente números de Stirling do primeiro tipo
unsigned_stirling_number_first_kind::Integer->Integer->Integer
unsigned_stirling_number_first_kind n k 
    |n==0 && k==0 = 1
    |n==0 && k/=0 = 0
    |n/=0 && k==0 = 0
    |otherwise = (n-1)*(unsigned_stirling_number_first_kind (n-1) k) + unsigned_stirling_number_first_kind (n-1) (k-1)

signed_stirling_number_first_kind::Integer->Integer->Integer
signed_stirling_number_first_kind n k 
    |n==0 && k==0 = 1
    |n==0 && k/=0 = 0
    |n/=0 && k==0 = 0
    |otherwise = (-1)*(n-1)*(signed_stirling_number_first_kind (n-1) k) + signed_stirling_number_first_kind (n-1) (k-1)

--FUNÇÃO PRINCIPAL
main::IO()
main=do
    putStr("Digite um número inteiro: ")
    n1<-getLine
    let n = read n1::Integer
    putStr("Digite um número inteiro: ")
    k1<-getLine
    let k = read k1::Integer
    putStrLn("(Positivo) s("++show n++","++show k++") = "++show(unsigned_stirling_number_first_kind n k)++".")
    putStrLn("s("++show n++","++show k++") = "++show(signed_stirling_number_first_kind n k)++".")

