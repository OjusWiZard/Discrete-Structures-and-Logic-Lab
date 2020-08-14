#include <stdio.h>
#include <stdlib.h>

// Input Set
int *getSet(void)
{
	int nA;
	printf("\nEnter the number of Elements in set: ");
	scanf("%d", &nA);
	int *A = (int *)calloc(nA, sizeof(int)+1);
	A[0] = nA;
	printf("Enter the Elements of set: ");
	for (int i = 1; i<=nA; i++)
	{
		scanf("%d", &A[i]);
	}
	return A;
}

// Linear Search
int find(int *Set, int key)
{
	int found = 0;
	for (int i = 1; i<=Set[0]; i++)
	{
		if (Set[i]==key)
		{
			found = 1;
			break;
		}
	}
	return found;
}

// Checks if the two Sets are Equal
int areEqual(int *A, int *B)
{
	int equal = 1;
	for (int i = 1; i<=A[0]; i++)
	{
		if (!find(B, A[i]))
			equal = 0;
	}
	for (int i = 1; i<=B[0]; i++)
	{
		if (!find(A, B[i]))
			equal = 0;
	}
	return equal;
}

// Linear Search on Power Sets
int findSet(int **powSet, int *set)
{
	int found = 0;
	for (int i = 1; i<=powSet[0][0]; i++)
	{
		if (areEqual(powSet[i], set))
		{
			found = 1;
			break;
		}
	}
	return found;
}

// Union of two Sets A and B
int *setUnion(int *A, int *B)
{
	int *AUB = (int *)calloc(A[0]+B[0]+1, sizeof(int));
	int k = 1;
	for (int i = 1; i<=A[0]; i++)
	{
		AUB[k] = A[i];
		k++;
	}
	for (int i = 1; i<=B[0]; i++)
	{
		AUB[0] = k-1;
		if (!find(AUB, B[i]))
		{
			AUB[k] = B[i];
			k++;
		}
	}
	AUB = (int *)realloc(AUB, k*sizeof(int));
	AUB[0] = k-1;
	return AUB;
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

// Checks if two Power Sets are Equal
int arePowerSetEqual(int **A, int **B)
{
	int equal = 1;
	for (int i = 1; i<=A[0][0]; i++)
	{
		if (!findSet(B, A[i]))
			equal = 0;
	}
	for (int i = 1; i<=B[0][0]; i++)
	{
		if (!findSet(A, B[i]))
			equal = 0;
	}
	return equal;
}

// Union of two Power Sets A and B
int **powerSetUnion(int **A, int **B)
{
	int **AUB = (int **)calloc(A[0][0]+B[0][0]+1, sizeof(int *));
	int k = 1, *sizeAUB = (int *)malloc(sizeof(int));
	sizeAUB[0] = A[0][0]+B[0][0];
	AUB[0] = sizeAUB;
	for (int i = 1; i<=A[0][0]; i++)
	{
		AUB[k] = A[i];
		k++;
	}
	for (int i = 1; i<=B[0][0]; i++)
	{
		AUB[0][0] = k-1;
		if (!findSet(AUB, B[i]))
		{
			AUB[k] = B[i];
			k++;
		}
	}
	AUB = (int **)realloc(AUB, k*sizeof(int *));
	AUB[0][0] = k-1;
	return AUB;
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

	int *B = getSet();
	printf("PowerSet of it is:\n");
	int **powB = PowerSet(B);
	for (int i = 1; i<=powB[0][0]; i++)
	{
		for (int j = 1; j<=powB[i][0]; j++)
		{
			printf("%d ", powB[i][j]);
		}
		printf("\n");
	}

	printf("\n\nL.H.S. = P(A) U P(B) =\n");
	int **LHS = powerSetUnion(powA, powB);
	for (int i = 1; i<=LHS[0][0]; i++)
	{
		for (int j = 1; j<=LHS[i][0]; j++)
		{
			printf("%d ", LHS[i][j]);
		}
		printf("\n");
	}

	printf("\nR.H.S. = P(AUB) =\n");
	int **RHS = PowerSet(setUnion(A, B));
	for (int i = 1; i<=RHS[0][0]; i++)
	{
		for (int j = 1; j<=RHS[i][0]; j++)
		{
			printf("%d ", RHS[i][j]);
		}
		printf("\n");
	}

	printf("\nHence, ");
	if (arePowerSetEqual(LHS, RHS))
		printf("L.H.S. = R.H.S.");
	else
		printf("L.H.S. != R.H.S.");

	printf("\n\n\n");
	system("pause");
	return 0;
}