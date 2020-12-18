#ifndef DATATOPARAVIEW_H
#define DATATOPARAVIEW_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// autor: T. Halada

void printDataToParaview(std::vector<double> data, int pocetBoduSiteX, int pocetBoduSiteY, std::string nazevSouboru)
{

	const int pocPoli = 1;

	int sitParaviewX = pocetBoduSiteX + 1;
	int sitParaviewY = pocetBoduSiteY + 1;
	int pocBunek = (pocetBoduSiteX)*(pocetBoduSiteY);

	std::ofstream file;
	file.open(nazevSouboru.c_str());

	file << "# vtk DataFile Version 3.0" << std::endl;
	file << "vtk output" << std::endl;
	file << "ASCII" << std::endl;
	file << "DATASET STRUCTURED_GRID" << std::endl;
	file << "DIMENSIONS "<< sitParaviewX << " " << sitParaviewY << " 1" << std::endl;
	file << "POINTS " << sitParaviewX*sitParaviewY << " float" << std::endl;

	for(int i=0;i<sitParaviewX;i++)
		for(int j=0;j<sitParaviewY;j++)
			file << i << " " << j << " 0" << std::endl;

	file << "CELL_DATA " << pocBunek << std::endl;
	file << "FIELD FieldData " << pocPoli << std::endl;

	file << "teplota 1 " << pocBunek << " float" << std::endl;
	for(int i=0;i<pocBunek;i++)
		//for(int j=0;j<pocetBoduSiteY;j++)
				file << data[i] << std::endl; //<------------------ TADY, pozor na indexování

	file.close();
}

#endif

