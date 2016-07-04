/*
2015年11月10日11:08:44


#1000 : A + B
时间限制:1000ms
单点时限:1000ms
内存限制:256MB
描述
求两个整数A+B的和

输入
输入包含多组数据。
每组数据包含两个整数A(1 ≤ A ≤ 100)和B(1 ≤ B ≤ 100)。

输出
对于每组数据输出A+B的和。

样例输入
1 2
3 4
样例输出
3
7


*/

#include "stdafx.h"

#include <stdio.h>

int main(void)
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}

	return 0;
}

