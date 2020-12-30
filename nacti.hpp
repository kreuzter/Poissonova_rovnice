#pragma once

#include <fstream>
#include <sstream>

using namespace std;

double nacti(int n){
	
	ifstream nacitanySoubor("vstupParam.txt");
	
	string line;
	
	int lineno = 0;
	double x;
	
	while(getline(nacitanySoubor, line)){
		lineno++;
		
		if(lineno == n){
		istringstream(line) >> x;
		}
	}
	
	nacitanySoubor.close();
	
	return x;
}
