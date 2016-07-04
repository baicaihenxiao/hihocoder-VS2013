/*
2016年2月2日19:36:39


#1043 : 完全背包
时间限制:20000ms
单点时限:1000ms
内存限制:256MB
描述

且说之前的故事里，小Hi和小Ho费劲心思终于拿到了茫茫多的奖券！而现在，终于到了小Ho领取奖励的时刻了！

等等，这段故事为何似曾相识？这就要从平行宇宙理论说起了………总而言之，在另一个宇宙中，小Ho面临的问题发生了细微的变化！

小Ho现在手上有M张奖券，而奖品区有N种奖品，分别标号为1到N，其中第i种奖品需要need(i)张奖券进行兑换，并且可以兑换无数次，为了使得辛苦得到的奖券不白白浪费，小Ho给每件奖品都评了分，其中第i件奖品的评分值为value(i),表示他对这件奖品的喜好值。现在他想知道，凭借他手上的这些奖券，可以换到哪些奖品，使得这些奖品的喜好值之和能够最大。

提示一： 切，不就是0~1变成了0~K么

提示二：强迫症患者总是会将状态转移方程优化一遍又一遍

提示三：同样不要忘了优化空间哦！

输入

每个测试点（输入文件）有且仅有一组测试数据。

每组测试数据的第一行为两个正整数N和M,表示奖品的种数，以及小Ho手中的奖券数。

接下来的n行描述每一行描述一种奖品，其中第i行为两个整数need(i)和value(i)，意义如前文所述。

测试数据保证

对于100%的数据，N的值不超过500，M的值不超过10^5

对于100%的数据，need(i)不超过2*10^5, value(i)不超过10^3

输出

对于每组测试数据，输出一个整数Ans，表示小Ho可以获得的总喜好值。

样例输入
5 1000
144 990
487 436
210 673
567 58
1056 897
样例输出
5940

*/


#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;

int need[510] = { 0 };
int value[510] = { 0 };
int dp[100010] = { 0 };

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
		for (j = need[i]; j <= M; ++j)
		{
			int tmp = dp[j - need[i]] + value[i];

			if (tmp > dp[j])
				dp[j] = tmp;

		}
	}

	cout << dp[M] << endl;

	return 0;
}