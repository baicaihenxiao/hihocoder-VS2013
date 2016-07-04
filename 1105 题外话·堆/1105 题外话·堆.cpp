/*
2016��7��4��19:54:45

#1105 : ���⻰����
ʱ������:10000ms
����ʱ��:1000ms
�ڴ�����:256MB
����

СHo��һ���ǹ����ӣ�ÿ��һ��ʱ��СHo���Ὣ���������ǹ��Ž�ȥ��ͬʱ��Ҳ�᲻�ϵĴ�������ѡ�������ǹ������Ե�������Ѱ�������ǹ�����һ���ǳ��򵥵����飬����СHoϣ���ܹ��ü����������æ����������⣡

��ʾ�����ǹ��Զ��˻���ֵģ�

����

ÿ�����Ե㣨�����ļ������ҽ���һ��������ݡ�

��һ����������У�

��1��Ϊ1������N����ʾ��Ҫ������¼���Ŀ��

��������M�У�ÿ������һ���¼������¼������ɸ��еĵ�һ���ַ���ʾ�����Ϊ'A'����ʾСHo��һ���ǹ��Ž��˺��ӣ��ҽ�����Ϊһ������W����ʾ����ǹ������������Ϊ'T'����ʾСHo��Ҫ֪����ǰ���������ص��ǹ��������Ƕ��٣���֪�����ֵ֮��СHo�Ὣ����ǹ��Ӻ�����ȡ�����Ե���

����100%�����ݣ�����1<=N<=10^5, 1<=w<=10^5��<>

����100%�����ݣ�����û��2���ǹ�����������ͬ�ģ��ʼ��ʱ��СHo���ǹ������ǿյģ���ÿ��СHo��Ҫȡ��һ���ǹ���ʱ�������һ��������һ���ǹ���

���

��һ����������У�

����ÿ������Ϊ'T'��ʱ�䣬���1������W_MAX����ʾ����һʱ�̣����������ص��ǹ���������



��������
5
A 77751
A 1329
A 26239
A 80317
T
�������
80317


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


int heap[100010] = { 0 };

int heapSize = 0;


int parent(int son)
{

	return son / 2;

}

int left(int parent)
{
	return 2 * parent;
}


int right(int parent)
{
	return 2 * parent + 1;
}

void insertCandy(int weight)
{
	//throw std::logic_error("The method or operation is not implemented.");

	++heapSize;//�Ѵ��±�Ϊһ��ʼ�洢��

	heap[heapSize] = weight;

	int tmp = heapSize;
	int inTmp = 0;

	while (tmp > 1 && heap[parent(tmp)] < heap[tmp])
	{
		inTmp = heap[parent(tmp)];
		heap[parent(tmp)] = heap[tmp];
		heap[tmp] = inTmp;

		tmp = parent(tmp);
	}

}

int eatCandy()
{
	//throw std::logic_error("The method or operation is not implemented.");

	if (heapSize == 0)
	{
		return -1;
	}

	int result = heap[1];

	heap[1] = heap[heapSize];

	--heapSize;

	//start compare with children
	int tmp = 1;
	int larger;

	while (true)
	{
		larger = tmp;

		if (left(tmp) <= heapSize && heap[left(tmp)] > heap[tmp])
		{
			larger = left(tmp);
		}

		if (right(tmp) <= heapSize && heap[right(tmp)] > heap[larger])//notice:heap[right(tmp)] > heap[larger] ; not  heap[right(tmp)] > heap[tmp];
		{
			larger = right(tmp);
		}

		if (larger == tmp)
		{
			break;
		}
		else
		{
			heap[tmp] ^= heap[larger];
			heap[larger] ^= heap[tmp];
			heap[tmp] ^= heap[larger];

			tmp = larger;
		}

	}


	return result;

}

int main()
{

	freopen("../test.txt", "r", stdin);

	int N;

	scanf("%d\n", &N);

	char type;
	int weight;

	while ((N --) != 0)
	{
		scanf("%c", &type);

		if (type == 'A')
		{
			scanf("%d\n", &weight);

			insertCandy(weight);
		}
		else if (type == 'T')
		{
			scanf("\n");

			int tmpCandy = eatCandy();

			printf("%d\n", tmpCandy);
		}


	}



}