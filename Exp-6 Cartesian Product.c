#include <stdio.h>
#include <stdlib.h>

// Input Set
int *getSet(void)
{
	int nA;
	printf("\nEnter the number of Elements in set: ");
	scanf("%d", &nA);
	int *A = (int *)calloc(nA + 1, sizeof(int));
	A[0] = nA;
	printf("Enter the Elements of set: ");
	for (int i = 1; i <= nA; i++)
	{
		scanf("%d", &A[i]);
	}
	return A;
}

// Cartesian Product of A and B
int **cartesianProduct(int *A, int *B)
{
	int **AxB = (int **)calloc(A[0] * B[0] + 1, sizeof(int *));
	int k = 1;
	int *size = (int *)calloc(1, sizeof(int));
	size[0] = A[0] * B[0];
	AxB[0] = size;

	for (int i = 1; i <= A[0]; i++)
	{
		for (int j = 1; j <= B[0]; j++)
		{
			int *element = (int *)calloc(3, sizeof(int));
			element[0] = 2;
			element[1] = A[i];
			element[2] = B[j];
			AxB[k++] = element;
		}
	}

	return AxB;
}

int main()
{
	int *A = getSet();
	int *B = getSet();

	printf("\n\nCartesian Product A x B = ");
	int **AxB = cartesianProduct(A, B);
	printf("{ ");
	for (int i = 1; i < AxB[0][0]; i++)
	{
		printf("(%d,%d), ", AxB[i][1], AxB[i][2]);
	}
	printf("(%d,%d) }", AxB[AxB[0][0]][1], AxB[AxB[0][0]][2]);

	printf("\n\n\n");
	system("pause");
	return 0;
}