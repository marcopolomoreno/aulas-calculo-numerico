#include<stdio.h>
#include<math.h>

const double Pi = 3.14159265359;

int main()
{
	FILE *arquivo;
	arquivo = fopen("dados.txt", "w");
	
	double ht = 0.1, hx = 0.25;
	double T[5][6];
	
	for (int j=0; j<=5; j++)
	{
		T[0][j] = 0;
		T[4][j] = 0;
	}
	
	for (int i=0; i<=4; i++)
		T[i][0] = 10*sin( Pi*hx*i );
		
	for (int j=0; j<=4; j++) //Malha interior
		for (int i=1; i<=3; i++)
			T[i][j+1] = 0.2*T[i][j] + 0.4*( T[i-1][j] + T[i+1][j] );
	
	for (int j=0; j<=5; j++)
	{
		printf("\n");
		fprintf(arquivo, "\n");
		for (int i=0; i<=4; i++)
		{
			printf("%f ", T[i][j]);
			fprintf(arquivo, "%f ", T[i][j]);
		}
			
	}
}
