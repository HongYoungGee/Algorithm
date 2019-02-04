#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define maxnum 1000000

int cache[maxnum + 3] = { 0 };
int sumOfSquares(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cache[i] = maxnum;
		for (int j = 1; i - j*j >= 0; j++)
			cache[i] = min(cache[i - j*j] + 1, cache[i]);
		
	}

	return cache[n];
}

int main()
{
	int n;
	cin >> n;

	cout << sumOfSquares(n) << endl;
}