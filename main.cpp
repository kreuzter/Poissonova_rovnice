#include <iostream>
#include <cmath>
#include <vector>

#include "sit.hpp"

using namespace std;

int main() {
	//Nadpis
	cout << "+++----------------------------------------------+++" << endl << "+++----------------------------------------------+++" << endl << "||| RESENI POISSONOVY ROVNICE METODOU SITI VE 2D |||" << endl << "+++----------------------------------------------+++"<< endl << "+++----------------------------------------------+++" << endl << endl;
	
	//Schema site
	cout << "C- - - -D" << endl << "| | | | | \\" << endl << " - - - - - " << endl << "| | | | | | \\" << endl << " - - - - - - " << endl << "| | | | | | | \\" << endl << " - - - - - - - " << endl << "| | | | | | | | \\" << endl << "A- - - - - - - -B" << endl << endl;
	
	//Zadani krajnich bodu a kroku site
	vector<double> A(2);
	vector<double> B(2);
	vector<double> C(2);
	vector<double> D(2);
	double h;
	cout << "Zadani souradnic [x,y] krajnich bodu (bez mezery):" << endl;
	cout << "A = ";
	cin >> A[0] >> A[1];
	cout << "B = ";
	cin >> B[0] >> B[1];
	cout << "C = ";
	cin >> C[0] >> C[1];
	cout << "D = ";
	cin >> D[0] >> D[1];
	cout << endl << "Zadani kroku site:" << endl;
	cout << "h = ";
	cin >> h;

	
	return 0;
}
