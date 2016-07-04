/*
2015年11月10日11:09:17

#1039 : 字符消除
时间限制:1000ms
单点时限:1000ms
内存限制:256MB
描述
小Hi最近在玩一个字符消除游戏。给定一个只包含大写字母"ABC"的字符串s，消除过程是如下进行的：



1)如果s包含长度超过1的由相同字母组成的子串，那么这些子串会被同时消除，余下的子串拼成新的字符串。例如"ABCCBCCCAA"中"CC","CCC"和"AA"会被同时消除，余下"AB"和"B"拼成新的字符串"ABB"。

2)上述消除会反复一轮一轮进行，直到新的字符串不包含相邻的相同字符为止。例如”ABCCBCCCAA”经过一轮消除得到"ABB"，再经过一轮消除得到"A"



游戏中的每一关小Hi都会面对一个字符串s。在消除开始前小Hi有机会在s中任意位置(第一个字符之前、最后一个字符之后以及相邻两个字符之间)插入任意一个字符('A','B'或者'C')，得到字符串t。t经过一系列消除后，小Hi的得分是消除掉的字符的总数。



请帮助小Hi计算要如何插入字符，才能获得最高得分。



输入
输入第一行是一个整数T(1<=T<=100)，代表测试数据的数量。

之后T行每行一个由'A''B''C'组成的字符串s，长度不超过100。



输出
对于每一行输入的字符串，输出小Hi最高能得到的分数。



提示
第一组数据：在"ABCBCCCAA"的第2个字符后插入'C'得到"ABCCBCCCAA"，消除后得到"A"，总共消除9个字符(包括插入的'C')。

第二组数据："AAA"插入'A'得到"AAAA"，消除后得到""，总共消除4个字符。

第三组数据：无论是插入字符后得到"AABC","ABBC"还是"ABCC"都最多消除2个字符。



样例输入
3
ABCBCCCAA
AAA
ABC
样例输出
9
4
2



*/

#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

int removeDup(char str[])
{
	int length = strlen(str);
	//cout << strlen(str);

	int count = 0;

	int j, k, tmp1;

	for (j = 0; j < length - 1; ++j)//将相同的字符置为 小a；
	{
		if (str[j + 1] == str[j])
		{
			for (k = j + 1; k < length; ++k)
			{
				if (str[k] == str[j])
				{
					str[k] = 'a';
					++count;
				}
				else
				{
					break;
				}
			}

			str[j] = 'a';
			
			++count;

			j = k - 1;
		}
	}

	//cout << str << endl;

	for (j = 0, tmp1 = 0; j < length; ++j, ++tmp1)//消除 小a
	{

		if (str[j] == 'a')
		{

			for (; j < length; ++j)
			{
				if (str[j] != 'a')
				{
					break;
				}
			}

			if (j != length)
			{
				str[tmp1] = str[j];
			}
			else
			{
				break;
			}
		}
		else
		{
			str[tmp1] = str[j];
		}
	}

	str[tmp1] = '\0';

	return count;
}

char* insertChar(char strp[], int pos, char ins)//在str[pos]之前插入ins
{
	char*str = new char[105];
	strcpy(str, strp);

	int length = strlen(str);

	str[length + 1] = '\0';

	for (int i = length; i > pos; -- i)
	{
		str[i] = str[i - 1];
	}

	str[pos] = ins;

	//cout << str << endl;

	return str;
}

int main()
{
	freopen("F:\\DocCenter\\ProjectFile\\c++\\vs2013\\hihocoder\\test.txt", "r", stdin);

	int T;
	int i, j, k;
	int tmp1, tmp2;

	scanf("%d\n", &T);

	char str[105];
	char strtmp[105];
	char tmp;

	//cout << strlen(str);

	for (i = 0; i < T; -- T)
	{
		gets(str);

		//
		int count = 0;
		//cout << strlen(str);
		
		/*

		for (j = 0; j < length - 1; ++ j)//将相同的字符置为 小a；
		{
			if (str[j + 1] == str[j])
			{
				for (k = j + 1; k < length; ++k)
				{
					if (str[k] == str[j])
					{
						str[k] = 'a';
					}
					else
					{
						break;
					}
				}
				
				str[j] = 'a';

				j = k - 1;
			}
		}

		cout << str << endl;

		for (j = 0, tmp1 = 0; j < length; ++ j, ++ tmp1)//消除 小a
		{

			if (str[j] == 'a')
			{

				for (; j < length; ++ j)
				{
					if (str[j] != 'a')
					{
						break;
					}
				}

				if (j != length)
				{
					str[tmp1] = str[j];
				}
				else
				{
					break;
				}
			}
			else
			{
				str[tmp1] = str[j];
			}
		}

		str[tmp1] = '\0';
		*/

		//cout << removeDup(str) << endl;

		if (strlen(str) == 0)
		{
			cout << 0 << endl;
			continue;
		}

		count += removeDup(str);

		int length = strlen(str);


		if (length == 0)
		{
			++ count;
			cout << count << endl;
			continue;
		}

		int maxCount = 0;



		for (j = 0; j <= length; ++ j)
		{
			

			for (k = 0; k < 3; ++ k)
			{
				char inst = 'A' + k;

				char* tmp = insertChar(str, j, inst);

				int ma = 0;
				int ma1 = 0;
				while ((ma1 = removeDup(tmp)) != 0)
				{
					ma += ma1;
				}

				if (ma > maxCount)
				{
					maxCount = ma;
				}

				delete[] tmp;
			}

		}

		//cout << "max le is " << (count + maxCount) << endl;

		cout << (count + maxCount) << endl;

		//printf("%s\n", str);
	}


	return 0;
}

