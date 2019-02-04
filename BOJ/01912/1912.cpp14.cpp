#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define maxnum 1000000

int cache[maxnum + 3];
int continuousSum(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cache[i] = arr[i];
		if (i > 0 && cache[i - 1] + arr[i] > cache[i]) cache[i] = cache[i - 1] + arr[i];
	}

	return *max_element(&cache[0], &cache[n]);
}

int main()
{
	int arr[maxnum + 3], n;

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	cout << continuousSum(n, arr) << endl;
}