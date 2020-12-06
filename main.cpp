#include <iostream>
#include <vector>

#include "sit.hpp"

using namespace std;

int main() {
	//Nadpis
	cout << "+++----------------------------------------------+++" << endl << "+++----------------------------------------------+++" << endl << "||| RESENI POISSONOVY ROVNICE METODOU SITI VE 2D |||" << endl << "+++----------------------------------------------+++"<< endl << "+++----------------------------------------------+++" << endl << endl;
	

	sit g(0, 0, 1, 0.6, 10, 6);

	for(int i = 0; i <= g.n2; i++){
		cout << g.y[i] << "\t" ;
	}
	
	cout << endl;
	
	for(int i = 0; i <= g.n1; i++){
		cout << g.x[i] << "\t" ;
	}
	
	cout << endl;
	
	for(int i = 0; i < g.n; i++){
		cout << g.ux[i] << "\t" ;
	}
	
	cout << endl;
	
	for(int i = 0; i < g.n; i++){
		cout << g.uy[i] << "\t" ;
	}

	return 0;
}
