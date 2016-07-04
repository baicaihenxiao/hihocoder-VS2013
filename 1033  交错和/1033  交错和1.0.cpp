#include <stdio.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

const int DIGIT = 23;//当前位数
const int DIGIT_VALUE = 13;//当前位数的数值
const int JIAOCUOHE = 710;//交错和，这里数组稍微定大一些
const int REAL_JIAOCUOHE = 700;//实际用到的交错和上限

const int NEGTIVE_INFINITY = -1;//

long long dict[DIGIT][DIGIT_VALUE][JIAOCUOHE] = { 0 };//

int main()
{
	freopen("F:\\DocCenter\\ProjectFile\\c++\\vs2013\\hihocoder\\test.txt", "r", stdin);

	long l, r;
	int k, i, j;

	int larray[20], rarray[20];
	int bit = 1;//1为奇数，最后一位以 加法 运算

	cin >> l >> r >> k;

	for (i = 1; i < 20 && l != 0; ++ i)
	{
		larray[i] = l % 10;
		l /= 10;
	}

	if (i % 2 == 1)
	{
		bit = -1;
	}

	cout << larray << endl;
	cout << i;

	
	for (int i = 0; i <= 9; ++ i)
	{
		for (int j = 0; j <= REAL_JIAOCUOHE; ++j)
		{
			dict[1][i][j] = NEGTIVE_INFINITY;
		}
	}

	for (int i = 0; i <= 9; ++ i)
	{

	}

	for (int i = 1; i <= 20; ++ i)
	{
		for (int j = 0; j <= 9; ++ j)
		{
			for (int k = 1; k <= 700; ++ k)
			{
				for (int tmp = 0; tmp < 10; ++ tmp)
				{
					dict[i][j][k] += dict[i - 1][tmp][k - ]
				}
			}
		}
	}

}