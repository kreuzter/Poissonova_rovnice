#pragma once
#include <fstream>

void doCMDline1(){
	cout << "Spusten vypocet." << endl;
}

void doCMDline2(bool pis){
	cout << "Vypis OP, regularnich uzlu, atd. ";
    if(pis == 1){
    	cout << "je" ;
	}else{
		cout << "neni";
	}
	cout << " pozadovan." << endl;
}

void nadpis(){
	ofstream file("vypis.txt");
	file << "+++----------------------------------------------+++" << endl;
	file << "+++----------------------------------------------+++" << endl;
	file << "||| RESENI POISSONOVY ROVNICE METODOU SITI VE 2D |||" << endl;
	file << "+++----------------------------------------------+++" << endl;
	file << "+++----------------------------------------------+++" << endl << endl;
	file.close();
}

void HvypisOP(string kde, bool pis){
	if(pis == 1){
	ofstream file("vypis.txt", ofstream::app);
	file << endl;
	file << "Prvky na " << kde << ": "<< endl;
	file.close();
	}
}

void vypisOP(int i, float p, bool pis){
	if(pis == 1){
	ofstream file("vypis.txt", ofstream::app);
	file << "Uzel "<< i <<"\t OP: " << p << ", " << endl;
	file.close();
	}
}

void RU(bool pis){
	if(pis == 1){
	ofstream file("vypis.txt", ofstream::app);
	file << endl << "Regularni uzly: " << endl;
	file.close();
	}
}

void RUi(int i, bool pis){
	if(pis == 1){
	ofstream file("vypis.txt", ofstream::app);
	file << i << ", ";
	file.close();
	}
}

void vypisIter(double normar, int m, int iter){
	ofstream file("vypis.txt", ofstream::app);
    file << endl << endl << "normar = " << normar;
    file << endl << "pocet iteraci = " << m << " / " << iter;
    file.close();
}
