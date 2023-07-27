--VAMOS ESCREVER UM PROGRAMA EM HASKELL QUE CALCULA O FATORIAL DE UM NÚMERO

--DEFINIÇÃO DE FUNÇÕES
fatorial::Integer->Integer
fatorial n =product[1..n]

--PROGRAMA PRINCIPAL 
main::IO()
main = do
 putStrLn("Usuário digite um número inteiro:")
 x<-readLn
 putStrLn("O fatorial de "++show x++" é "++ show(fatorial x)++".\n")
 
