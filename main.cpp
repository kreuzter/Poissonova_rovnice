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
	int n1 = 5;
	int n2 = 3;
	
	//definuj funkci vnitrniho rozlozeni
	double INxx = 0;
	double INyy = 0;
	double INxy = 2;
	double INx  = 0;
	double INy  = 0;	
	double IN0  = 2;
	
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
	
	cout << "Krok v x: " << g.h1 << endl;
	cout << "Krok v y: " << g.h2 << endl;
	
	double S[g.n][g.n] = {{0}}; //matice soustavy - vynulovana
	double p[g.n] = {0};          //vektor pravych stran - vynulovany
	
	cout << "Prvky na spodni vodorovne: ";
	
	for(int i = 0; i <= g.n1; i++){
		S[i][i] = 1;
		p[i] = g.fceHORIZl()[i];
		cout << i << ", ";
	}
	
	cout << endl;
	cout << "Prvky na horni vodorovne: ";
	
	for(int i = (g.n-g.n1)-1; i < g.n; i++){
		S[i][i] = 1;
		p[i] = g.fceHORIZu()[i];
		cout << i << ", ";
	}
	
	cout << endl;
	cout << "Prvky na leve svisle: ";

	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == 0){
			S[i][i] = 1;
			p[i] = g.fceVERTl()[i];	
			cout << i << ", ";		
		}		
	}

	cout << endl;
	cout << "Prvky na prave svisle: ";
	
	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == g.n1){
			S[i][i] = 1;
			p[i] = g.fceVERTr()[i];	
			cout << i << ", ";		
		}		
	}	

	cout << endl;
	cout << "Regularni uzly: ";
	
	for(int i = g.n1; i < g.n-g.n1; i++){
		if(i % (n1+1) != g.n1 && i % (n1+1) != 0 ){
		S[i][i] =  2/g.h2 + 2/g.h1;
		S[i][i - g.n1 - 1] =  - 1/g.h2;
		S[i][i + g.n1 + 1] =  - 1/g.h2;
		S[i][i+1] =  - 1/g.h1;
		S[i][i-1] =  - 1/g.h1;
		p[i] = g.fceIN()[i];
		cout << i << ", ";
		}
	}	
	cout << endl;

	cout << "Matice soustavy | vektor pravych stran:" << endl;
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j < g.n; j++){
			
			if(S[i][j]*S[i][j] < 1e-180){
				S[i][j] = 0;
			}
		
		cout << S[i][j] << "\t" ;
		}
		cout << "|" << p[i] << endl ;
	}

	return 0;
}
