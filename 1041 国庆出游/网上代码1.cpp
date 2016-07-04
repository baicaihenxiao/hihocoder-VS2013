// http://blog.csdn.net/q1204265228/article/details/42915067
//http://blog.csdn.net/x920405451x/article/details/39753305


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<bitset>
using namespace std;
#define MAX 111
int m, ok, j, order[MAX], flag[MAX][MAX];
bitset<MAX> digit[MAX];//���ÿ�������ܵ�������г��У��ܵ��ﲻ�������м������·
vector<int> u[MAX];//���ÿ��������·���ӵ����г���

void canReach(int a, int v)
{
	digit[a][a] = 1;
	for (int i = 0; i < u[a].size(); i++)
	{
		int b = u[a][i];
		if (b == v)
			continue;
		canReach(b, a);
		digit[a] |= digit[b];
	}
}

void dfs(int a, int v)
{
	if (a == order[j])
		j++;
	if (j == m)
	{
		ok = 1;
		return;
	}
	while (j < m)
	{
		int p = j, c = order[j];
		for (int i = 0; i < u[a].size(); i++)
		{
			int b = u[a][i];
			if (b == v)
				continue;
			if (digit[b][c] && flag[a][b])//���b�ܵ���c����a��b֮����·
			{
				flag[a][b] = 0;
				dfs(b, a);
				break;
			}
		}
		if (p == j)
			break;//��ʾ�Ըýڵ�Ϊ��������������Ŀ��㣬����ѭ������Ȼ�󷵻صݹ���һ�㣩
	}
}

int main(void)
{
	freopen("../test.txt", "r", stdin);


	int a, b, i, t, n;
	scanf("%d", &t);
	while (t--)
	{
		ok = j = 0;
		memset(flag, 0, sizeof flag);
		for (i = 0; i < MAX; i++)
		{
			digit[i].reset();
			u[i].clear();
		}
		scanf("%d", &n);
		for (i = 1; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			u[a].push_back(b);
			u[b].push_back(a);
			flag[a][b] = flag[b][a] = 1;
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++)
			scanf("%d", &order[i]);
		canReach(1, -1);
		dfs(1, -1);
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
}