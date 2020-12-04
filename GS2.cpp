#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int i,j,m;
    
    double Q[3][3] = {
        {2,1,-1},
        {1,2,1},
        {-1,-1,2}
    };
    
    int N = sizeof(Q)/sizeof(Q[0]);
    int n = N - 1;
    
    double p[N],x[N][10000],suma[N],normax;
    
    for(int i = 0; i <= n; i++){
			cout << "Zadej prvek vektoru p " << i << " : ";
			cin >> p[i];
		}
	
	m=0;
	for(int i = 0; i <= n; i++){
			x[i][m]=0;
		}
    
    do
    {
        m = m + 1;
    
    	for (j = 0; j <= n; j = j + 1)
        	{
            	suma[j] = 0;
            
            	// x0 (=x1)
            	if ((j == 0))
            	{
                	for (i = 1; i <= n; i++)
                	{
                    	suma[j] = suma[j] + (Q[j][i]*x[i][m - 1]);
                	}
                	x[j][m] = (1/Q[j][j])*(p[j] - suma[j]);
            	}
            
            	// x1,...,xn-1
            	else if ((j > 0) && (j < n))
            	{
            	    for (i = 0; i < j; i++)
                	{
                    	suma[j] = suma[j] + (Q[j][i]*x[i][m]);
                	}
                	for (i = j + 1; i <= n; i++)
                	{
                    	suma[j] = suma[j] + (Q[j][i]*x[i][m - 1]);
                	}
                	x[j][m] = (1/Q[j][j])*(p[j] - suma[j]);
            	}
            
            	// xn
            	else if ((j == n))
            	{
                	for (i = 0; i < n; i++)
                	{
                    	suma[j] = suma[j] + (Q[j][i]*x[i][m]);
                	}
                	x[j][m] = (1/Q[j][j])*(p[j] - suma[j]);
            	}
        	}
        normax=0;
		for(j=0;j<=n;j=j+1)
        	{
            	normax = normax + pow(x[j][m]-x[j][m-1],2);
        	}
        normax = sqrt(normax);	
        	
    }while ((normax > 0.00001) && (m < 10000));
    
    cout << endl << "x[" << m << "] = [";
    for (j=0;j<=n;j=j+1)
    {
        cout << x[j][m];
        if (j<n)
        {
            cout << ", ";
        }
    }
    cout << "]T" << endl;
    
    return 0;
}
