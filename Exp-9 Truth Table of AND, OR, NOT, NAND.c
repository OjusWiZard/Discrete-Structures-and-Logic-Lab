#include <stdio.h>
#include <stdlib.h>

void truthTableAND(int n)
{
	for (int i = 0; i < n; i++)
		printf("%c\t", 'A' + i);
	printf(":\tAND\n");

	for (int i = 0; i < 1 << n; i++)
	{
		int j = i;
		int AND = (j & 1);
		for (int k = 0; k < n; k++)
		{
			printf("%d\t", j & 1);
			AND = (AND & (j & 1));
			j = j >> 1;
		}
		printf(":\t%d\n", AND);
	}
	printf("\n");
}

void truthTableOR(int n)
{
	for (int i = 0; i < n; i++)
		printf("%c\t", 'A' + i);
	printf(":\tOR\n");

	for (int i = 0; i < 1 << n; i++)
	{
		int j = i;
		int OR = (j & 1);
		for (int k = 0; k < n; k++)
		{
			printf("%d\t", j & 1);
			OR = (OR | (j & 1));
			j = j >> 1;
		}
		printf(":\t%d\n", OR);
	}
	printf("\n");
}

void truthTableNOT()
{
	printf("%c\t", 'A');
	printf(":\tNOT\n");

	for (int i = 0; i < 2; i++)
		printf("%d\t:\t%d\n", i, !i);

	printf("\n");
}

void truthTableNAND()
{
	for (int i = 0; i < 2; i++)
		printf("%c\t", 'A' + i);
	printf(":\tNAND\n");

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			printf("%d\t%d\t:\t%d\n", j, i, !(j & i));

	printf("\n");
}

int main()
{
	printf("-1 to exit\n");
	printf("1 <input variables> for AND\n");
	printf("2 <input variables> for OR\n");
	printf("3 for NOT\n");
	printf("4 for NAND\n\n");

	while (1)
	{
		int choice;
		scanf("%d", &choice);

		if (choice == -1)
			break;
		else if (choice == 1)
		{
			int inV;
			scanf("%d", &inV);
			truthTableAND(inV);
		}
		else if (choice == 2)
		{
			int inV;
			scanf("%d", &inV);
			truthTableOR(inV);
		}
		else if (choice == 3)
			truthTableNOT();
		else if (choice == 4)
			truthTableNAND();
	}

	printf("\n\n\n");
	system("pause");
	return 0;
}