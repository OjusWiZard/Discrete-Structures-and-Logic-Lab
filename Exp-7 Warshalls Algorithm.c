#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	int **W = M;
	printf("\nW0 is:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf(" %d", W[i][j]);
		printf("\n");
	}
	// Transitive Closure
	for (int k = 0; k < n; k++)
	{
		printf("\nW%d is:\n", k + 1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				W[i][j] = (W[i][j] == 1) || (W[i][k] == 1 && W[k][j] == 1);
				printf(" %d", W[i][j]);
			}
			printf("\n");
		}
	}

	printf("\n\n\n");
	system("pause");
}