#pragma once

#include <vector>

using namespace std;

class sit{
	public:
		vector<float> x;
		vector<float> y;
		vector<float> ux;
		vector<float> uy;
		float Ax;
		float Ay;
		float d1;
		float d2;
		float h1;
		float h2;
		int n1;
		int n2;
		int n;
		float INxx, INyy, INxy,INx, INy, IN0;     //temito parametry definuji funkci rozlozeni uvnitr pole
		float HORIZxU, HORIZ0U, VERTyL, VERT0L, HORIZxL, HORIZ0L, VERTyR, VERT0R;       //temito okrajove podminky
		
		vector<float> fceIN(); //rozlozeni uvnitr pole
		vector<float> fceHORIZu(); //OP vodorovna horni
		vector<float> fceHORIZl();
		vector<float> fceVERTl();  //OP svisla leva
		vector<float> fceVERTr();
		
		void vypis();
	
		sit(float _Ax, float _Ay, float _d1, float _d2, int _n1, int _n2, float _INxx, float _INyy, float _INxy, float _INx, float _INy, float _IN0, 
		float _HORIZxU, float _HORIZ0U, float _VERTyL, float _VERT0L, float _HORIZxL, float _HORIZ0L, float _VERTyR, float _VERT0R);
};

sit::sit(float _Ax, float _Ay, float _d1, float _d2, int _n1, int _n2, float _INxx, float _INyy, float _INxy, float _INx, float _INy, float _IN0, 
float _HORIZxU, float _HORIZ0U, float _VERTyL, float _VERT0L, float _HORIZxL, float _HORIZ0L, float _VERTyR, float _VERT0R){
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

vector<float> sit::fceIN(){
	
	vector<float> fce(n);
	
	for(int i = 0; i <= n-1; i++){
		fce[i] = INxx*ux[i]*ux[i] + INyy*uy[i]*uy[i] + INxy*ux[i]*uy[i] + INx*ux[i] + INy*uy[i] + IN0;
	}
	return fce;
}

vector<float> sit::fceVERTl(){
	
	vector<float> fceVL(n );
	
	for(int i = 0; i <= n-1; i++){
		fceVL[i] = VERTyL*uy[i] + VERT0L;
	}
	return fceVL;
}

vector<float> sit::fceHORIZu(){
	
	vector<float> fceHU(n );
	
	for(int i = 0; i <= n-1; i++){
		fceHU[i] = HORIZxU*ux[i] + HORIZ0U;
	}
	return fceHU;
}

vector<float> sit::fceVERTr(){
	
	vector<float> fceVR(n );
	
	for(int i = 0; i <= n-1; i++){
		fceVR[i] = VERTyR*uy[i] + VERT0R;
	}
	return fceVR;
}

vector<float> sit::fceHORIZl(){
	
	vector<float> fceHL(n );
	
	for(int i = 0; i <= n-1; i++){
		fceHL[i] = HORIZxL*ux[i] + HORIZ0L;
	}
	return fceHL;
}
