#pragma once

#include <vector>

using namespace std;

class sit{
	public:
		vector<double> x;
		vector<double> y;
		double Ax;
		double Ay;
		double d1;
		double d2;
		double h1;
		double h2;
		int n1;
		int n2;
	
		sit(double _Ax, double _Ay, double _d1, double _d2, int _n1, int _n2);
};

sit::sit(double _Ax, double _Ay, double _d1, double _d2, int _n1, int _n2){
	Ax = _Ax;
	Ay = _Ay;
	d1 = _d1;
	d2 = _d2;
	n1 = _n1;
	n2 = _n2;
	
	h1 = d1/n1;
	h2 = d2/n2;
	
	x.resize(n1);
	y.resize(n2);
	
	for(int i = 0; i <= n1; i++){
		x[i] = Ax + i * h1;
	}
	
	for(int i = 0; i <= n2; i++){
		y[i] = Ay + i * h2;
	}
}
