#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define maxnum 100000
int memo[maxnum + 3][3] = { 0 };  //0 안뜯는거, 1 위, 2 아래
int sticker(int n, int arr[][2])
{
	memo[0][1] = arr[0][0];
	memo[0][2] = arr[0][1];

	for (int i = 1;i<n ;i++)
	{
		memo[i][0] = max(memo[i - 1][1], memo[i - 1][2]); // 안뜯는경우
		memo[i][1] = max(memo[i - 1][0], memo[i - 1][2]) + arr[i][0]; //위에꺼 뜯는경우 , 
		memo[i][2] = max(memo[i - 1][0], memo[i - 1][1]) + arr[i][1]; //아래꺼 뜯는경우 , 
	}

	return max(max(memo[n-1][0], memo[n-1][1]), memo[n-1][2]);
}

int main()
{
	int arr[maxnum + 3][2];

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) //입력 받기
			for (int j = 0; j < n; j++)
				scanf("%d",&arr[j][i]);

		cout << sticker(n,arr) << endl;
	}
}