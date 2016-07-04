/*
2016年5月1日14:27:17


#1141 : 二分·归并排序之逆序对





时间限制:10000ms

单点时限:1000ms

内存限制:256MB


描述

在上一回、上上回以及上上上回里我们知道Nettle在玩《艦これ》。经过了一番苦战之后，Nettle又获得了的很多很多的船。
这一天Nettle在检查自己的舰队列表：

我们可以看到，船默认排序是以等级为参数。但实际上一个船的火力值和等级的关系并不大，所以会存在A船比B船等级高，但是A船火力却低于B船这样的情况。比如上图中77级的飞龙改二火力就小于55级的夕立改二。
现在Nettle将按照等级高低的顺序给出所有船的火力值，请你计算出一共有多少对船满足上面提到的这种情况。


提示：火力高才是猛！

拿到这道题目，可以很容易想到两重For循环枚举，复杂度为O(N^2)，对于1000ms的时限来说显然会TLE。

既然是分治专题，这题必然和分治相关咯？
没错。这道题需要用到的是长期被我们忽略的归并排序。
我们来看一个归并排序的过程:
给定的数组为[2, 4, 5, 3, 1]，二分后的数组分别为[2, 4, 5], [1, 3]，假设我们已经完成了子过程，现在进行到该数组的“并”操作：



a: [2, 4, 5] 　 b: [1, 3] 　 result:[1] 　 选取b数组的1
a: [2, 4, 5] 　 b: [3] 　 result:[1, 2] 　 选取a数组的2
a: [4, 5] 　 b: [3] 　 result:[1, 2, 3] 　 选取b数组的3
a: [4, 5] 　 b: [] 　 result:[1, 2, 3, 4] 　 选取a数组的4
a: [5] 　 b: [] 　 result:[1, 2, 3, 4, 5] 　 选取a数组的5

在执行[2, 4, 5]和[1, 3]合并的时候我们可以发现，当我们将a数组的元素k放入result数组时，result中存在的b数组的元素一定比k小。
在原数组中，b数组中的元素位置一定在k之后，也就是说k和这些元素均构成了逆序对。
那么在放入a数组中的元素时，我们通过计算result中b数组的元素个数，就可以计算出对于k来说，b数组中满足逆序对的个数。
又因为递归的过程中，a数组中和k满足逆序对的数也计算过。则在该次递归结束时，[2, 4, 5, 3, 1]中所有k的逆序对个数也就都统计了。
同理对于a中其他的元素也同样有这样的性质。

由于每一次的归并过程都有着同样的情况，则我们可以很容易推断出：
若将每一次合并过程中得到的逆序对个数都加起来，即可得到原数组中所有逆序对的总数。

即在一次归并排序中计算出了所有逆序对的个数，时间复杂度为O(NlogN)

另外，逆序对的计算还有一种同样O(NlogN)的算法，使用的是树状数组，有兴趣的话可以自行搜索一下资料。




输入

第1行：1个整数N。N表示舰船数量, 1≤N≤100,000
第2行：N个整数，第i个数表示等级第i低的船的火力值a[i]，1≤a[i]≤2^31-1。

输出

第1行：一个整数，表示有多少对船满足“A船比B船等级高，但是A船火力低于B船”。
样例输入10
1559614248 709366232 500801802 128741032 1669935692 1993231896 369000208 381379206 962247088 237855491
样例输出27




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

int a[100005];
int tmp[100005];
long long result = 0;//注意这里一定要设为long long,设为int的话通不过!!!

void Merge(int low, int mid, int high)
{
	int leftPoint = low, rightPoint = mid;
	int tmpPoint = low;
	while (leftPoint < mid && rightPoint < high)
	{
		if (a[leftPoint] <= a[rightPoint])
		{
			tmp[tmpPoint++] = a[leftPoint++];
			result += rightPoint - mid;
		}
		else
		{
			tmp[tmpPoint++] = a[rightPoint++];
		}
	}

	while (leftPoint < mid)
	{
		tmp[tmpPoint++] = a[leftPoint++];
		result += rightPoint - mid;//如果能进入这个循环，表示右边的一半已经遍历结束，此时rightPoint==high;
	}
	while (rightPoint < high)
	{
		tmp[tmpPoint++] = a[rightPoint++];
	}

	for (int i = low; i < high; ++i)
	{
		a[i] = tmp[i];
	}

}

void MergeSort(int low, int high)//数组的下标范围为[low,high) , 总共high - low个元素
{
	if (low == high || (low + 1) == high)
	{
		return;
	}

	int mid = (low + high) / 2;
	//将数组分为[low, mid)和[mid, high),所以存在划分时low==mid的情况和low+1 == mid的情况，这两种情况都为终止情况；
	MergeSort(low, mid);
	MergeSort(mid, high);

	Merge(low, mid, high);
}

int main()
{
	freopen("../test.txt", "r", stdin);

	int N = 0;

	cin >> N;

	for (int i = 0; i != N; ++i)
	{
		cin >> a[i];
	}

	MergeSort(0, N);

	//for (int i = 0; i != N; ++i)
	//{
	//	cout << a[i] << endl;
	//}

	cout << result << endl;
}