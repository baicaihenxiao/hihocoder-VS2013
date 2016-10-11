#include <math.h>
#include <stdio.h>

int IsCube(long long n)
{
	int root = pow(abs(n), 1.0 / 3);
	
	//printf("-----------%d\n", root);

	long long res = root * root * root;

	if (abs(n) == res)
		return 1;
	else
		return 0;
}

int main()
{
	
	long long input = 0;

	scanf("%ld", &input);

	if (IsCube(input) == 1)
	{
		printf("TRUE\n");
	}
	else
	{
		printf("FALSE\n");
	}

}