//Vamos escrver um programa que simula matemticamente o problema do caminho aleátório

/*Cabeçalho*/
#include<iostream>
#include<thread>
#include<chrono>
#include<cmath>
#include<array>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
using this_thread::sleep_for;
using namespace std::chrono_literals;

//Funções úteis

//Função que printa a tabuleiro na tela do computador
void mostrar_tabuleiro(int a, int b){
//Variáveis
char tabuleiro[39][39];
int x, y;

//Determinando a posição do bebado
for(x=0; x<39; x++){
    for(y=0; y<39; y++){
if(x==a && y==b)
    tabuleiro[x][y]='o';
else if(x!=a || y!=b)
    tabuleiro[x][y]=' ';
                       };
                   };
//Printando o tabulero na tela computador
for(x=0; x<39; x++){
    for(y=0; y<39; y++)
 cout<<tabuleiro[x][y];
cout<<"\n";
                      
                 };

}


//Função que define o caminha do bêbado
void  movimento(int& x, int& y){
int lance /*Variável que define o movimento do bêbado, 0: direita, 1:esquerda, 2:cima, 3:baixo*/;
//Executando o movimento
srand(time(NULL));
lance=rand()%4;

//Obtendo a nova posição
if(lance==0)
{x+=1; y+=0;
if(x==38 || x==0 || y==38 ||y==0)
x-=1;};
if(lance==1)
{x-=1; y+=0;
if(x==38 || x==0 || y==38 ||y==0)
x+=1;};
if(lance==2)
{x+=0; y+=1;
if(x==38 || x==0 || y==38 ||y==0)
y-=1;};
if(lance==3)
{x+=0; y-=1;
if(x==38 || x==0 || y==38 ||y==0)
y+=1;};

}

//Função que calcula a distância da origem
double distancia(int a, int b){
return(sqrt(pow(a-20,2)+pow(b-20,2)));
}

//Aqui começa a função principal do programa

int main(){
//Semente para geração de números 
//Definindo variáveis usadas no programa
int x, y, n_movimentos, flag;
char continuar;
vector<int> rodadas;
//Apresentação
cout<<"Vamos simular o caminhar do bêbado em um tabuleiro 39x39\nO bêbado inicia seu trajeto no centro do tabuleiro que corresponde as coodernadas x=20 e y=20.\nUsaremos a equidade de movimentos em todas as direções.\nMovimentos fora do escopo do tabuleiro serão desconsiderados.\nNestes casos o bebado retorna um passo para trás.\n";
//Ajustando o tabuleiro em sua configuração inicial
x=20;
y=20;
n_movimentos=0;

flag=cin.get();
cout<<"Eis o tabuleiro em sua configuração inicial: \n";
mostrar_tabuleiro(x, y);

//Rodando o loop principal
restart:
do{n_movimentos++;
movimento(x,y);
sleep_for(0.1s);
mostrar_tabuleiro(x,y);
cout<<"x = "<<x<<", y ="<<y<<".\n";
cout<<"Distância da origem: "<<distancia(x, y)<<"\n";
cout<<"Número de movimentos: "<<n_movimentos<<"\n\n";
}while(distancia(x, y)>0.0 || n_movimentos>1000000);
flag=cin.get();
//Registrando o número de movimentos de uma simulação e executando novas simulações
rodadas.push_back(n_movimentos);
cout<<"Deseja rodar outra simulação?\nDigite 's' para sim ou 'n' para encerrar as simulações: ";
cin>>continuar;

if(continuar=='s'){
x=20;
y=20;
n_movimentos=0;
goto restart;
          };
auto media=[=](){
double soma_parcial;
soma_parcial=0.0;
for(auto i:rodadas)
soma_parcial=soma_parcial+i;
return(double(soma_parcial/rodadas.size()));

};

cout<<"A média de movimentos para retornar a origem foi de "<<media()<<"\n";
return 0;
}
