--VAMOS ESCREVER UM PROGRAMA EM HASKELL QUE IMPLEMENTA ÁRVORES BINÁRIAS

--IMPORTANDO MÔNADAS USADAS
import Data.Maybe

--TIPOS 
data Tree a = Empty -- Null node
    | Leaf a -- Folha (end node)
    | Branch a (Tree a) (Tree a) --Ramificação
    deriving (Show, Eq)
    
--FUNÇÕES
--Função que printa os elementos de uma lista
tolist :: Tree a -> [a]
tolist Empty = [] --No caso de empty node retorna uma lista vazia
tolist (Leaf x) = [x] --Retorna elementos no nó de uma árvore binária
tolist (Branch x l r) = tolist l ++ [x] ++ tolist r -- Invoca a função recursivamente quando há uma ramificação x é o elemento alocado no nó e l e r são as ramificações 


preordertolist :: Tree a -> [a]
preordertolist Empty = []
preordertolist (Leaf x) = [x]
preordertolist (Branch x l r) = [x] ++ preordertolist l ++ preordertolist r

inordertolist :: Tree a -> [a]
inordertolist Empty = []
inordertolist (Leaf x) = [x]
inordertolist (Branch x l r) = inordertolist l ++ [x] ++ inordertolist r

postordertolist :: Tree a -> [a]
postordertolist Empty = []
postordertolist (Leaf x) = [x]
postordertolist (Branch x l r) = postordertolist l ++ postordertolist r ++ [x]

--Função map para árvores binárias
map_bt :: (a -> b) -> Tree a -> Tree b
map_bt f Empty = Empty
map_bt f (Leaf x) = Leaf (f x)
map_bt f (Branch x l r) = Branch (f x) (map_bt f l) (map_bt f r)

--Função quer concatena elementos na árvore binária
foldr_bt :: (a -> b -> b) -> b -> Tree a -> b
foldr_bt _ z Empty = z
foldr_bt f z (Leaf x) = f x z
foldr_bt f z (Branch x l r) = foldr_bt f (f x (foldr_bt f z r)) l

--Função usada para desenhar a árvore
draw :: Show a => Tree a -> String
draw t = pfxDraw "" t
    where pfxDraw p Empty = p ++ "+:\n" --printa um nó vazio (null node)
          pfxDraw p (Leaf x) = p ++ "+-" ++ show x ++ "\n" --printa o valor alocado em uma folha (end-node)
          pfxDraw p (Branch x l r) = center ++ left ++ right -- p ="" (constante empty string)
            where center = p ++ "+-" ++ show x ++ "\n"
                  left = pfxDraw (p ++ " ") l
                  right = pfxDraw (p ++ " ") r --quando há uma ramificação a função printa o valor alocado no nó em center e chama recursivamente a função nas ramificações a esquerda e direita " " é usado para identação e indicar a escala hierárquica

--FUNÇÃO PRINCIPAL
main :: IO ()
main = do
    --Declarando uma árvore binária de inteiros
    {-  1
       / \
      2   3
         / \
        4   5
    -}

    let t = Branch 1 (Leaf 2) (Branch 3 (Leaf 4) (Leaf 5))
    print t
    print (tolist t)
    print (preordertolist t)
    print (inordertolist t)
    print (postordertolist t)
    print (map_bt (*2) t)
    print (foldr_bt (+) 0 t)
    putStr (draw t)



