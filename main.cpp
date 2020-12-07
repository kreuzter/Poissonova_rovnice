#include <iostream>
#include <vector>

#include "sit.hpp"

using namespace std;

int main() {
	//Nadpis
	cout << "+++----------------------------------------------+++" << endl;
	cout << "+++----------------------------------------------+++" << endl;
	cout << "||| RESENI POISSONOVY ROVNICE METODOU SITI VE 2D |||" << endl;
	cout << "+++----------------------------------------------+++" << endl;
	cout << "+++----------------------------------------------+++" << endl << endl;
	
	//levy dolni bod site
	double Ax = 0;
	double Ay = 0;
	
	//rozmer
	double d1 = 0.1;
	double d2 = 0.1;
	
	//pocet kroku
	int n1 = 10;
	int n2 = 10;
	
	//definuj funkci vnitrniho rozlozeni
	double INxx = 0;
	double INyy = 0;
	double INxy = 2;
	double INx = 0;
	double INy = 0;	
	double IN0 = 2;
	
	//definuj svisle OP
	double VERTyL = 0;
	double VERT0L = 1;
	double VERTyR = 0;
	double VERT0R = 1;
	
	//definuj vodorovne OP
	double HORIZxU = 0;
	double HORIZ0U = 1;
	double HORIZxL = 0;
	double HORIZ0L = 1;	

	sit g(Ax, Ay, d1, d2, n1, n2, INxx, INyy, INxy, INx, INy, IN0, HORIZxU, HORIZ0U, VERTyL, VERT0L, HORIZxL, HORIZ0L, VERTyR, VERT0R);

/*
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
*/

	vector<double> a(g.n);
	a = g.fceVERTl();
	cout << g.ux[20] << "\t" << g.uy[20] << "\t" << a[11] << endl;
	
	return 0;
}
