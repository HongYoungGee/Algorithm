#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

#define cache_size 1003
int cache[cache_size][cache_size];

char dbcshfdl()
{
	int a, ans = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		ans += a;
	}

	if (ans == 4)
		return 'E';
	
	return 'D' - ans;
}

int main()
{
	cout << dbcshfdl()<<endl;
	cout << dbcshfdl() << endl;
	cout << dbcshfdl() << endl;
}