/*
2017-8-16 17:43:52

https://leetcode.com/problems/word-ladder-ii/description/

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

���ѡ�

*/

#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <deque>

#include <algorithm>

#include <iostream>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <bitset>
#include <limits>
#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void initArr(string& arr, vector<int>& suf)
{
	int sz = arr.size();
	if (sz == 0)
		return;
	suf[0] = -1;

	int tmp = -1;

	int i = 0;

	for (i = 0; i < sz - 1; ++i)
	{

		if (arr[i + 1] == arr[tmp + 1])
		{
			++tmp;
			suf[i + 1] = tmp;
		}
		else
		{
			if (tmp != -1)
			{
				tmp = suf[tmp];
				--i;
			}
			else
			{
				suf[i + 1] = -1;
			}
		}
	}
}


//1. res[i]的�表示s[0~i]的最大相同前后缀的前�子串为s[0~res[i]],若res[i]=-1,则表示s[0~i]无相同前后缀�
//2. s[0~i]的最大相同前后缀的前�子串的长度为res[i]+1
vector<int> computePrefixFunction(string& s)
{
	vector<int> res(s.size(), 0);

	res[0] = -1;

	int k = -1;//表示pattern里已经匹配了s[0~k]

	for (int i = 1; i < s.size(); ++i)
	{
		while (k >= 0 && s[i] != s[k + 1])
		{
			k = res[k];
		}

		if (s[i] == s[k + 1])
		{
			++k;
		}

		res[i] = k;
	}

	return res;
}

void KMP(string& text, string& pattern)
{
	vector<int> prefix = computePrefixFunction(pattern);

	int k = -1;

	for (int i = 0; i < text.size(); ++i)
	{
		while (k >= 0 && text[i] != pattern[k + 1])
		{
			k = prefix[k];
		}

		if (text[i] == pattern[k + 1])
		{
			++k;
		}

		if (k + 1 == pattern.size())
		{
			cout << i - k << endl;
			k = prefix[k];
		}
	}

}

void KMP1(string& text, string& pattern)
{
	vector<int> prefix(pattern.size(), 0);
	initArr(pattern, prefix);

	int k = -1;

	for (int i = 0; i < text.size(); ++i)
	{
		while (k >= 0 && text[i] != pattern[k + 1])
		{
			k = prefix[k];
		}

		if (text[i] == pattern[k + 1])
		{
			++k;
		}

		if (k + 1 == pattern.size())
		{
			cout << i - k << endl;
			k = prefix[k];
		}
	}

}


int main()
{
	char c = 255;
	char c1 = 0;
	cout << c - c1 << endl;
	// cout << c << endl;
	printf("%d\n", c);

	unsigned short b = c;
	cout << b << endl;

	int d = c;
	cout << d << endl;

	cout << "sd" << endl;

	//cout << s.substr(1, 2) << endl;
	//cout << Solution().longestPalindrome(s) << endl;

}
