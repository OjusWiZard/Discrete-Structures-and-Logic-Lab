#include <stdio.h>
#include <stdlib.h>

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

// Intersection of two Sets A and B
int *setIntersection(int *A, int *B)
{
	int size = A[0]<B[0] ? A[0]+1 : B[0]+1;
	int *AnB = (int *)calloc(size, sizeof(int));
	int k = 1;
	for (int i = 1; i<=A[0]; i++)
	{
		AnB[0] = k-1;
		if (find(B, A[i]))
		{
			AnB[k] = A[i];
			k++;
		}
	}
	AnB = (int *)realloc(AnB, k*sizeof(int));
	AnB[0] = k-1;
	return AnB;
}

// Difference of Sets, A-B
int *setDifference(int *A, int *B)
{
	int *AminusB = (int *)calloc(A[0]+1, sizeof(int));
	int k = 1;
	for (int i = 1; i<=A[0]; i++)
	{
		if (!find(B, A[i]))
		{
			AminusB[k] = A[i];
			k++;
		}
	}
	AminusB = (int *)realloc(AminusB, k*sizeof(int));
	AminusB[0] = k-1;
	return AminusB;
}

int main()
{
	int *A = getSet();
	int *B = getSet();

	printf("\n\nA^B = (AUB) - (AnB) = ");
	int *AXB = setDifference(setUnion(A, B), setIntersection(A, B));
	for (int i = 1; i<=AXB[0]; i++)
	{
		printf("%d ", AXB[i]);
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}