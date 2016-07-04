/*
2016��5��25��23:54:14


#1041 : �������




ʱ������:1000ms

����ʱ��:1000ms

�ڴ�����:256MB


����

СHi��СHo׼�������ڼ�ȥA�����Ρ�A���ĳǼʽ�ͨ�Ƚ�����ɫ��������n������(���1-n)������֮��ǡ����n-1����·�������γ�һ�����ι�·����СHi�ƻ���A���׶�(1�ų���)�������Լݱ������г��У����Ҿ���ÿһ����·ǡ�����Ρ������ظ�һ�Ρ���������·���Եľ�ɫ����������




��СHi���յ�������С���СHoϣ������ĳ���ض���˳����������m�����С����簴3-2-5��˳��������3�����С�(����������Ҫ�󣺵�һ�ε���3�ų��бȵ�һ�ε���2�ų����磬���ҵ�һ�ε���2�ų��бȵ�һ�ε���5�ų�����)��




СHi��֪���Ƿ���һ���Լ�˳������СHo��Ҫ��

����

�����һ����һ������T(1<=T<=20)������������ݵ�������

ÿ�����ݵ�һ����һ������n(1 <= n <= 100)�����������Ŀ��

֮��n-1��ÿ����������a��b (1 <= a, b <= n)����ʾab֮���й�·������

֮��һ�а���һ������m (1 <= m <= n)

���һ�а���m����������ʾСHoϣ��������˳��

���

YES����NO����ʾ�Ƿ���һ���Լ�˳������СHo��Ҫ��
��������2
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

�������YES
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

bool road[MAX][MAX] = { 0 };//road[a][b]��ʾa,b��������֮���Ƿ��бߣ�������˫��ߣ���a�ߵ�b����������·ֻ����һ�飬��canArrive��ʾ��ӿɴ�����е�;
vector<int> cityTree[MAX];//�����������У�����road�����Ļ���ÿһ���ڵ���չ��һ��ʱ��Ҫ����MAX�����ҵ�Ϊһ�ĵ㣻
int order[MAX] = { 0 };//�������е�˳��;
bitset<MAX> canArrive[MAX];//canArrive[i]��ʾ�����׶�Ϊ���ڵ㹹�ɵ����У���i�������ܹ�������ӽڵ���䱾�� j����Щ�ڵ��ʹcanArrive[i][j]�Ķ�����λΪ1�������Ϊ0;
int m;//Ҫ���ʵĴ�����еĸ���
bitset<MAX> visited;

void arrive(int thisNode, int parentNode)//��ΪҪ�ӵײ�ڵ㿪ʼ������ڵ��ܴﵽ�����е㣬����BFS�������������Ҳ�����������������ǲ��еģ�������DFS
{
	//memset(visited, 0, sizeof(visited));
	visited.reset();
	stack<int> dfstack;//����ݹ�ڵ�
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
			//ע������,����ʼ����arrive����ʱ����������-1,������ܸ��ڵ����Ϊ-1������������Ļ��ᵼ��WA����֪��Ϊʲô��arrive(1,0)�Ͳ��������arrive(1,-1)�ʹ���;
			//canArrive[-1]����û�б���Ӧ����bitset�������������жϣ����ǽ���hihocoder��WA�˶�����RE����֪��Ϊʲô��
			canArrive[tmpParentNode] |= canArrive[tmpNode];
			//cout << "!--" << tmpNode << endl;
			dfstack.pop();
			dfsParentNode.pop();
		}
		else//���ӽڵ�û�з��ʹ���������ʲô��
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

	while (curTarget <= m)//�᲻�����m+1û�г�ʼ������m+1Ҳ���ҵ��ˣ�
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

		//����������Ӧ����thisNode��ÿ���ӽڵ㶼û���ҵ�������ӽڵ�a�������ҵ��ˣ������a���ֵܽڵ�b��a֮ǰ����������b��Ҫ�����жϡ�������һ��whileѭ���жϡ�
		if (tmpTarget == curTarget)//thisNode���ӽڵ�û�ҵ���Ӧ�û��ݣ�
		{
			break;
		}
		else//thisNode��ĳ���ӽڵ��ҵ��ˣ��򿴿��ֵܽڵ��Ƿ����ҵ���һ��
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

		//��ʼ��
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

		//���׶�Ϊ���ڵ㣬�����canArrive���飻
		arrive(1, 0);//��֪��Ϊʲô��arrive(1,0)�Ͳ��������arrive(1,-1)�ʹ���;
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