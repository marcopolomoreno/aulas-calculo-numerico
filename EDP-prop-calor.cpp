#include<stdio.h>
#include<math.h>

const double Pi = 3.14159265359;

int main()
{
	int Nt = 50, Nx = 10;
	double T[Nx+1][Nt+1], x, hx = 0.10, ht = 0.01, alpha = 0.5;
	double r = ht*alpha*alpha/(hx*hx);
	
	for (int j=0; j<=Nt; j++)
	{
		T[0][j] = 0;
		T[Nx][j] = 0;
	}
	
	for (int i=0; i<=Nx; i++)
	{
		x = hx*i;
		T[i][0] = 10*sin(Pi*x);
		//printf("%f ", T[i][0]);
	}
	//printf("\n\n");
	
	for (int j=0; j<=Nt-1; j++)
		for (int i=1; i<=Nx-1; i++)
			T[i][j+1] = (1-2*r)*T[i][j] + r*( T[i-1][j] + T[i+1][j] );

	for (int j=0; j<=Nt; j++)
	{
		printf("\n");
		for (int i=0; i<=Nx; i++)
			printf("%f ", T[i][j]);
	}
}
