#pragma once

#include <fstream>
#include <sstream>

using namespace std;

double nacti(int n){
	
	ifstream nacitanySoubor("input.txt");
	
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

int nactiINT(int n){
	
	ifstream nacitanySoubor("input.txt");
	
	string line;
	
	int lineno = 0;
	int x;
	
	while(getline(nacitanySoubor, line)){
		lineno++;
		
		if(lineno == n){
		istringstream(line) >> x;
		}
	}
	
	nacitanySoubor.close();
	
	return x;
}

int nactiBOOL(int n){
	
	ifstream nacitanySoubor("input.txt");
	
	string line;
	
	int lineno = 0;
	bool x;
	
	while(getline(nacitanySoubor, line)){
		lineno++;
		
		if(lineno == n){
		istringstream(line) >> x;
		}
	}
	
	nacitanySoubor.close();
	
	return x;
}
