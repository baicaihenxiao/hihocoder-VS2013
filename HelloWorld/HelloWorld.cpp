#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* func1()
{
	char* a = (char*)malloc(10 * sizeof(char));

	strcpy(a, "asdf");

	printf("func1: 数组a=<%s>, 地址a=<%p>\n", a, a);


	return a;
}

char* func2()
{
	char a[10] = "zxcv";


	printf("func2: 数组a=<%s>, 地址a=<%p>\n", a, a);

	return a;
}

int main()
{
	
	char* a = func1();

	printf("func1: 数组a=<%s>, 地址a=<%p>\n", a, a);


	//strcpy(a, "1asdf111");

	//printf("func1: 数组a=<%s>, 地址a=<%p>\n", a, a);


	a = func2();

	printf("func2: 数组a=<%s>, 地址a=<%p>\n", a, a);


	return 0;
}