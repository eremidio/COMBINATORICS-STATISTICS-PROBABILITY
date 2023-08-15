--VAMOS CRIAR UM PROGRAMA EM HASKELL QUE CALCULA OS NÚMEROS DE BELL
--EXECUTAR ESTE PROGRAMA COM O COMANDO: runghc bell_numbers.hs

{-
DADO UM CONJUNTO DE ELEMENTOS, DIGAMOS {a, b, c}, PARTIÇÕES DE UM CONJUNTO SÃO CONJUNTOS DE SUBCONJUNTOS NÃO VAZIOS DESTE 
CONJUNTOS QUE SATISFAZEM A SEGUINTES CONDIÇÕES:
1. OS SUBCONJUNTOS NÃO SÃO VAZIOS.
2. A INTERSEÇÃO DE SUBCONJUNTOS É NULA.

NESTE EXEMPLOS COM TRÊS ELEMENTOS A PARTIÇÃO É DADA POR: {{a},{b},{c}}; {{a, b},{c}}; {{a, c},{b}}; {{b, c},{a}}; {{a, b, c}}.
O NÚMERO DE PARTIÇÕES DE UM CONJUNTO COM n ELEMENTOS É CHAMADO DE n-ÉSIMO NÚMERO DE BELL. NESTE  EXEMPLO B(3)=5.

OS NÚMEROS DE BELL PODEM SER DEFINIDOS RECURSIVAMENTE POR MEIO DA RELAÇÃO:
B(n)=Σ C(n,k)B(k), ONDE C(n,k) COM n<k DENOTA  A COMBINAÇÃO SIMPLES DE k ELEMENTOS EM UM CONJUNTO DE n ELEMENTOS
OS PRIMEIROS TERMOS DA SEQUÊNCIA DE BELL SÃO 1, 1, 2, ...

NÚMEROS DE BELL APARECEM EM OUTRAS ÁREAS DA MATEMÁTICA COMO CONTAGEM DE FATORAÇÕES DIFERENTES DE INTEIROS SEM FATORES PRIMOS
REPETIDOS, EM PŔOBLEMAS ENVOLVENDO PERMUTAÇÕES, ETC.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Bell_number


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

--Funções que calcula o n-ésimo número de Bell
bell_number::Integer->Integer
bell_number n
    |n==0 = 1
    |n==1 = 1
    | otherwise = sum [combination (n-1) k * bell_number k | k <- [0..n-1]]
    
--FUNÇÃO PRINCIPAL
main::IO()
main = do
    putStr("Digite um número inteiro: ")
    n1<-getLine
    let n = read n1::Integer
    putStrLn(show n++"-ésimo número de Bell: "++show(bell_number n))




