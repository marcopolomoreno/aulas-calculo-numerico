#include<stdio.h>
#include<math.h>

const double Pi = 3.14159265359;

int main()
{
	FILE *arq;
	arq = fopen("dados.txt", "w");
	
	int Nx = 50, Nt = 20, i, j;
	double hx = 0.1, ht = 0.1;
	double T[Nx+1][Nt+1], alpha = 0.2;
	double r = alpha*alpha*ht/(hx*hx);
	
	for (j=0; j<=Nt; j++)
	{
		T[0][j] = 0;
		T[Nx][j] = 5*ht*j;
	}
	
	for (i=0; i<=Nx; i++)
		T[i][0] = 5*hx*i - pow(hx*i, 2);
	
	for (j=0; j<=Nt-1; j++)
		for (i=1; i<=Nx-1; i++)
			T[i][j+1] = (1-2*r)*T[i][j] + r*(T[i-1][j] + T[i+1][j]);
			
	for (int j=0; j<=Nt; j++)
	{
		printf("\n");
		fprintf(arq, "\n");
		for (int i=0; i<=Nx; i++)
		{
			printf("%f ", T[i][j]);
			fprintf(arq, "%f ", T[i][j]);
		}			
	}
}
