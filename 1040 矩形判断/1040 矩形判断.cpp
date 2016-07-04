/*
2016��2��28��21:39:47


#1040 : �����ж�




ʱ������:1000ms

����ʱ��:1000ms

�ڴ�����:256MB


����

����ƽ����4���߶Σ��ж���4���߶��Ƿ�ǡ��Χ��һ���������0�ľ��Ρ�

����

�����һ����һ������T(1<=T<=100)������������ݵ�������

ÿ�����ݰ���4�У�ÿ�а���4������x1, y1, x2, y2 (0 <= x1, y1, x2, y2 <= 100000)������(x1, y1), (x2,y2)����һ���߶ε������˵㡣

���

ÿ���������һ��YES����NO����ʾ�����4���߶��Ƿ�ǡ��Χ�ɾ��Ρ�
��������3
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

�������YES
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
	//		if (a.p1.x == b.p1.x)//�ж��Ƿ���
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
		if (a.y * (b.p1.x - a.p1.x) == a.x * (b.p1.y - a.p1.y))//���a��bƽ�У��ж������Ƿ���
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
			if (allLines[i].x == allLines[i].y && allLines[i].y == 0)//�ж��Ƿ��б߳�Ϊ��
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
		
		for (i = 1; i < 4; ++ i)//��ƽ�е������߷���ǰ����
		{
			if (isParallel(allLines[0], allLines[i]))
			{
				line tmp = allLines[1];
				allLines[1] = allLines[i];
				allLines[i] = tmp;
				break;
			}
		}
		
		if (i == 4)//û��ƽ�б�
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