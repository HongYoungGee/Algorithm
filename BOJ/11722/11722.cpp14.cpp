#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define maxnum 1000

int memo[maxnum + 3]; 
int longestLowSequence(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		memo[i] = 1;
		for (int j = 0; j < i; j++) //자기보다 큰 수
			if (arr[j] > arr[i] && memo[j] + 1 > memo[i]) // 이었을때 더 큰 값이면 
				memo[i] = memo[j] + 1;
	}

	return *max_element(&memo[0], &memo[n]);
}

int main()
{
	int arr[maxnum + 3], n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << longestLowSequence(n, arr) << endl;
}