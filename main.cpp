
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

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

bool testeGirar(){//Teste para verificar a rotação da Sonda;

//A sonda deve iniciar para o norte e se rotacionada para a esquerda deve girar para o oeste;
//Caso rotacionada para a direita deve girar para leste e assim por diante;
	
	Sonda S1,S2,S3,S4,S5;
	
	S1.Girar("L");
	S2.Girar("R");
	S3.Girar("LL");
	S4.Girar("RRR");
	S5.Girar("LRRL")
	
	if(S1.GetDir() != "W") {
		return false;
	}
	
	if(S2.GetDir() != "E") {
		return false;
	}
	
	if(S3.GetDir() != "S") {
		return false;
	}
	
	if(S4.GetDir() != "W") {
		return false;
	}
	
	if(S5.GetDir() != "N") {
		return false;
	}
	
	
	
	
	
	
} 
int main() {
	//Teste do Grid--------------------------------------------
	if(testeTamanhoGrid()){
		cout << "GRID = VERDE" << '\n';
	}else{
		cout << "GRID = VERMELHO" << '\n';
	}
	//----------------------------------------------------------
	
	
	
	
	return 0;
}
