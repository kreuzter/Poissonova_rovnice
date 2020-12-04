#pragma once

#include <vector>

using namespace std;

class uzel{
	public:
		int n;
		
		vector<double> xs;
		vector<double> ys;
		
		uzel(int _n1, int _n2, vector<double> _x, vector<double> _y);
};

uzel::uzel(int _n1, int _n2, vector<double> _x, vector<double> _y){
	n = (_n1+1)*(_n2+1);	//pocet uzlu
	

	
	
}

