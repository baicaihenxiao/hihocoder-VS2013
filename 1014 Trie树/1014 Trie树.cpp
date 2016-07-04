/*
2016��6��8��19:42:22


#1014 : Trie��




ʱ������:10000ms

����ʱ��:1000ms

�ڴ�����:256MB


����

СHi��СHo��һ�Ժ����ѣ���������Ϣ���������ǶԱ�̲�����Ī�����Ȥ������Լ���û���������ڱ�̵�ѧϰ��·��һͬǰ����

��һ�죬����������һ���ʵ䣬����СHi����СHo������Ǹ���������⣺��СHo�����ܲ��ܶ���ÿһ���Ҹ������ַ�������������ʵ������ҵ�������ַ�����ͷ�����е����أ���

����ս��СHo���������ô�᲻���أ���ÿ����һ���ַ������Ҿ����α����ʵ�������е��ʣ��������ҵ��ַ����ǲ���������ʵ�ǰ׺�������ˣ���

СHiЦ�������㰡������̫�����ˣ�~�����Ȿ�ʵ�����10������ʣ���ѯ����һ��Σ����Ҫ�㵽��������ȥ����

СHo��ͷ����һ�㣬������һ�Ѷѵ�0����ʱ�о��Լ��Ⱳ�Ӷ�Ҫ����������...

СHi����СHo�ć�����Ҳ�Ǽ���Ц���������������һ�����֪ʶˮƽ��~��֪��������һ�����ݽṹô����

СHo�����룬˵������֪��~����һ�ֻ��������ݽṹ����������˵��һ������

СHi����ĵ��˵�ͷ��˵����������֪������ô����һ��������ʾ�����ʵ�ô����

СHoҡҡͷ��ʾ�Լ��������

��ʾһ��Trie���Ľ���

���㿴���������ڵõ�������һ��������ô�㿴������Ҹ���һ���ַ���ap����Ҫ��ô�ҵ�������ap��ͷ�ĵ����أ���СHi�ֿ�ʼ��УСHo��

����...һ�����������еĵ��ʣ���СHo���ǲ����Լ��ʼ��������㷨��

������������ѵ��Ͱ׹����ˣ���СHi��ѵ��СHo�����������������ˣ���

��ʾ�������ʹ��Trie��

��ʾ�����ڽ���Trie��ʱͬʱ����ͳ�ƣ�

����ô���ڣ��Ͻ�ȥ�ô���ʵ�ְɣ���СHi����˵��




����

����ĵ�һ��Ϊһ��������n����ʾ�ʵ�Ĵ�С�����n�У�ÿһ��һ�����ʣ�����֤��Ӣ�ĵ��ʣ�Ҳ�п����ǻ����ĵ���Ŷ���������ɲ�����10����СдӢ����ĸ��ɣ����ܴ�����ͬ�ĵ��ʣ���ʱӦ����������ͬ�ĵ��ʡ���������һ��Ϊһ��������m����ʾСHiѯ�ʵĴ��������m�У�ÿһ��һ���ַ��������ַ����ɲ�����10����СдӢ����ĸ��ɣ���ʾСHi��һ��ѯ�ʡ�

��20%��������n, m<=10���ʵ����ĸ���С<=2.

��60%��������n, m<=1000���ʵ����ĸ���С<=5.

��100%��������n, m<=100000���ʵ����ĸ���С<=26.

���ⰴͨ��������������Ŷ��

���

����СHi��ÿһ��ѯ�ʣ����һ������Ans,��ʾ�ʵ�����СHi�������ַ���Ϊǰ׺�ĵ��ʵĸ�����
��������5
babaab
babbbaaaa
abba
aaaaabaa
babaababb
5
babb
baabaaa
bab
bb
bbabbaab
�������1
0
3
0
0



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

class node
{
public:
	int count = 0;
	node* next[26];
	node()
	{
		for (int i = 0; i != 26; ++ i)
		{
			next[i] = NULL;
		}
	}

};


node* dic;


void insertWord(char word[])
{
	int tmp = 0;
	node* curNode = dic;
	
	while (word[tmp] != 0)
	{

		if (curNode->next[word[tmp] - 'a'] == NULL)
		{
			curNode->next[word[tmp] - 'a'] = new node();
		}


		curNode = curNode->next[word[tmp] - 'a'];
		++curNode->count;

		//cout << word << " " << curNode->count << endl;


		++tmp;
	}


}


int queryWord(char word[])
{
	//throw std::logic_error("The method or operation is not implemented.");

	int tmp = 0;
	node* curNode = dic;

	if (word[tmp] == 0)
	{
		return 0;
	}

	while (curNode->next[word[tmp] - 'a'] != NULL)
	{
		curNode = curNode->next[word[tmp] - 'a'];//curNode������һ������ĸ��

		++tmp;//��curNode�������һ��

		if (word[tmp] == 0)
		{
			break;
		}
	}

	if (word[tmp] == 0)
	{
		return curNode->count;
	}

	return 0;
}

int main()
{

	freopen("../test.txt", "r", stdin);


	int n, m;
	char tmp[11];
	int result = 0;

	dic = new node();

	scanf("%d\n", &n);

	while ((n--) > 0)
	{
		scanf("%s\n", &tmp);

		insertWord(tmp);

	}

	scanf("%d\n", &m);


	while ((m --) > 0)
	{
		scanf("%s\n", &tmp);

		result = queryWord(tmp);

		printf("%d\n", result);
	}

	return 0;

}