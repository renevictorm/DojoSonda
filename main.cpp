#include <iostream>
using namespace std;



bool testeTamanhoGrid(){//teste para a criação do tamanho máximo do grid;

//se o input for menor ou igual a 0 a aplicação deve alterar para no mínimo 1 por 1, caso contrario o teste retorna vermelho(false);  
	
	grid G1(2,2);
	grid G2(-1,0);
	
	if (G1.x != 2 || G1.y != 2){// se
		return = false;
	} 
	
	if (G2.x <= 0 || G2.y <=0){
		return = false;
	}
	
	
}


int main() {
	return 0;
}
