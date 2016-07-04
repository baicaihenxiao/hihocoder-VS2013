/*
2016年4月29日21:27:14

第一种方法很好理解，我们随机的从某个节点s对树深度优先遍历（广度优先遍历也行），找到深度最大的叶子节点node1；然后再从node1点对树DFS，找到深度最大的叶子节点node2；则node1和node2即为这棵树中相距最远的两个点，它们之间的距离即为树的直径。


*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

#define MAX_N 100005

vector<vector<int>> tree(MAX_N);

int deepestNode = 0;
int deepestLength = 0;

void dfs(int thisNode, int parentNode, int depth)
{

	if (depth > deepestLength)
	{
		deepestLength = depth;
		deepestNode = thisNode;
	}

	int sizeOfSon = tree[thisNode].size();

	for (int i = 0; i < sizeOfSon; ++i)
	{
		if (parentNode == tree[thisNode][i])
		{
			continue;
		}

		dfs(tree[thisNode][i], thisNode, depth + 1);
	}
}

int main()
{
	freopen("../test.txt", "r", stdin);

	int N;
	int ai, bi;

	cin >> N;

	for (int i = 1; i < N; ++i)
	{
		cin >> ai >> bi;
		tree[ai].push_back(bi);
		tree[bi].push_back(ai);
	}

	dfs(1, 0, 0);

	dfs(deepestNode, 0, 0);

	cout << deepestLength << endl;

	return 0;
}