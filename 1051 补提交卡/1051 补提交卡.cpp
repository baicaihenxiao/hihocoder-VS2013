/*
2015��11��13��10:25:40

#1051 : ���ύ��
ʱ������:2000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
СHo���Լ�����һ����ΰ��Ŀ�꣺����100��ÿ������hihoCoder���ύһ������100���ȥ�ˣ�СHo�鿴�Լ����ύ��¼������N����Ϊ̰�������ύ�ˡ�����СHo��ĥӲ�ݡ�ǿ����СHi���ӵ������СHi����Ҫ��M��"���ύ��"��ÿ��"���ύ��"�����Բ���һ����ύ����ԭ��û���ύ�����һ�������ύ�����һ�졣СHo��֪��ͨ��������M�Ų��ύ��������ʹ�Լ���"������ύ����"����ɶ����졣

����
��һ����һ������T(1 <= T <= 10)������������ݵ�������

ÿ���������ݵ�һ����2������N��M(0 <= N, M <= 100)���ڶ��а���N������a1, a2, ... aN(1 <= a1 < a2 < ... < aN <= 100)����ʾ��a1, a2, ...  aN��СHoû���ύ����

���
����ÿ�����ݣ����ͨ��ʹ�ò��ύ��СHo��������ύ��������ɶ��١�

��������
3
5 1
34 77 82 83 84
5 2
10 30 55 56 90
5 10
10 30 55 56 90
�������
76
59
100
EmacsNormalVim
*/

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int T;
	int N, M;
	int absence[105];
	int i, j, k;

	freopen("F:\\DocCenter\\ProjectFile\\c++\\vs2013\\hihocoder\\test.txt", "r", stdin);

	scanf("%d", &T);

	for (k = 0; k < T; ++k)
	{
		scanf("%d %d", &N, &M);

		for (i = 1; i <= N; ++ i)
		{
			scanf("%d", &absence[i]);
		}

		absence[0] = 0;
		absence[N + 1] = 101;


		if (N <= M)
		{
			cout << 100 << endl;
			continue;
		}

		int max = 0, tmp = 0;

		for (i = 1; i <= N - M + 1; ++ i)
		{
			tmp = absence[i + M] - absence[i - 1] - 1;

			if (max < tmp)
			{
				max = tmp;
			}

		}

		cout << max << endl;

	}



}