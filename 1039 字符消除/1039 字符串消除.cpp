/*
2015��11��10��11:09:17

#1039 : �ַ�����
ʱ������:1000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
СHi�������һ���ַ�������Ϸ������һ��ֻ������д��ĸ"ABC"���ַ���s���������������½��еģ�



1)���s�������ȳ���1������ͬ��ĸ��ɵ��Ӵ�����ô��Щ�Ӵ��ᱻͬʱ���������µ��Ӵ�ƴ���µ��ַ���������"ABCCBCCCAA"��"CC","CCC"��"AA"�ᱻͬʱ����������"AB"��"B"ƴ���µ��ַ���"ABB"��

2)���������ᷴ��һ��һ�ֽ��У�ֱ���µ��ַ������������ڵ���ͬ�ַ�Ϊֹ�����硱ABCCBCCCAA������һ�������õ�"ABB"���پ���һ�������õ�"A"



��Ϸ�е�ÿһ��СHi�������һ���ַ���s����������ʼǰСHi�л�����s������λ��(��һ���ַ�֮ǰ�����һ���ַ�֮���Լ����������ַ�֮��)��������һ���ַ�('A','B'����'C')���õ��ַ���t��t����һϵ��������СHi�ĵ÷������������ַ���������



�����СHi����Ҫ��β����ַ������ܻ����ߵ÷֡�



����
�����һ����һ������T(1<=T<=100)������������ݵ�������

֮��T��ÿ��һ����'A''B''C'��ɵ��ַ���s�����Ȳ�����100��



���
����ÿһ��������ַ��������СHi����ܵõ��ķ�����



��ʾ
��һ�����ݣ���"ABCBCCCAA"�ĵ�2���ַ������'C'�õ�"ABCCBCCCAA"��������õ�"A"���ܹ�����9���ַ�(���������'C')��

�ڶ������ݣ�"AAA"����'A'�õ�"AAAA"��������õ�""���ܹ�����4���ַ���

���������ݣ������ǲ����ַ���õ�"AABC","ABBC"����"ABCC"���������2���ַ���



��������
3
ABCBCCCAA
AAA
ABC
�������
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

	for (j = 0; j < length - 1; ++j)//����ͬ���ַ���Ϊ Сa��
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

	for (j = 0, tmp1 = 0; j < length; ++j, ++tmp1)//���� Сa
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

char* insertChar(char strp[], int pos, char ins)//��str[pos]֮ǰ����ins
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

		for (j = 0; j < length - 1; ++ j)//����ͬ���ַ���Ϊ Сa��
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

		for (j = 0, tmp1 = 0; j < length; ++ j, ++ tmp1)//���� Сa
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

