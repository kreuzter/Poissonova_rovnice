#include <iostream>
#include <vector>
#include <math.h>

#include "sit.hpp"   //definuje tridu sit
#include "vypis.hpp" //obsahuje funkce pro vypis dat
#include "dataToParaview.hpp"
#include "nacti.hpp"

using namespace std;


int main() {
	
	doCMDline1();
	nadpis();

	int n1, n2;
	double Ax, Ay, d1, d2, INxx, INyy, INxy, INx, INy, IN0, HORIZxU, HORIZ0U, VERTyL, VERT0L, HORIZxL, HORIZ0L, VERTyR, VERT0R;
	bool pis;
	
	Ax = nacti(6);
	Ay = nacti(9);
	d1 = nacti(14);
	d2 = nacti(17);
	n1 = nactiINT(22);	
	n2 = nactiINT(25);
	
	INxx = nacti(30);
	INyy = nacti(33);
	INxy = nacti(36);
	INx  = nacti(39);
	INy  = nacti(42);	
	IN0  = nacti(45);
	
	VERTyL = nacti(50);
	VERT0L = nacti(53);
	VERTyR = nacti(56);
	VERT0R = nacti(59);
	
	HORIZxU = nacti(64);
	HORIZ0U = nacti(67);
	HORIZxL = nacti(70);
	HORIZ0L = nacti(73);
	
	pis = nactiBOOL(78);
	
	doCMDline2(pis);	
	
	sit g(Ax, Ay, d1, d2, n1, n2, INxx, INyy, INxy, INx, INy, IN0, HORIZxU, HORIZ0U, VERTyL, VERT0L, HORIZxL, HORIZ0L, VERTyR, VERT0R);
	g.vypis();

	vector<double> S(g.n*g.n);
	vector<double> p(g.n);
	
	fill(S.begin(), S.end(), 0);
	fill(p.begin(), p.end(), 0);
	
	// vytvarim OP

	HvypisOP("spodni vodorovne", pis);
	for(int i = 0; i <= g.n1; i++){
		S[i*g.n + i] = 1;
		p[i] = g.fceHORIZl()[i];
		vypisOP(i, p[i], pis);
	}

	HvypisOP("horni vodorovne", pis);
	for(int i = (g.n-g.n1)-1; i < g.n; i++){
		S[i*g.n + i] = 1;
		p[i] = g.fceHORIZu()[i];
		vypisOP(i, p[i], pis);
	}
	
	HvypisOP("leve svisle", pis);

	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == 0){
			S[i*g.n + i] = 1;
			p[i] = g.fceVERTl()[i];	
			vypisOP(i, p[i], pis);	
		}		
	}

	HvypisOP("prave svisle", pis);
	
	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == g.n1){
			S[i*g.n + i] = 1;
			p[i] = g.fceVERTr()[i];	
			vypisOP(i, p[i], pis);
		}		
	}
	
	RU(pis);
	
	for(int i = g.n1; i < g.n-g.n1; i++){
		if(i % (n1+1) != g.n1 && i % (n1+1) != 0 ){
		S[i*g.n + i] =  2/g.h2 + 2/g.h1;
		S[i*g.n + i - g.n1 - 1] =  - 1/g.h2;
		S[i*g.n + i + g.n1 + 1] =  - 1/g.h2;
		S[i*g.n + i + 1] =  - 1/g.h1;
		S[i*g.n + i - 1] =  - 1/g.h1;
		p[i] = g.fceIN()[i];
		RUi(i, pis);
		}
	}	
	cout << endl << endl;

	int N = g.n - 1;

	vector<double> suma(g.n);
	fill(suma.begin(), suma.end(), 0);

	vector<double> r(g.n);
	r = p;
	
	vector<double> rpom(g.n);
	rpom = p;
	
	double normar = 0;
	
	int m = 0, i, j;
	int iter = 10000;
	
	for(int f = 0; f<20; f++){cout << "-";}
	cout << endl;
	
	do
    {
        m++;
        
    	if(m%(iter/20) == 0){cout << "|";}
    	fill(suma.begin(), suma.end(), 0);
    	
		normar = 0;
		for (j = 0; j <= N; j++)
        	{
            	suma[j] = 0;
            
            	// r0 (=r1)
            	if ((j == 0))
            	{
                	for (i = 1; i <= N; i++)
                	{
                    	suma[j] = suma[j] + (S[j*g.n+i]*rpom[i]);
                	}
                	r[j] = (1/S[j*g.n+j])*(p[j] - suma[j]);
            	}
            
            	// r1,...,rn-1
            	else if ((j > 0) && (j < N))
            	{
            	    for (i = 0; i < j; i++)
                	{
                    	suma[j] = suma[j] + (S[j*g.n+i]*r[i]);
                	}
                	for (int i = j + 1; i <= N; i++)
                	{
                    	suma[j] = suma[j] + (S[j*g.n+i]*rpom[i]);
                	}
                	r[j] = (1/S[j*g.n+j])*(p[j] - suma[j]);
            	}
            
            	// rn
            	else if ((j == N))
            	{
                	for (i = 0; i < N; i++)
                	{
                    	suma[j] = suma[j] + (S[j*g.n+i]*r[i]);
                	}
					
                	r[j] = (1/S[j*g.n+j])*(p[j] - suma[j]);
				}
        	}
        normar = 0;
		for(j=0;j<=N;j++)
        	{
            	normar = normar+pow(r[j]-rpom[j],2);
        	}
        rpom = r;     	
		    	
    }while ((normar > 1e-10) && (m < iter));
    normar = sqrt(normar);
	vypisIter(normar, m, iter);

	printDataToParaview(r, n1+1, n2+1, "vysledky.vtk");
	return 0;
}
