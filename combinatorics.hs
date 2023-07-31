{-
VAMOS CRIAR UM PROGRAMA EM HASKELL QUE IMPLEMENTA AS FUNÇÕES BÁSICAS DE ANÁLISE COMBINATÓRIA.
ÚTIL PARA O CÁLCULO ENVOLVENDO VALORES MAIS ELEVADOS.
-}

--FUNÇÕES
--Função que calcula o fatorial de um número
factorial::Integer->Integer
factorial n = product[1..n] 

--Permutação simples
permutation::Integer->Integer
permutation n = (factorial n)

--Arranjo simples
arrangement::Integer->Integer->Integer
arrangement n m
    | n<m = error "Lista de argumentos inválida."
    | n>=m = div (factorial n) (factorial (n-m))

--Combinação simples
combination::Integer->Integer->Integer
combination n m
    | n<m = error "Lista de argumentos inválida."
    | n>=m = div (factorial n) ((factorial (n-m))*(factorial m))


--FUNÇÃO PRINCIPAL
main::IO()
main = do
    putStrLn("Usuário digite um número inteiro: ")
    x<-readLn
    putStrLn("Usuário digite um número inteiro: ")
    y<-readLn
    putStrLn("P("++show x++")= "++ show(permutation x)++".")
    putStrLn("P("++show y++")= "++ show(permutation y)++".")
    putStrLn("A("++show y++","++show x ++")= "++ show(arrangement x y)++".")
    putStrLn("C("++show y++","++show x ++")= "++ show(combination x y)++".")


