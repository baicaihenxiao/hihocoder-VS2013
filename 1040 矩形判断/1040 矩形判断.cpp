/*
2016年2月28日21:39:47


#1040 : 矩形判断




时间限制:1000ms

单点时限:1000ms

内存限制:256MB


描述

给出平面上4条线段，判断这4条线段是否恰好围成一个面积大于0的矩形。

输入

输入第一行是一个整数T(1<=T<=100)，代表测试数据的数量。

每组数据包含4行，每行包含4个整数x1, y1, x2, y2 (0 <= x1, y1, x2, y2 <= 100000)；其中(x1, y1), (x2,y2)代表一条线段的两个端点。

输出

每组数据输出一行YES或者NO，表示输入的4条线段是否恰好围成矩形。
样例输入3
0 0 0 1
1 0 1 1
0 1 1 1
1 0 0 0
0 1 2 3
1 0 3 2
3 2 2 3
1 0 0 1
0 1 1 0
1 0 2 0
2 0 1 1
1 1 0 1

样例输出YES
YES
NO



*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class point
{
public:
	int x;
	int y;
	bool equals(point p)
	{
		if (this->x == p.x && this->y == p.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	point()
	{

	}
};

class line
{
public:
	int x, y;
	point p1, p2;
	line(int x, int y, point p1, point p2)
	{
		this->x = x;
		this->y = y;
		this->p1 = p1;
		this->p2 = p2;
	}

};

vector<point> allPoints;
vector<line> allLines;

void addPoint(int x, int y)
{
	point p(x, y);

	if (allPoints.size() == 0)
	{
		allPoints.push_back(p);
		return;
	}

	for (int i = 0; i < allPoints.size(); ++ i)
	{
		if (allPoints[i].equals(p))
		{
			return;
		}
	}
	allPoints.push_back(p);

}

void addLine(line l)
{
	allLines.push_back(l);
}

bool isParallel(line a, line b)
{
	//if (a.x == 0)
	//{
	//	if (b.x != 0)
	//	{
	//		return false;
	//	}
	//	else
	//	{
	//		if (a.p1.x == b.p1.x)//判断是否共线
	//		{
	//			return false;
	//		}
	//		else
	//		{
	//			return true;
	//		}
	//	}
	//}

	if (a.x * b.y == a.y * b.x)
	{
		if (a.y * (b.p1.x - a.p1.x) == a.x * (b.p1.y - a.p1.y))//如果a和b平行，判断两者是否共线
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool isVerticle(line a, line b)
{
	if (a.x * b.x + a.y * b.y == 0)
	{
		return true;
	}

	return false;
}




int main()
{
	freopen("../test.txt", "r", stdin);

	int i, j, k;
	int T;
	int x1, y1, x2, y2;

	cin >> T;

	while ((T --) >0)
	{
		allPoints.clear();
		allLines.clear();

		bool lineIsZero = false;

		for (int i = 0; i < 4; ++ i)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			addLine(line(x2 - x1, y2 - y1, point(x1, y1), point(x2, y2)));
			if (allLines[i].x == allLines[i].y && allLines[i].y == 0)//判断是否有边长为零
			{
				lineIsZero = true;
			}
			addPoint(x1, y1);
			addPoint(x2, y2);
		}
		
		if (allPoints.size() != 4 || lineIsZero)
		{
			cout << "NO" << endl;
			continue;
		}
		
		for (i = 1; i < 4; ++ i)//将平行的两条边放在前两个
		{
			if (isParallel(allLines[0], allLines[i]))
			{
				line tmp = allLines[1];
				allLines[1] = allLines[i];
				allLines[i] = tmp;
				break;
			}
		}
		
		if (i == 4)//没有平行边
		{
			cout << "NO" << endl;
			continue;
		}

		if (isVerticle(allLines[0], allLines[2]) && isVerticle(allLines[0], allLines[3]) && isParallel(allLines[2], allLines[3]))
		{
			cout << "YES" << endl;

		}
		else
		{
			cout << "NO" << endl;
		}


	}

}