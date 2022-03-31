#include<stdio.h>
#include<math.h>

int main()
{
	FILE *arq;
	arq = fopen("dados.txt", "w");
	
	int i, j, Nx = 6, Nt = 21;
	double hx = 0.4, ht = 0.1, alpha = 1, r;
	double f[Nx][Nt], g = 0;
	
	r = pow(alpha*ht/hx, 2);
	
	for (j=0; j<=Nt-1; j++)
	{
		f[0][j] = 0;
		f[Nx-1][j] = 0;
	}
	
	for (i=0; i<=Nx-1; i++)
	{
		double x = hx*i;
		f[i][0] = x*(2 - x);
	}
	
	for (j=0; j<=Nt-2; j++)
	{
		for (i=1; i<=Nx-2; i++)
		{
			if (j==0) f[i][1] = ht*g + (1-r)*f[i][0] + 
			                    0.5*r*( f[i-1][0] + f[i+1][0] );
			if (j>0)  f[i][j+1] = -f[i][j-1] + 2*(1-r)*f[i][j] + 
			                    r*( f[i-1][j] + f[i+1][j] );
		}
	}
	
	for (i=0; i<=Nx-1; i++)
	{
		printf("\n %f ", hx*i);
		fprintf(arq, "\n %f ", hx*i);
		for (j=0; j<=Nt-1; j++)
		{
			printf("%f ", f[i][j]);
			fprintf(arq, "%f ", f[i][j]);
		}
	}	
}
