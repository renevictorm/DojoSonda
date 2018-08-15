
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
	
	if ((G1.Getx() != 2) || (G1.Gety() != 2)){// se
		return false;
	} 
	
	if (G2.Getx() <= 0 || G2.Gety() <=0){
		return false;
	}
	
	return true;
}


int main() {
	
	if(testeTamanhoGrid()){
		cout << "VERDE" << '\n';
	}else{
		cout << "VERMELHO" << '\n';
	}
	
	
	return 0;
}
