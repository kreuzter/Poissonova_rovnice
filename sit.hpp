#pragma once

#include <vector>

using namespace std;

class sit{
	public:
		double h;				//krok site
		double Ax;
		double Ay;
		double Bx;
		double By;
		double Cx;
		double Cy;
		double Dx;
		double Dy;
		
		sit(double _Ax, double _Ay, double _Bx, double _By, double _Cx, double _Cy, double _Dx, double _Dy, int _h);
};

sit::sit(double _Ax, double _Ay, double _Bx, double _By, double _Cx, double _Cy, double _Dx, double _Dy, int _h){
	Ax = _Ax;
	Ay = _Ax;
	Bx = _Ax;
	By = _Ax;
	Cx = _Ax;
	Cy = _Ax;
	Dx = _Ax;
	Dy = _Ax;
	h = _h;
}
