/*
2016年7月5日10:41:12

#1105 : 题外话·堆




时间限制:10000ms

单点时限:1000ms

内存限制:256MB


描述

小Ho有一个糖果盒子，每过一段时间小Ho都会将新买来的糖果放进去，同时他也会不断的从其中挑选出最大的糖果出来吃掉，但是寻找最大的糖果不是一件非常简单的事情，所以小Ho希望能够用计算机来他帮忙计算这个问题！

提示：吃糖果吃多了会变胖的！





输入

每个测试点（输入文件）有且仅有一组测试数据。

在一组测试数据中：

第1行为1个整数N，表示需要处理的事件数目。

接下来的M行，每行描述一个事件，且事件类型由该行的第一个字符表示，如果为'A'，表示小Ho将一粒糖果放进了盒子，且接下来为一个整数W，表示这颗糖果的重量；如果为'T'，表示小Ho需要知道当前盒子中最重的糖果的重量是多少，在知道这个值之后，小Ho会将这颗糖果从盒子中取出并吃掉。

对于100%的数据，满足1<=N<=10^5, 1<=w<=10^5。<>

对于100%的数据，满足没有2颗糖果的重量是相同的，最开始的时候小Ho的糖果盒子是空的，且每次小Ho想要取出一颗糖果的时候盒子里一定至少有一颗糖果。

输出

在一组测试数据中：

对于每个类型为'T'的时间，输出1个整数W_MAX，表示在这一时刻，盒子中最重的糖果的重量。



样例输入5
A 77751
A 1329
A 26239
A 80317
T

样例输出80317



*/
//111


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

	++heapSize;//锟斤墜锟介姖飼烇拷閵濈當锟芥挊聙鎲暆锟斤拷鍓侊拷

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
