#include <iostream>
#include <vector>

#include "sit.hpp"
#include "uzel.hpp"


using namespace std;

int main() {
	//Nadpis
	cout << "+++----------------------------------------------+++" << endl << "+++----------------------------------------------+++" << endl << "||| RESENI POISSONOVY ROVNICE METODOU SITI VE 2D |||" << endl << "+++----------------------------------------------+++"<< endl << "+++----------------------------------------------+++" << endl << endl;
	

	sit g(1, 2, 10, 5, 10, 5);

	for(int i = 0; i <= g.n2; i++){
		cout << g.y[i] << "\t" ;
	}
	
	cout << endl;
	
	for(int i = 0; i <= g.n1; i++){
		cout << g.x[i] << "\t" ;
	}

	return 0;
}
