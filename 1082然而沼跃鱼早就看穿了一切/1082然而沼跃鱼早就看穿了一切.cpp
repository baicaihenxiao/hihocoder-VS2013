/*
2015��11��13��22:39:35

#1082 : Ȼ����Ծ����Ϳ�����һ��
ʱ������:1000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
marshtomp.jpg

fjxmlhxÿ�춼�ڱ���Ծ��ˢ������������е��ҵ�����ϣ����дһ�������������о����е���Ծ��(��marshtomp���������ִ�Сд)��Ϊ��ʹ���Ӳ�ȱ�ٳɷ֣�ͳһ���� ��fjxmlhx�� ��

����
����������С�

ÿ����һ���ַ��������Ȳ�����200��

һ�е�ĩβ����һ�еĿ�ͷû�й�ϵ��

���
����������У�Ϊ���밴�������б任�Ľ����

��������
The Marshtomp has seen it all before.
marshTomp is beaten by fjxmlhx!
AmarshtompB
�������
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