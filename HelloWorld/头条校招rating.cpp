/*
����:
4
20 35 23 40
�����
2

����ڶ�����4����Ŀ��Ӧ��ratingֵ��ÿ������Ҫ���������rating����a<=b<=c,b-a<=10,c-b<=10,Ŀ����������Ӷ��ٵ����������е���Ŀȫ��Ӧ�õ������



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