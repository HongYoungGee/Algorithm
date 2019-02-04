#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define maxnum 1000

int memo[maxnum + 3];
int longestSumSequence(int n, int arr[])
{
	for (int i = 0; i < n; i++) //본인 값 할당
		memo[i] = arr[i];

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++) //자기보다 작은수 찾고
			if (arr[j] < arr[i] && memo[j] + arr[i] > memo[i]) // 이었을때 더 큰 값이면 
				memo[i] = memo[j] + arr[i];

	return *max_element(&memo[0], &memo[n]);
}

int main()
{
	int arr[maxnum + 3], n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << longestSumSequence(n, arr) << endl;
}