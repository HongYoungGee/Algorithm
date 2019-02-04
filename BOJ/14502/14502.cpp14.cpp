#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

int arr[9][9], N,M,safe=-3,minbirus=100;
int direct[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
queue<pair<int, int>> q;

void arrcopy(int arr[][9], int temp[9][9])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) temp[i][j] = arr[i][j];
}

int bfs(int temp[][9], queue<pair<int, int>> q)
{
	int ans = 0;
	while (!q.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			int rx = direct[i][0] + q.front().first;
			int ry = direct[i][1] + q.front().second;

			if (rx >= 0 && rx < N && ry >= 0 && ry < M && temp[rx][ry] == 0)
			{
				temp[rx][ry] = 2;
				q.push(make_pair(rx, ry));
				ans++;
			}
		}
		q.pop();
	}

	return safe-ans;
}

int lab()
{
	int ans = 0, temp[9][9];;
	for (int i = 0; i < N*M; i++) //3개의 벽 선택
	{
		if (arr[i / M][i%M] != 0) continue;
		arr[i / M][i%M] = 1;
		for (int j = i + 1; j < N*M; j++)
		{
			if (arr[j / M][j%M] != 0) continue;
			arr[j / M][j%M] = 1;
			for (int k = j + 1; k < N*M; k++)
			{
				if (arr[k / M][k%M] != 0) continue;
				arr[k / M][k%M] = 1;
				arrcopy(arr, temp);
				ans = max(bfs(temp,q), ans);
				arr[k / M][k%M] = 0;
			}
			arr[j / M][j%M] = 0;
		}
		arr[i / M][i%M] = 0;
	}

	return ans;
}


int main()
{
	scanf("%d %d", &N, &M); //입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &arr[i][j]);

	for (int i = 0; i < N; i++) //공통변수 입력
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 0) safe++;
			else if (arr[i][j] == 2) q.push(make_pair(i, j));

	printf("%d\n", lab());
}