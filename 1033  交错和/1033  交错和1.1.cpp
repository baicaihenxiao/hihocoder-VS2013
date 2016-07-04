#include <stdio.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

const int MAX_DIGIT = 25;//��ǰλ��
const int MAX_REAL_DIGIT = 22;
const int MAX_DIGIT_VALUE = 13;//��ǰλ������ֵ
const int MAX_JIAOCUOHE = 710;//����ͣ�����������΢����һЩ
const int MAX_REAL_JIAOCUOHE = 700;//ʵ���õ��Ľ��������
const int MAX_BIASE_JIAOCUOHE = 350;
const int MOD = 1000000007;

int larray[MAX_DIGIT] = { 0 }, rarray[MAX_DIGIT] = { 0 };//�������ʾÿһλ��ֵ
int lWeishu, rWeishu;
long long int base[MAX_DIGIT];

const int WRONG_STATE = -1;//
const int INITIAL_STATE = -2;

long long int dict[MAX_DIGIT][MAX_DIGIT_VALUE][MAX_JIAOCUOHE] = { 0 };//��ǰλ��Ϊi�����λΪj�������Ϊk


const bool IS_DEBUG = true;

long long int dfs(int weishu, int zuigaowei, int multiplicator, bool isEqualLast, int jiaocuohe, int* array)
{
	long long int result = 0;

	if (weishu == 1 && (multiplicator * zuigaowei == jiaocuohe))
	{
		return zuigaowei;
	}

	if (dict[weishu][zuigaowei][jiaocuohe + MAX_BIASE_JIAOCUOHE] != INITIAL_STATE)
	{
		return dict[weishu][zuigaowei][jiaocuohe + MAX_BIASE_JIAOCUOHE];
	}

	if (weishu == 1 || weishu == MAX_REAL_DIGIT || zuigaowei < 0 || zuigaowei > 9 || jiaocuohe > MAX_BIASE_JIAOCUOHE || jiaocuohe < -MAX_BIASE_JIAOCUOHE)
	{
		return WRONG_STATE;
	}
	
	bool isWrongState = true;

	if (isEqualLast)
	{
		for (int i = 0; i < array[weishu - 1]; ++ i)
		{
			if (IS_DEBUG)
			{
				if (weishu == 5)
				{
					cout << "DEBUG" << endl;
				}
			}
			

			long long int tmp = dfs(weishu - 1, i, -1 * multiplicator, false, jiaocuohe - multiplicator * zuigaowei, array);
			if (tmp != WRONG_STATE)
			{
				result += tmp;
				result %= MOD;
				result += zuigaowei * base[weishu];
				result %= MOD;

				isWrongState = false;

			}
		}
		long long int tmp = dfs(weishu - 1, array[weishu - 1], -1 * multiplicator, true, jiaocuohe - multiplicator * zuigaowei, array);
		if (tmp != WRONG_STATE)
		{
			result += tmp;
			result %= MOD;
			result += zuigaowei * base[weishu];
			result %= MOD;

			isWrongState = false;
		}

	}
	else
	{
		for (int i = 0; i < 10; ++ i)
		{
			long long int tmp = dfs(weishu - 1, i, -1 * multiplicator, false, jiaocuohe - multiplicator * zuigaowei, array);
			if (tmp != WRONG_STATE)
			{
				result += tmp;
				result %= MOD;
				result += zuigaowei * base[weishu];
				result %= MOD;

				isWrongState = false;
			}
			
		}
	}



	if (!isEqualLast)//��Ϊֻ�����λ��array�Ķ�ӦλС��ʱ����һλ�Ż����0-9
	{
		if (isWrongState)
		{
			dict[weishu][zuigaowei][jiaocuohe + MAX_BIASE_JIAOCUOHE] = WRONG_STATE;
		}
		else
		{
			dict[weishu][zuigaowei][jiaocuohe + MAX_BIASE_JIAOCUOHE] = result;
		}
	}

	if (isWrongState)
	{
		return WRONG_STATE;
	}
	else
	{
		return result;
	}


}

void initDict()
{
	for (int i = 0; i < MAX_DIGIT; ++ i)
	{
		for (int j = 0; j < MAX_DIGIT_VALUE; ++ j)
		{
			for (int k = 0; k < MAX_JIAOCUOHE; ++ k)
			{
				dict[i][j][k] = INITIAL_STATE;
			}
		}
	}
}

int main()
{
	freopen("F:\\test.txt", "r", stdin);

	long long int l, r, lInput, rInput;
	int k, i, j;


	//int base[DIGIT];

	cin >> lInput >> rInput >> k;

	l = lInput;
	r = rInput;

 	base[1] = 1;
	for (int i = 2; i < MAX_REAL_DIGIT; ++i)
 	{
 		base[i] = 10 * base[i - 1];
		printf("%d %lld\n", i, base[i]);
 	}

	//cout << base[20] << endl;
	

	//���ڶ��Ǳ����䣬����l��һ
	l -= 1;

	for (i = 1; i < 20 && l != 0; ++i)
	{
		larray[i] = l % 10;
		l /= 10;
	}
	lWeishu = i - 1;

	for (i = 1; i < 20 && r != 0; ++i)
	{
		rarray[i] = r % 10;
		r /= 10;
	}
	rWeishu = i - 1;
	//if (i % 2 == 1)
	//{
	//	bit = -1;
	//}

	//cout << larray << endl;
	//cout << lWeishu << endl;


	//cout << rarray << endl;
	//cout << rWeishu << endl;

	long long int lRes = 0, rRes = 0;

	initDict();

	if (rInput != 0)
	{
		rRes = dfs(rWeishu + 1, 0, -1, true, k, rarray);

		if (rRes == WRONG_STATE)
		{
			rRes = 0;
		}

	}
	//cout << dfs(rWeishu + 1, 0, -1, true, k, rarray) << endl;

	cout << rRes << endl;
	printf("%lld\n", rRes);
	if (rRes == 0)
	{
		cout << 0 << endl;
		return 0;
	}



	initDict();
	if (lInput != -1)
	{
		lRes = dfs(lWeishu + 1, 0, -1, true, k, larray);
		if (lRes == WRONG_STATE)
		{
			lRes = 0;
		}
	}

	cout << lRes << endl;
	printf("%lld\n", lRes);
	//cout << dfs(lWeishu + 1, 0, -1, true, k, larray) << endl;

	cout << (rRes - lRes) % MOD << endl;
	printf("%lld\n", (rRes - lRes) % MOD);
	



}