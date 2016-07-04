/*
2015��11��16��23:50:26

#1094 : Lost in the City
ʱ������:10000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
Little Hi gets lost in the city. He does not know where he is. He does not know which direction is north.

Fortunately, Little Hi has a map of the city. The map can be considered as a grid of N*M blocks. Each block is numbered by a pair of integers. The block at the north-west corner is (1, 1) and the one at the south-east corner is (N, M). Each block is represented by a character, describing the construction on that block: '.' for empty area, 'P' for parks, 'H' for houses, 'S' for streets, 'M' for malls, 'G' for government buildings, 'T' for trees and etc.

Given the blocks of 3*3 area that surrounding Little Hi(Little Hi is at the middle block of the 3*3 area), please find out the position of him. Note that Little Hi is disoriented, the upper side of the surrounding area may be actually north side, south side, east side or west side.

����
Line 1: two integers, N and M(3 <= N, M <= 200).
Line 2~N+1: each line contains M characters, describing the city's map. The characters can only be 'A'-'Z' or '.'.
Line N+2~N+4: each line 3 characters, describing the area surrounding Little Hi.

���
Line 1~K: each line contains 2 integers X and Y, indicating that block (X, Y) may be Little Hi's position. If there are multiple possible blocks, output them from north to south, west to east.

��������
8 8
...HSH..
...HSM..
...HST..
...HSPP.
PPGHSPPT
PPSSSSSS
..MMSHHH
..MMSH..
SSS
SHG
SH.
�������
5 4


*/

#include <stdio.h>

char map[110][110];
char sur1[5][5];
char sur2[5][5];
char sur3[5][5];
char sur4[5][5];
int match1 = 1;
int match2 = 1;
int match3 = 1;
int match4 = 1;

int main()
{

	int N, M;
	int i, j, k, l;

	freopen("F:\\DocCenter\\ProjectFile\\c++\\vs2013\\hihocoder\\test.txt", "r", stdin);


	scanf("%d %d", &N, &M);

	scanf("\n");

	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= M; ++j)
		{
			scanf("%c", &map[i][j]);
		}

		scanf("\n");

	}

	for (i = 1; i <= 3; ++i)
	{
		for (j = 1; j <= 3; ++j)
		{
			scanf("%c", &sur1[i][j]);//��������
			sur2[j][4 - i] = sur1[i][j];
			sur3[4 - i][4 - j] = sur1[i][j];
			sur4[4 - j][i] = sur1[i][j];
			//scanf("%c", &sur2[j][4-i]);//˳ʱ��ת90��
			//scanf("%c", &sur3[4-i][4-j]);//˳ʱ��ת180��
			//scanf("%c", &sur4[4-j][i]);//˳ʱ��ת270��


		}
		scanf("\n");
	}

	for (i = 1; i < N - 1; ++i)
	{
		for (j = 1; j < M - 1; ++j)
		{
			//�Ե�ͼ�ϵ�ÿһ���Ź������ƥ��

			for (k = 1; k < 4; ++k)
			{
				for (l = 1; l < 4; ++l)
				{
					if (map[i + k - 1][j + l - 1] != sur1[k][l])
					{
						match1 = 0;

						goto out1;
					}


				}
			}

			printf("%d %d\n", i + 1, j + 1);
			continue;

		out1:;

			match1 = 1;


			for (k = 1; k < 4; ++k)
			{
				for (l = 1; l < 4; ++l)
				{
					if (map[i + k - 1][j + l - 1] != sur2[k][l])
					{
						match2 = 0;

						goto out2;
					}


				}
			}

			printf("%d %d\n", i + 1, j + 1);
			continue;

		out2:;

			match2 = 1;


			for (k = 1; k < 4; ++k)
			{
				for (l = 1; l < 4; ++l)
				{
					if (map[i + k - 1][j + l - 1] != sur3[k][l])
					{
						match3 = 0;

						goto out3;
					}


				}
			}

			printf("%d %d\n", i + 1, j + 1);
			continue;

		out3:;

			match3 = 1;


			for (k = 1; k < 4; ++k)
			{
				for (l = 1; l < 4; ++l)
				{
					if (map[i + k - 1][j + l - 1] != sur4[k][l])
					{
						match4 = 0;

						goto out4;
					}


				}
			}

			printf("%d %d\n", i + 1, j + 1);
			continue;

		out4:;

			match4 = 1;


		}
	}

	return 0;
}