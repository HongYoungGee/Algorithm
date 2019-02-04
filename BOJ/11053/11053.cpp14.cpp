#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define maxnum 1000

int memo[maxnum + 3][2];  //0 포함, 1 미포함
int longestSequence(int n, int arr[]) 
{
	memo[n - 1][0] = 1;
	memo[n - 1][1] = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		//포함할때
		memo[i][0] = 1;
		for (int j = i + 1; j < n; j++) //본인보다 큰 수중 memo값 가장 큰수 할당
			if ( (arr[i] < arr[j]) && (memo[i][0] < (memo[j][0]+1))) memo[i][0] = memo[j][0] + 1;

		//미포함
		memo[i][1] = max(memo[i + 1][0], memo[i + 1][1]);

	}

	return max(memo[0][0], memo[0][1]);
}

int main()
{
	int arr[maxnum + 3], n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << longestSequence(n, arr) << endl;
}