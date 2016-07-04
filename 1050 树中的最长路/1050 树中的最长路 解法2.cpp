/*
2016��4��29��21:27:14

��һ�ַ����ܺ���⣬��������Ĵ�ĳ���ڵ�s����������ȱ�����������ȱ���Ҳ�У����ҵ��������Ҷ�ӽڵ�node1��Ȼ���ٴ�node1�����DFS���ҵ��������Ҷ�ӽڵ�node2����node1��node2��Ϊ������������Զ�������㣬����֮��ľ��뼴Ϊ����ֱ����


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