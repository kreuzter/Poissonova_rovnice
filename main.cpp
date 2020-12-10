#include <iostream>
#include <vector>

#include "sit.hpp"   //definuje tridu sit
#include "vypis.hpp" //obsahuje funkce pro vypis dat

using namespace std;


int main() {
	
	nadpis();

	//levy dolni bod site
	double Ax = 0;
	double Ay = 0;
	
	//rozmer
	double d1 = 30.0;
	double d2 = 50.0;
	
	//pocet kroku
	int n1 = 170;
	int n2 = 170;
	
	//definuj funkci vnitrniho rozlozeni
	double INxx = 0;
	double INyy = 0;
	double INxy = 2;
	double INx  = 0;
	double INy  = 0;	
	double IN0  = 0;
	
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
	g.vypis();

	// tvorim pole pro soustavu rovnic
	vector<double> S;
	vector<double> p;
	
	// nastavuji velikost
	S.resize(g.n*g.n);
	p.resize(g.n);
	
	// nuluji
	for(int i = 0; i < g.n * g.n; i++){
		S[i] = 0;
	}
	for(int i = 0; i < g.n; i++){
		p[i] = 0;
	}
	
	// vytvarim OP

	HvypisOP("spodni vodorovne");
	for(int i = 0; i <= g.n1; i++){
		S[i*g.n + i] = 1;
		p[i] = g.fceHORIZl()[i];
		vypisOP(i, p[i]);
	}

	HvypisOP("horni vodorovne");
	for(int i = (g.n-g.n1)-1; i < g.n; i++){
		S[i*g.n + i] = 1;
		p[i] = g.fceHORIZu()[i];
		vypisOP(i, p[i]);
	}
	
	HvypisOP("leve svisle");

	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == 0){
			S[i*g.n + i] = 1;
			p[i] = g.fceVERTl()[i];	
			vypisOP(i, p[i]);	
		}		
	}

	HvypisOP("prave svisle");
	
	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == g.n1){
			S[i*g.n + i] = 1;
			p[i] = g.fceVERTr()[i];	
			vypisOP(i, p[i]);
		}		
	}
	
	cout << endl;
	//cout << "Regularni uzly: " << endl;
	
	for(int i = g.n1; i < g.n-g.n1; i++){
		if(i % (n1+1) != g.n1 && i % (n1+1) != 0 ){
		S[i*g.n + i] =  2/g.h2 + 2/g.h1;
		S[i*g.n + i - g.n1 - 1] =  - 1/g.h2;
		S[i*g.n + i + g.n1 + 1] =  - 1/g.h2;
		S[i*g.n + i + 1] =  - 1/g.h1;
		S[i*g.n + i - 1] =  - 1/g.h1;
		p[i] = g.fceIN()[i];
		//cout << i << ", "; //podobne jako pro matici
		}
	}	
	cout << endl << endl;

/*
	// tohle nevypisovat pro "rozumne hustou sit"	
	// pro par uzlu proc ne, ale pro vic jak 20 je to kravina
	cout << "Matice soustavy | vektor pravych stran:" << endl;
	for(int i = 0; i < g.n*g.n; i++){
		cout << S[i] << "\t" ;
		if(i%g.n == (g.n-1)){
			cout << "|" << p[i/g.n] << endl ;
		}
	}			


*/
	return 0;
}
