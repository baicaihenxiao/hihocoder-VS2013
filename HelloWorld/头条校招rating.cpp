/*
输入:
4
20 35 23 40
输出：
2

输入第二行是4个题目对应的rating值，每场考试要求三道题的rating满足a<=b<=c,b-a<=10,c-b<=10,目的是最少添加多少道题能让已有的题目全部应用到考试里。



*/

#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;


int main()
{
	int n;
	vector<int> data;
	data.reserve(100010);

	int tmp;
	long long res = 0;

	scanf("%d\n", &n);

	for (int i = 0; i != n; ++i)
	{
		scanf("%d", &tmp);
		data.push_back(tmp);
	}
	sort(data.begin(), data.end());

	tmp = 0;

	for (int i = 0; i < n; ++i)
	{
		if (tmp == 0)
		{
			++tmp;
			continue;
		}

		if (data[i] - data[i - 1] <= 10)
		{
			++tmp;

			if (tmp == 3)
			{
				tmp = 0;
				//++ i;
			}

		}
		else
		{
			if (tmp == 2)
			{
				++res;
				tmp = 1;
				//++i;
			}
			else if (tmp == 1)
			{
				if (data[i] - data[i - 1] <= 20)
				{
					++res;
					tmp = 0;
					//++i;
				}
				else
				{
					res += 2;
					tmp = 1;
					--i;

				}
			}

		}
	}
	//std::cout << tmp << endl;

	std::cout << (res + 3 - tmp) << endl;


}