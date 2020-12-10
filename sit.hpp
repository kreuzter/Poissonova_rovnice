#pragma once

#include <vector>

using namespace std;

class sit{
	public:
		vector<double> x;
		vector<double> y;
		vector<double> ux;
		vector<double> uy;
		double Ax;
		double Ay;
		double d1;
		double d2;
		double h1;
		double h2;
		int n1;
		int n2;
		int n;
		double INxx, INyy, INxy,INx, INy, IN0;     //temito parametry definuji funkci rozlozeni uvnitr pole
		double HORIZxU, HORIZ0U, VERTyL, VERT0L, HORIZxL, HORIZ0L, VERTyR, VERT0R;       //temito okrajove podminky
		
		vector<double> fceIN(); //rozlozeni uvnitr pole
		vector<double> fceHORIZu(); //OP vodorovna horni
		vector<double> fceHORIZl();
		vector<double> fceVERTl();  //OP svisla leva
		vector<double> fceVERTr();
		
		void vypis();
	
		sit(double _Ax, double _Ay, double _d1, double _d2, int _n1, int _n2, double _INxx, double _INyy, double _INxy, double _INx, double _INy, double _IN0, 
		double _HORIZxU, double _HORIZ0U, double _VERTyL, double _VERT0L, double _HORIZxL, double _HORIZ0L, double _VERTyR, double _VERT0R);
};

sit::sit(double _Ax, double _Ay, double _d1, double _d2, int _n1, int _n2, double _INxx, double _INyy, double _INxy, double _INx, double _INy, double _IN0, 
double _HORIZxU, double _HORIZ0U, double _VERTyL, double _VERT0L, double _HORIZxL, double _HORIZ0L, double _VERTyR, double _VERT0R){
	Ax = _Ax;
	Ay = _Ay;
	d1 = _d1;
	d2 = _d2;
	n1 = _n1;
	n2 = _n2;
	INxx = _INxx;
	INyy = _INyy;
	INxy = _INxy;
	INx = _INx;
	INy =  _INy;
	IN0 = _IN0;
	HORIZxU = _HORIZxU ;
	HORIZ0U = _HORIZ0U;
	HORIZxL = _HORIZxL ;
	HORIZ0L = _HORIZ0L;	
	VERTyL = _VERTyL;
	VERT0L = _VERT0L;
	VERTyR = _VERTyR;
	VERT0R = _VERT0R;	
	
	n = (_n1+1) * (_n2+1);
	h1 = d1/n1;
	h2 = d2/n2;
	
	x.resize(n1+1);
	y.resize(n2+1);
	ux.resize(n);
	uy.resize(n);
	
	// souradnice X site
	for(int i = 0; i <= n1; i++){
		x[i] = Ax + i * h1;
	}
	
	//souradnice Y site
	for(int i = 0; i <= n2; i++){
		y[i] = Ay + i * h2;
	}
	
	//souradnice X uzlu
	int j = 0;
	for(int i = 0; i < n; i++){
		if(i % (n1+1) == 0 && i != 0){
			j++;
		}
		ux[i] = x[i - j*(n1+1)];
	}

	//souradnice Y uzlu
	j = 0;
	for(int i = 0; i <= n-1; i++){
		if(i % (n1+1) == 0 && i != 0){
			j++;
		}
		uy[i] = y[j];
	}
}

void sit::vypis(){
	cout << "Levy dolni bod:  [" << Ax << "; " << Ay << "]" << endl;
	cout << "Rozmery site:    [" << d1 << "; " << d2 << "]" << endl;
	cout << "Krok v x:        " << h1 << endl;
	cout << "Krok v y:        " << h2 << endl;
	cout << "Pocet kroku v x: " << n1 << endl;
	cout << "Pocet kroku v y: " << n2 << endl;
	cout << "Pocet uzlu:      " << n  << endl;		
};

vector<double> sit::fceIN(){
	
	vector<double> fce(n);
	
	for(int i = 0; i <= n-1; i++){
		fce[i] = INxx*ux[i]*ux[i] + INyy*uy[i]*uy[i] + INxy*ux[i]*uy[i] + INx*ux[i] + INy*uy[i] + IN0;
	}
	return fce;
}

vector<double> sit::fceVERTl(){
	
	vector<double> fceVL(n );
	
	for(int i = 0; i <= n-1; i++){
		fceVL[i] = VERTyL*uy[i] + VERT0L;
	}
	return fceVL;
}

vector<double> sit::fceHORIZu(){
	
	vector<double> fceHU(n );
	
	for(int i = 0; i <= n-1; i++){
		fceHU[i] = HORIZxU*ux[i] + HORIZ0U;
	}
	return fceHU;
}

vector<double> sit::fceVERTr(){
	
	vector<double> fceVR(n );
	
	for(int i = 0; i <= n-1; i++){
		fceVR[i] = VERTyR*uy[i] + VERT0R;
	}
	return fceVR;
}

vector<double> sit::fceHORIZl(){
	
	vector<double> fceHL(n );
	
	for(int i = 0; i <= n-1; i++){
		fceHL[i] = HORIZxL*ux[i] + HORIZ0L;
	}
	return fceHL;
}
