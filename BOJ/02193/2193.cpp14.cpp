#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
unsigned long long memo[100] = { 0 };
unsigned long long ecin(int n)
{
	if (n <= 2) return 1;
	if (memo[n] != 0) return memo[n];
	
	return memo[n] = ecin(n - 1) + ecin(n - 2);
}

int main()
{
	int n;
	cin >> n;

	cout << ecin(n) << endl;
}