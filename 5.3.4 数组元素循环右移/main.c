#include <stdio.h>

void shift(int array[], int n)
{
	int i, array_end;
	array_end = array[n - 1];
	for (i = n - 1; i > 0; i --)
	{
		array[i] = array[i - 1];
	}
	array[0] = array_end;
}

void main()
{
	int number[100], n, m, i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; ++ i)
	{
		scanf("%d", &number[i]);
	}

	m %= n;
	m = n - m;

	for (i = 0; i < m; i ++)
	{
		shift(number, n);
	}

	for (i = 0; i < n - 1; ++ i)
	{
		printf("%d,", number[i]);
	}
	printf("%d\n", number[n - 1]);

}