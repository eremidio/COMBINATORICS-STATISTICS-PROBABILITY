--VAMOS CRIAR UM PROGRAM QUE CALCULA OS COEFICIENTE BOINOMIAIS DE FORMA RECURSIVA EM EM HASKELL
--EXECUTAR ESTE PROGRAMA COM O COMANDO: runghc binomial_coefficients.hs



--FUNÇÕES
--Função que calcula o coeficente da expansão binomial recursivamente
binomial_coefficient::Integer->Integer->Integer
binomial_coefficient n k
    | k>n = error"Argumentos inválidos!"
    | k==0 = 1
    | k==1 = n
    | k==n = 1
    | otherwise = binomial_coefficient (n-1) k + binomial_coefficient (n-1) (k-1)


--FUNÇÃO PRINCIAPAL
main :: IO()
main = do
    putStr("Digite um número inteiro: ")
    n1<-getLine
    let n = read n1::Integer
    putStr("Digite um número inteiro: ")
    k1<-getLine
    let k = read k1::Integer
    putStrLn("Coeficiente binominal C("++show n++","++show k++") = "++show(binomial_coefficient n k)++".")

