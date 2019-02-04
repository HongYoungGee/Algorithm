#include <iostream>
using namespace std;

long long cache[103] = { 0,1,1,1 };
long long padoban(int n)
{
	if(cache[n] ==0)
		for (int i = 3; i <= n; i++)
			cache[i] = cache[i - 2] + cache[i - 3];

	return cache[n];
}

int main()
{
	int T=0, n;

	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << padoban(n) << endl;
	}
}