#include<stdio.h>
#include<math.h>

const double Pi = 3.14159265359;

int main()
{
	double A[9][9], T[5][5], somatoria; int i, j, k;
	double hx = 0.5, hy = 0.5;
	
	double b[9] = { -0.5*sqrt(2), -1, -0.5*sqrt(2), 0, 0, 0, 0, 0, 0 };
	double x[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	for (i=0; i<=4; i++)
	{
		T[i][0] = sin(0.5*Pi*hx*i);
		T[i][4] = 0;
	}
	
	for (j=0; j<=4; j++)
	{
		T[0][j] = 0;
		T[4][j] = 0;
	}
	
	for (i=0; i<=8; i++)
	{
		for (j=0; j<=8; j++)
		{
			A[i][j] = 0;
			if (i==j)		A[i][j] = -4;
			
			if (j==i+3)		A[i][j] = 1;
			if (j==i-3)		A[i][j] = 1;
			
			if (j==i+1 && (j-3)%3!=0)		A[i][j] = 1;
			if (j==i+1 && (j-3)%3==0)		A[i][j] = 0;
				
			if (j==i-1 && (j-2)%3!=0)		A[i][j] = 1;
			if (j==i-1 && (j-2)%3==0)		A[i][j] = 0;
		}
	}
	
	for (i=0; i<=8; i++)
	{
		printf("\n");
		for (j=0; j<=8; j++)
			printf("%.0f ", A[i][j]);
	}
	
	for (k=1; k<=10; k++)
	{
		for (i=0; i<=8; i++)
		{
			somatoria = 0;
			for (j=0; j<=8; j++)
				if (j!=i)	somatoria = somatoria + A[i][j]*x[j];
			
			x[i] = 1.0/A[i][i] * ( b[i] - somatoria );
		}
	}
	printf("\n\n\n");	
	
	j = 0;
	
	for (i=0; i<=4; i++)
		printf("%f ", T[i][0]);
	
	printf("\n");
	printf("%f ", T[0][1]);
	for (i=0; i<=8; i++)
	{
		printf("%f ", x[i]);
		if ( (i-2)%3==0 )
		{
			j = j + 1;
			printf("%f \n%f ", T[4][j], T[0][j+1]);
		}			
	}
	
	for (i=1; i<=4; i++)
		printf("%f ", T[i][4]);	
}
