<<<<<<< HEAD
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

=======
#include <vector>
#include <algorithm>
#include <iostream>

struct Sum
{
	Sum() : sum{ 0 } { }
	void operator()(int n) { sum += n; }
	int sum;
};

int main()
{
	std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };

	std::cout << "before:";
	for (auto const &n : nums)
	{
		std::cout << ' ' << n;
	}
	std::cout << '\n';

	std::for_each(nums.begin(), nums.end(), [](int n){ n++; });

	// calls Sum::operator() for each number
	Sum s = std::for_each(nums.begin(), nums.end(), Sum());

	for (auto&& n : nums)
	{
		++ n;
	}

	std::cout << "after: ";
	for (auto const &n : nums)
	{
		std::cout << ' ' << n;
	}
	std::cout << '\n';
	std::cout << "sum: " << s.sum << '\n';
>>>>>>> origin/master
}