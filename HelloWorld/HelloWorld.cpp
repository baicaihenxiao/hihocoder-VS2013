#include <list>
#include <iostream>
using namespace std;

struct CacheNode
{
	int key;
	int value;

	CacheNode(int key, int value) : key(key), value(value) {}
};

int a = 0;

int main()
{
	constexpr int *a = nullptr;

}