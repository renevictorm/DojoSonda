
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;
class Sonda{
private:
	int x; //Coordenada X
    int y; //Coordenada Y
    int mx;//limit do grid em x
    int my;//limit do grid em y
    int cont; // conta moviementos invalidos
    char Dir;
    
public:
	
	Sonda(int maxx,int maxy){
		this->x= 0; //posição inicial x
		this->y=0;//posição inicial y
		this->cont=0;//nenhuma movimentação invalida
		this->Dir='N';//A sonda inicia apontando para o Norte
		if(maxx <=0){
    		this->mx= 1;
    	}else{
    		this->mx=maxx;
		}
		
		if(maxy <=0){
    		this->my= 1;
    	}else{
    		this->my=maxy;
		}
		
	};
	
	GirarSonda(char comando){
		switch(this->Dir){
			case 'N':
				if(comando == 'R'){
					this->Dir = 'E';
				}else{
					this->Dir = 'W';
				}
				break;
				
			case 'W':
				if(comando == 'R'){
					this->Dir = 'N';
				}else{
					this->Dir = 'S';
				}
				break;
				
			case 'S':
				if(comando == 'R'){
					this->Dir = 'W';
				}else{
					this->Dir = 'E';
				}
				break;
				
			case 'E':
				if(comando == 'R'){
					this->Dir = 'S';
				}else{
					this->Dir = 'N';
				}
				break;
		}
	
	};
	
	char GetDir(){
		return this->Dir;
	}
	
	int Getmx(){
		return this->mx;
	}
	
	int Getmy(){
		return this->my;
	}
};


bool testeTamanhoGrid(){//teste para a criação do tamanho máximo do grid;

//se o input for menor ou igual a 0 a aplicação deve alterar para no mínimo 1 por 1, caso contrario o teste retorna vermelho(false);  
	
	Sonda G1(2,2);
	Sonda G2(-1,0);
	
	if ((G1.Getmx() != 2) || (G1.Getmy() != 2)){
		return false;
	} 
	
	if (G2.Getmx() <= 0 || G2.Getmy() <=0){
		return false;
	}
	
	return true;
}

void GirarMover(string S, Sonda& Son){//função que pega uma string do input e converte em um array de char para charmar os metodos girar e mover da sonda
	
	int tamanhoString= S.length();
	
	char array[tamanhoString + 1];
	
	strcpy(array,S.c_str());
	
	for(int i=0; i<tamanhoString; i++){
		Son.GirarSonda(array[i]);
	}
	
} 

bool testeGirar(){//Teste para verificar a rotação da Sonda;

//A sonda deve iniciar para o norte e se rotacionada para a esquerda deve girar para o oeste;
//Caso rotacionada para a direita deve girar para leste e assim por diante;
	
	
	Sonda S1(5,5);
	Sonda S2(5,5);
	Sonda S3(5,5);
	Sonda S4(5,5);
	Sonda S5(5,5);
	
	GirarMover("L",S1);
	GirarMover("R",S2);
	GirarMover("LL",S3);
	GirarMover("RRR",S4);
	GirarMover("LRRL",S5);
	
	if(S1.GetDir() != 'W') {
		return false;
	}
	
	if(S2.GetDir() != 'E') {
		return false;
	}
	
	if(S3.GetDir() != 'S') {
		return false;
	}
	
	if(S4.GetDir() != 'W') {
		return false;
	}
	
	if(S5.GetDir() != 'N') {
		return false;
	}
	
	return true;
	
}


bool testeMover(){//Teste para verificar a movimentação da Sonda;

//A sonda deve iniciar na posição x=0 e y=0;
//Caso se mova a sonda deve acrescentar ou subtrair uma unidade em x ou y, dependendo da direção na qual está voltada;
//Se a sonda tentar se mover para fora dos limites da grid ela não deve se mexer
	
	Sonda S1(5,5);
	Sonda S2(5,5);
	Sonda S3(5,5);
	Sonda S4(5,5);
	Sonda S5(1,1);
	
	int px,py;
	
	GirarMover("RM",S2);
	GirarMover("LM",S3);
	GirarMover("M",S4);
	GirarMover("MMMM",S5);
	
	S1.GetPos(px,py);
	if((px != 0) && (py != 0)) {
		return false;
	}
	
	S2.GetPos(px,py);
	if((px != 1) && (py != 0)) {
		return false;
	}
	
	S3.GetPos(px,py);
	if((px != 0) && (py != 0)) {
		return false;
	}
	
	S4.GetPos(px,py);
	if((px != 0) && (py != 1)) {
		return false;
	}
	
	S5.GetPos(px,py);
	if((px != 0) && (py != 0)) {
		return false;
	}
	
	return true;
	
}

//========================================================================================

int main() {
	//Teste do Grid--------------------------------------------
	if(testeGirar()){
		cout << "GIRAR = VERDE" << '\n';
	}else{
		cout << "GIRAR = VERMELHO" << '\n';
	}
	//----------------------------------------------------------
	
	//Teste Girar--------------------------------------------
	if(testeTamanhoGrid()){
		cout << "GRID= VERDE" << '\n';
	}else{
		cout << "GRID = VERMELHO" << '\n';
	}
	//----------------------------------------------------------
	
	//Teste MOVER--------------------------------------------
	if(testeTamanhoGrid()){
		cout << "MOVER= VERDE" << '\n';
	}else{
		cout << "MOVER = VERMELHO" << '\n';
	}
	//----------------------------------------------------------
	return 0;
}
