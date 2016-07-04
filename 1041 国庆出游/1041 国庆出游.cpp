/*
2016年5月25日23:54:14


#1041 : 国庆出游




时间限制:1000ms

单点时限:1000ms

内存限制:256MB


描述

小Hi和小Ho准备国庆期间去A国旅游。A国的城际交通比较有特色：它共有n座城市(编号1-n)；城市之间恰好有n-1条公路相连，形成一个树形公路网。小Hi计划从A国首都(1号城市)出发，自驾遍历所有城市，并且经过每一条公路恰好两次——来回各一次——这样公路两旁的景色都不会错过。




令小Hi苦恼的是他的小伙伴小Ho希望能以某种特定的顺序游历其中m个城市。例如按3-2-5的顺序游历这3座城市。(具体来讲是要求：第一次到达3号城市比第一次到达2号城市早，并且第一次到达2号城市比第一次到达5号城市早)。




小Hi想知道是否有一种自驾顺序满足小Ho的要求。

输入

输入第一行是一个整数T(1<=T<=20)，代表测试数据的数量。

每组数据第一行是一个整数n(1 <= n <= 100)，代表城市数目。

之后n-1行每行两个整数a和b (1 <= a, b <= n)，表示ab之间有公路相连。

之后一行包含一个整数m (1 <= m <= n)

最后一行包含m个整数，表示小Ho希望的游历顺序。

输出

YES或者NO，表示是否有一种自驾顺序满足小Ho的要求。
样例输入2
7
1 2
1 3
2 4
2 5
3 6
3 7
3
3 7 2
7
1 2
1 3
2 4
2 5
3 6
3 7
3
3 2 7

样例输出YES
NO





*/


/*
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <string.h>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::bitset;
using std::stack;

#define MAX 105

bool road[MAX][MAX] = { 0 };//road[a][b]表示a,b两个城市之间是否有边，而且是双向边，从a走到b据题意这条路只能走一遍，而canArrive表示间接可达的所有点;
vector<int> cityTree[MAX];//用来遍历城市，若用road遍历的话，每一个节点扩展下一个时需要遍历MAX个点找到为一的点；
int order[MAX] = { 0 };//游历城市的顺序;
bitset<MAX> canArrive[MAX];//canArrive[i]表示，从首都为根节点构成的树中，第i个城市能够到达的子节点和其本身 j，这些节点会使canArrive[i][j]的二进制位为1，其余点为0;
int m;//要访问的次序城市的个数
bitset<MAX> visited;

void arrive(int thisNode, int parentNode)//因为要从底层节点开始往上算节点能达到的所有点，所以BFS（不是先序遍历也不是中序后序遍历）是不行的，所以用DFS
{
	//memset(visited, 0, sizeof(visited));
	visited.reset();
	stack<int> dfstack;//保存递归节点
	stack<int> dfsParentNode;

	int i = 0;

	dfstack.push(thisNode);
	dfsParentNode.push(parentNode);
	visited.set(thisNode);

	while (!dfstack.empty())
	{
		int tmpNode = dfstack.top();
		int tmpParentNode = dfsParentNode.top();

		for (i = 0; i < cityTree[tmpNode].size(); ++ i)
		{
			int debugTmp1 = cityTree[tmpNode][i];
			if (cityTree[tmpNode][i] == tmpParentNode)
			{
				continue;
			}

			if (!visited.test(cityTree[tmpNode][i]))
			{
				visited.set(cityTree[tmpNode][i]);
				dfstack.push(cityTree[tmpNode][i]);
				dfsParentNode.push(tmpNode);
				break;
			}
		}

		if (i == cityTree[tmpNode].size())
		{
			canArrive[tmpNode][tmpNode] = 1;
			//注意这里,如果最开始调用arrive函数时传进来的是-1,这里可能父节点可能为-1，而如果这样的话会导致WA，不知道为什么，arrive(1,0)就不会出错，而arrive(1,-1)就错了;
			//canArrive[-1]这里没有报错应该是bitset函数自身做了判断，但是交到hihocoder就WA了而不是RE，不知道为什么；
			canArrive[tmpParentNode] |= canArrive[tmpNode];
			//cout << "!--" << tmpNode << endl;
			dfstack.pop();
			dfsParentNode.pop();
		}
		else//有子节点没有访问过，不用做什么；
		{

		}


	}


}

void canReach(int a, int v)
{
	canArrive[a][a] = 1;
	for (int i = 0; i < cityTree[a].size(); i++)
	{
		int b = cityTree[a][i];
		if (b == v)
			continue;
		canReach(b, a);
		canArrive[a] |= canArrive[b];
	}
}


int curTarget = 1;

void dfs(int thisNode, int parentNode)
{

	if (curTarget == m + 1)
	{
		return;
	}

	if (thisNode == order[curTarget])
	{
		++ curTarget;
		//dfs(thisNode, parentNode, curTarget);

		//return;
	}

	while (curTarget <= m)//会不会出现m+1没有初始化导致m+1也被找到了？
	{

		int tmpTarget = curTarget;

		for (int i = 0; i < cityTree[thisNode].size(); ++i)
		{
			int tmpNode = cityTree[thisNode][i];
			if (tmpNode == parentNode)
			{
				continue;
			}

			if (road[thisNode][tmpNode] && canArrive[tmpNode][order[curTarget]])
			{
				road[thisNode][tmpNode] = 0;
				dfs(tmpNode, thisNode);
			}

		}

		//回溯条件，应该是thisNode的每个子节点都没有找到，如果子节点a的子树找到了，则可能a的兄弟节点b在a之前被遍历，则b需要重新判断。所以用一个while循环判断。
		if (tmpTarget == curTarget)//thisNode的子节点没找到，应该回溯；
		{
			break;
		}
		else//thisNode的某个子节点找到了，则看看兄弟节点是否能找到下一个
		{

		}

	}

	
	

}

int main()
{

	freopen("../test.txt", "r", stdin);

	int T;
	int n;
	
	int a, b;

	cin >> T;

	while ((T--) > 0)
	{
		cin >> n;

		//初始化
		memset(road, 0, sizeof(road));

		for (int i = 1; i <= n; ++ i)
		{
			cityTree[i].clear();
			canArrive[i].reset();
		}

		//input
		for (int i = 1; i < n; ++i)
		{
			cin >> a >> b;
			cityTree[a].push_back(b);
			cityTree[b].push_back(a);
			road[a][b] = true;
			road[b][a] = true;

		}
		cin >> m;

		for (int i = 1; i <= m; ++i)
		{
			cin >> order[i];
		}

		//以首都为根节点，计算出canArrive数组；
		arrive(1, 0);//不知道为什么，arrive(1,0)就不会出错，而arrive(1,-1)就错了;
		//canReach(1, -1);

		//cout << n << endl;
		//for (int i = 1; i <= n; ++ i)
		//{
		//	cout << canArrive[i] << " " << canArrive[i][1] << endl;
		//}

		curTarget = 1;

		dfs(1, -1);
		if (curTarget == m + 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}



}