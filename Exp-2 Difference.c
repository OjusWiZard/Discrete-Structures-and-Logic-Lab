#include <stdio.h>
#include <stdlib.h>

// Linear Search
int find(int *Set, int key, int size)
{
	int found = 0;
	for (int i = 0; i<size; i++)
	{
		if (Set[i]==key)
		{
			found = 1;
			break;
		}
	}
	return found;
}

int main()
{
	int nA, nB;
	printf("Enter the number of Elements in set A: ");
	scanf("%d", &nA);
	printf("Enter the number of Elements in set B: ");
	scanf("%d", &nB);

	int *A = (int *)malloc(nA*sizeof(int)), *B = (int *)malloc(nB*sizeof(int));
	printf("\nEnter the Elements of set A: ");
	for (int i = 0; i<nA; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("Enter the Elements of set B: ");
	for (int i = 0; i<nB; i++)
	{
		scanf("%d", &B[i]);
	}

	//AminusB
	int *AminusB = (int *)malloc((nA)*sizeof(int));
	int nAminusB = 0;
	for (int i = 0; i<nA; i++)
	{
		if (!find(B, A[i], nB))
		{
			AminusB[nAminusB] = A[i];
			nAminusB++;
		}
	}

	//BminusA
	int *BminusA = (int *)malloc((nB)*sizeof(int));
	int nBminusA = 0;
	for (int i = 0; i<nB; i++)
	{
		if (!find(A, B[i], nA))
		{
			BminusA[nBminusA] = B[i];
			nBminusA++;
		}
	}

	printf("\nA-B is: ");
	for (int i = 0; i<nAminusB; i++)
	{
		printf("%d ", AminusB[i]);
	}
	printf("\nB-A is: ");
	for (int i = 0; i<nBminusA; i++)
	{
		printf("%d ", BminusA[i]);
	}
	printf("\n\n");
	system("pause");

	free(A);
	free(B);
	free(AminusB);
	free(BminusA);
	return 0;
}