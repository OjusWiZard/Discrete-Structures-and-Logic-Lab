#include <stdio.h>
#include <stdlib.h>

// Input Set
int *getSet(void)
{
	int nA;
	printf("\nEnter the number of Elements in set: ");
	scanf("%d", &nA);
	int *A = (int *)calloc(nA+1, sizeof(int));
	A[0] = nA;
	printf("Enter the Elements of set: ");
	for (int i = 1; i<=nA; i++)
	{
		scanf("%d", &A[i]);
	}
	return A;
}

// Power Set of a Set
int **PowerSet(int *A)
{
	int **PowA = (int **)calloc((1<<A[0])+1, sizeof(int *));
	int k = 0, *sizePowA = (int *)malloc(sizeof(int));
	sizePowA[0] = (1<<A[0]);
	PowA[0] = sizePowA;
	while (k<(1<<A[0]))
	{
		int *elementSet = (int *)calloc(__builtin_popcount(k)+1, sizeof(int));
		int ks = 1;
		elementSet[0] = __builtin_popcount(k);
		for (int i = 1; i<=A[0]; i++)
		{
			if ((k>>(i-1))&1)
			{
				elementSet[ks] = A[i];
				ks++;
			}
		}
		PowA[k+1] = elementSet;
		k++;
	}
	return PowA;
}

int main()
{
	int *A = getSet();
	printf("PowerSet of it is:\n");
	int **powA = PowerSet(A);
	for (int i = 1; i<=powA[0][0]; i++)
	{
		for (int j = 1; j<=powA[i][0]; j++)
		{
			printf("%d ", powA[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}