#include<stdio.h>
#include<math.h>

int main()
{
	FILE *arq;
	arq = fopen("dados.txt", "w");
	
	int i, j, Nx = 81, Nt = 51;
	double hx = 0.2, ht = 0.2, alpha = 1, r;
	double f[Nx][Nt], g[Nx];
	
	r = pow(alpha*ht/hx, 2);
	
	for (j=0; j<=Nt-1; j++)
	{
		f[0][j] = 0;
		f[Nx-1][j] = 0;
	}
	
	for (i=0; i<=Nx-1; i++)
	{
		double x = hx*i;
		f[i][0] = 0;
		g[i] = (12*x - 96) * exp( -2*pow(x-8,2) );
	}
	
	for (j=0; j<=Nt-2; j++)
	{
		for (i=1; i<=Nx-2; i++)
		{
			if (j==0) f[i][1] = ht*g[i] + (1-r)*f[i][0] + 
			                    0.5*r*( f[i-1][0] + f[i+1][0] );
			if (j>0)  f[i][j+1] = -f[i][j-1] + 2*(1-r)*f[i][j] + 
			                    r*( f[i-1][j] + f[i+1][j] );
		}
	}
	
	for (i=0; i<=Nx-1; i++)
	{
		printf("%f ", hx*i);
		fprintf(arq, "%f ", hx*i);
		for (j=0; j<=Nt-1; j++)
		{
			printf("%f ", f[i][j]);
			fprintf(arq, "%f ", f[i][j]);
		}
		printf("\n");
		fprintf(arq, "\n");
	}	
}
