#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int cache[2][10010] = { 0 };

int Wine_tasting(int n, int arr[])
{
	for (int i = 4; i < n+4; i++)
	{
		cache[0][i] = max(cache[1][i - 1] + arr[i-3], max(cache[1][i - 4], cache[0][i - 4]) + arr[i - 4] + arr[i -3]);
		cache[1][i] = max(cache[0][i - 2], cache[1][i - 2]) + arr[i-3];
	}

	int max = 0;
	for (int i = 4; i < n+4; i++)
	{
		if (cache[0][i] > max) max = cache[0][i];
		if (cache[1][i] > max) max = cache[1][i];
	}

	return max;
}

int main()
{
	int n, arr[10003] = { 0 };

	cin >> n;
	for (int i = 1; i < n+1; i++) 
		scanf("%d", &arr[i]);


	printf("%d\n", Wine_tasting(n,arr));
}