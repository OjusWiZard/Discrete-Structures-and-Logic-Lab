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

	//Intersection
	int *AnB = (int *)malloc((nA<nB ? nA : nB)*sizeof(int));
	int k = 0;
	for (int i = 0; i<nA; i++)
	{
		if (find(B, A[i], nB))
		{
			AnB[k] = A[i];
			k++;
		}
	}

	printf("\nThe Intersection of A and B is: ");
	for (int i = 0; i<k; i++)
	{
		printf("%d ", AnB[i]);
	}
	printf("\n\n");
	system("pause");

	free(A);
	free(B);
	free(AnB);
	return 0;
}