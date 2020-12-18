#include <iostream>
#include <vector>
#include <math.h>

#include "sit.hpp"   //definuje tridu sit
#include "vypis.hpp" //obsahuje funkce pro vypis dat
#include "dataToParaview.hpp"

using namespace std;


int main() {
	
	nadpis();

	//levy dolni bod site
	double Ax = 0;
	double Ay = 0;
	
	//rozmer
	double d1 = 3;
	double d2 = 3;
	
	//pocet kroku
	int n1 = 20;
	int n2 = 20;
	
	//definuj funkci vnitrniho rozlozeni
	double INxx = 0;
	double INyy = 0;
	double INxy = 0;
	double INx  = 1;
	double INy  = 1;	
	double IN0  = 0;
	
	//definuj svisle OP
	double VERTyL = 0;
	double VERT0L = 0;
	double VERTyR = 3;
	double VERT0R = 0;
	
	//definuj vodorovne OP
	double HORIZxU = 3;
	double HORIZ0U = 0;
	double HORIZxL = 0;
	double HORIZ0L = 0;	

	sit g(Ax, Ay, d1, d2, n1, n2, INxx, INyy, INxy, INx, INy, IN0, HORIZxU, HORIZ0U, VERTyL, VERT0L, HORIZxL, HORIZ0L, VERTyR, VERT0R);
	g.vypis();

	vector<double> S(g.n*g.n);
	vector<double> p(g.n);
	
	fill(S.begin(), S.end(), 0);
	fill(p.begin(), p.end(), 0);
	
	// vytvarim OP

	HvypisOP("spodni vodorovne");
	for(int i = 0; i <= g.n1; i++){
		S[i*g.n + i] = 1;
		p[i] = g.fceHORIZl()[i];
		//vypisOP(i, p[i]);
	}

	HvypisOP("horni vodorovne");
	for(int i = (g.n-g.n1)-1; i < g.n; i++){
		S[i*g.n + i] = 1;
		p[i] = g.fceHORIZu()[i];
		//vypisOP(i, p[i]);
	}
	
	HvypisOP("leve svisle");

	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == 0){
			S[i*g.n + i] = 1;
			p[i] = g.fceVERTl()[i];	
			//vypisOP(i, p[i]);	
		}		
	}

	HvypisOP("prave svisle");
	
	for(int i = 0; i < g.n; i++){
		if(i % (n1+1) == g.n1){
			S[i*g.n + i] = 1;
			p[i] = g.fceVERTr()[i];	
			//vypisOP(i, p[i]);
		}		
	}
	
	cout << endl;
	//cout << "Regularni uzly: " << endl;
	
	for(int i = g.n1; i < g.n-g.n1; i++){
		if(i % (n1+1) != g.n1 && i % (n1+1) != 0 ){
		S[i*g.n + i] =  2/g.h2 + 2/g.h1;
		S[i*g.n + i - g.n1 - 1] =  - 1/g.h2;
		S[i*g.n + i + g.n1 + 1] =  - 1/g.h2;
		S[i*g.n + i + 1] =  - 1/g.h1;
		S[i*g.n + i - 1] =  - 1/g.h1;
		p[i] = g.fceIN()[i];
		//cout << i << ", "; //podobne jako pro matici
		}
	}	
	cout << endl << endl;
/*

	// tohle nevypisovat pro "rozumne hustou sit"	
	// pro par uzlu proc ne, ale pro vic jak 20 je to kravina
	cout << "Matice soustavy | vektor pravych stran:" << endl;
	for(int i = 0; i < g.n*g.n; i++){
		cout << S[i] << "\t" ;
		if(i%g.n == (g.n-1)){
			cout << "|" << p[i/g.n] << endl ;
		}
	}			

*/	
	int N = g.n - 1;

	vector<double> suma(g.n);
	fill(suma.begin(), suma.end(), 0);

	vector<double> r(g.n);
	fill(r.begin(), r.end(), 0);	
	
	vector<double> rpom(g.n);
	fill(rpom.begin(), rpom.end(), 0);	
	
	double normar = 0;
	
	int m = 0, i, j;
	
	for(int f = 0; f<=20; f++){cout << "-";}
	cout << endl;
	
	do
    {
        m++;
    	if(m%(10000/20) == 0){cout << "|";}
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
    }while ((normar > 0.00001) && (m < 10000));
   
    cout << endl << "normar = " << normar;
    cout << endl << "pocet iteraci = " << m;
    /*
    cout << endl << "r[" << m << "] = [";
    for (int j=0;j<=N;j=j+1)
    {
        cout << r[j];
        if (j<N)
        {
            cout << ", ";
        }
    }
	
    cout << "]T" << endl;
	*/
	printDataToParaview(r, n1+1, n2+1, "vysledky.vtk");
	return 0;
}
