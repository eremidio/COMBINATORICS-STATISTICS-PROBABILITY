!VAMOS CRIAR UM PROGRAMA EM FORTRAN QUE GERA NÚMEROS PSEUDO ALEATÓRIOSUSANDO A EQUAÇÃO LOGISTICA
!COMPILAT ESTE PROGRAMA COM O COMANDO: gfortran -o pseudo_random_number pseudo_random_number.f95


!*************************************************************************************************************************
!   A EQUAÇÃO LOGÍSTICA É UMA DAS EQUAÇÕES MAIS IMPORTANTES EM MATEMÁTICAS SERVINDO DE MODELOS PARA MODELAR INÚMEROS SISTEMAS
!   FÍSICOS DE INTERESSE ESTA EQUAÇÃO TEM A FORMA:
!   X(N+1)=rX(N)(1-X(N)), NA QUAL OS X(i)'s SÃO RESTRITOS AOS INTERVALO (0,1).

!   DE GRANDE INTERESSE TÉORICO ESTA EQUAÇÃO É DAS EQUAÇÕES MAIS SIMPLES A EXIBIR COMPORTAMENTO CAÓTICO. O COMPORTAMENTO DAS
!   SOLUÇÕES DESTA EQUAÇÃO DEPENDEM DO PARÂMETRO r, AS SEGUINTES OBSERVAÇÕES SÃO VÁLIDAS:
!   PARA r<1, AS SOLUÇÕES DESTA EQUAÇÃO TENDEM A 0 PARA N GRANDE
!   PARA 1<r<3 AS SOLUÇÕES DESTA EQUAÇÃO TENDE A UM VALOR FIXO 
!   PARA 3<r≲ 3,5966 AS SOLUÇÕES PASSAM A OSCILAR PARA  2^k (k INTEIRO) VALORES DIFERENTES
!   PARA VALORES AINDA MAIORES DE r A SOLUÇÃO DA EQUAÇÃO PARA A SE COMPORTAR DE FORMA AINDA MAIS COMPLEXA, EMBORA PARA PEQUENOS
!   INTERVALOS ACIMA DESTE A EQUAÇÃO OSCILE ENTRE VALORES ESPECÍFICOS.

 

!   PODEMOS ENTÃO USAR A EQUAÇÃO LOGÍSTICA COMO UM GERADOR DE NÚMEROS ALEATÓRIOS PARA GERAR NÚMEROS PSEUDO ALEATÓRIOS COM  
!   RESULTADOS RAZOAVELMENTE BONS

!   PARA MAIRES INFORMAÇÕES: https://en.wikipedia.org/wiki/Logistic_map
!                            https://www.nature.com/articles/261459a0

!************************************************************************************************************************



!*******************************************************************************************************************
program pseudo_random_number
!Variáveis
implicit none
real(kind=kind(1.0d0)):: x0, r
integer:: n, i, fi, ios, random_int
real(kind=kind(1.0d0)), allocatable, dimension(:)::x
character(len=20)::filename

!Procedimentos
!Ajuste de parâmetros da simulação
write(*,*)"Digite um valor inicial entre 0 e 1 para gerar uma sequência de números aleatórios:"
read(*,*)x0
write(*,*)"Digite um parâmetro superior a 3,5699 para determinar a taxa de variação dos números gerados:"
read(*,*)r;
write(*,*)"Digite um valor quantos valores você irá incluir neste experimento:"
read(*,*)n;
write(*,*)"Digite o nome do arquivo no qual os dados da simulação serão salvos (usar a extensão ,txt):"
read(*,*)filename;

!Abrindo um arquivo e registrando os dados da simulação
open(newunit=fi, file=filename, status="replace", action="readwrite", iostat=ios)

if(ios/=0) then
write(*,*)"Erro ao abrir o arquivo"
else !Resgitrando os parâmetros da equação logística
write(unit=fi, fmt=*)"LISTA DE NÚMEROS PSEUDOALETÓRIOS GERADOS COM A EQUAÇÃO LOGÍSTICA"
write(unit=fi, fmt=*)"SEMENTE INICIAL: ", x0
write(unit=fi, fmt=*)"TAXA DE CRESCIMENTO: ", r
write(unit=fi, fmt =*)"PARÂMETROS USADOS NA GERAÇÃO DE INTEIROS: 989898989 E 1000000000"
endif




!Alocando dinamicamente memória e iniciando a simulação numérica
allocate(x(n))
x(1)=x0

do i= 1, n, 1
 x(i+1)= r*x(i)*(1-x(i))
 random_int= mod(floor(x(i+1)*1000000000), 989898989)   
 write(unit=fi, fmt =*) i, x(i+1), random_int
end do

deallocate(x)

!Encerrando o arquivo
 close(unit=fi, status="keep", iostat=ios)
if(ios==0) then
write(*,*) "Simulação executada com sucesso!"
else
write(*,*) "Erro ao fechar arquivo contendo dados da simulação!"
end if 

end program pseudo_random_number
