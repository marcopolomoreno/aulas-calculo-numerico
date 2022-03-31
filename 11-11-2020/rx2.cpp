#include<stdio.h>
#include<math.h>

const double Pi = 3.14159265359;

int main()
{
	FILE *arquivo;
	arquivo = fopen("dados.txt", "w");
	
	double ht = 0.02, hx = 0.25;
	double T[9][51];
	
	for (int j=0; j<=50; j++)
	{
		T[0][j] = 0;
		T[8][j] = 0;
	}
	
	for (int i=0; i<=3; i++)
		T[i][0] = hx*i;
		
	for (int i=4; i<=8; i++)
		T[i][0] = 2 - hx*i;
		
	for (int j=0; j<=49; j++) //Malha interior
		for (int i=1; i<=7; i++)
			T[i][j+1] = 0.36*T[i][j] + 0.32*( T[i-1][j] + T[i+1][j] );
	
	for (int j=0; j<=50; j++)
	{
		printf("\n");
		fprintf(arquivo, "\n");
		for (int i=0; i<=8; i++)
		{
			printf("%f ", T[i][j]);
			fprintf(arquivo, "%f ", T[i][j]);
		}
			
	}
}
