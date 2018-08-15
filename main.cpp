
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;
class Sonda{
private:
	int x; //Coordenada X
    int y; //Coordenada Y
    int cont; // conta moviementos invalidos
    char Dir;
    
public:
	
	Sonda(){
		this->x= 0; //posição inicial x
		this->y=0;//posição inicial y
		this->cont=0;//nenhuma movimentação invalida
		this->Dir='N';//A sonda inicia apontando para o Norte
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
};

//========================================================================================
class Grid{
private:
    int x; //Coordenada X
    int y; //Coordenada Y
	
   
public:
    Grid(int maxx, int maxy){
    	
		if(maxx <=0){
    		this->x= 1;
    	}else{
    		this->x=maxx;
		}
		
		if(maxy <=0){
    		this->y= 1;
    	}else{
    		this->y=maxy;
		}
	};
	
	int Getx(){
		return this->x;
	}
	
	int Gety(){
		return this->x;
	}
    
    
};
bool testeTamanhoGrid(){//teste para a criação do tamanho máximo do grid;

//se o input for menor ou igual a 0 a aplicação deve alterar para no mínimo 1 por 1, caso contrario o teste retorna vermelho(false);  
	
	Grid G1(2,2);
	Grid G2(-1,0);
	
	if ((G1.Getx() != 2) || (G1.Gety() != 2)){
		return false;
	} 
	
	if (G2.Getx() <= 0 || G2.Gety() <=0){
		return false;
	}
	
	return true;
}

void Girar(string S, Sonda& Son){
	
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
	
	Sonda S1,S2,S3,S4,S5;
	
	Girar("L",S1);
	Girar("R",S2);
	Girar("LL",S3);
	Girar("RRR",S4);
	Girar("LRRL",S5);
	
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
	
	
	return 0;
}
