#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMat(int **A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int **joinMat(int **A, int **B, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			B[i][j] = (A[i][j] == 1 || B[i][j] == 1);
	return B;
}

int **compositionMat(int **A, int **B, int n)
{
	int **C = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		C[i] = (int *)calloc(n, sizeof(int));
		memset(C[i], 0, sizeof(C[0]) * n);
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i][j] = C[i][j] | (A[i][k] == 1 && B[k][j] == 1);

	return C;
}

int **TransitiveClosure(int **M, int n)
{
	// Creating A and B
	int **A = (int **)calloc(n, sizeof(int *));
	int **B = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int *)calloc(n, sizeof(int));
		B[i] = (int *)calloc(n, sizeof(int));

		// Initializing A and B by M
		for (int j = 0; j < n; j++)
			A[i][j] = B[i][j] = M[i][j];
	}

	printf("\nR^1:\n");
	printMat(B, n);
	// Transitive Closure
	for (int i = 2; i <= n; i++)
	{
		A = compositionMat(A, M, n);
		B = joinMat(B, A, n);
		printf("\nR^%d:\n", i);
		printMat(B, n);
	}

	return B;
}

int main()
{
	int n, rels;
	printf("Enter the number of rows and columns: ");
	scanf("%d", &n);

	// Creating Graph
	int **M = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		M[i] = (int *)calloc(n, sizeof(int));
		memset(M[i], 0, sizeof(M[0]) * n);
	}

	//Entering Relations
	printf("\nEnter the number of relations: ");
	scanf("%d", &rels);
	printf("\nEnter the relations: \n");
	for (int k = 0; k < rels; k++)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		M[i - 1][j - 1] = 1;
	}

	printf("\n");
	TransitiveClosure(M, n);

	printf("\n\n\n");
	system("pause");
}