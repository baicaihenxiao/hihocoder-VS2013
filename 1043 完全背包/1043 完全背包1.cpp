/*
2016Äê2ÔÂ5ÈÕ10:52:34

*/


#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;

int need[510] = { 0 };
int value[510] = { 0 };
int dp[510][100010] = { 0 };//10^5/500

int main()
{

	freopen("../test.txt", "r", stdin);

	int N, M;

	int i, j, k;

	cin >> N >> M;

	for (i = 1; i <= N; ++i)
	{
		cin >> need[i] >> value[i];
	}

	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= M; ++j)
		{
			int maxK = j / need[i];

			for (k = 0; k <= maxK; ++k)
			{
				int tmp = (value[i] * k + dp[i - 1][j - need[i] * k]);
				if (tmp > dp[i][j])
				{
					dp[i][j] = tmp;
				}
			}

		}
	}

	cout << dp[N][M] << endl;

	return 0;
}
