/*
2015年11月13日22:39:35

#1082 : 然而沼跃鱼早就看穿了一切
时间限制:1000ms
单点时限:1000ms
内存限制:256MB
描述
marshtomp.jpg

fjxmlhx每天都在被沼跃鱼刷屏，因此他急切的找到了你希望你写一个程序屏蔽所有句子中的沼跃鱼(“marshtomp”，不区分大小写)。为了使句子不缺少成分，统一换成 “fjxmlhx” 。

输入
输入包括多行。

每行是一个字符串，长度不超过200。

一行的末尾与下一行的开头没有关系。

输出
输出包含多行，为输入按照描述中变换的结果。

样例输入
The Marshtomp has seen it all before.
marshTomp is beaten by fjxmlhx!
AmarshtompB
样例输出
The fjxmlhx has seen it all before.
fjxmlhx is beaten by fjxmlhx!
AfjxmlhxB


*/

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	char str[205];
	int i, j, k;
	int length;

	freopen("F:\\DocCenter\\ProjectFile\\c++\\vs2013\\hihocoder\\test.txt", "r", stdin);


	while (gets(str) != NULL)
	{
		length = strlen(str);

		if (length == 0)
		{
			cout << endl;
		}

		for (i = 0; i < length;)
		{
			j = i;
			if ((str[j] == 'm') || str[j] == 'M')
			{
				++ j;
				if ((str[j] == 'a') || str[j] == 'A')
				{
					++ j;
					if ((str[j] == 'r') || str[j] == 'R')
					{
						++ j;
						if ((str[j] == 's') || str[j] == 'S')
						{
							++ j;
							if ((str[j] == 'h') || str[j] == 'H')
							{
								++j;
								if ((str[j] == 't') || str[j] == 'T')
								{
									++j;
									if ((str[j] == 'o') || str[j] == 'O')
									{
										++j;
										if ((str[j] == 'm') || str[j] == 'M')
										{
											++j;
											if ((str[j] == 'p') || str[j] == 'P')
											{
												cout << "fjxmlhx";

												++j;

												i = j;

												continue;

											}
											else
											{
												goto ifout;
											}
										}
										else
										{
											goto ifout;
										}
									}
									else
									{
										goto ifout;
									}
								}
								else
								{
									goto ifout;
								}
							}
							else
							{
								goto ifout;
							}
						}
						else
						{
							goto ifout;
						}
					}
					else
					{
						goto ifout;
					}
				}
				else
				{
					goto ifout;
				}
			}
			else
			{
				++ j;
			}
			
		ifout:;

			for (k = i; k < j; ++ k)
			{
				cout << str[k];
			}

			i = j;

		}


		cout << endl;
	}

	return 0;
}