#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;



int main()
{
	int M, N, arr[1001][1001];
	cin >> M >> N;

	for (int i = 0; i < N; i++) // 입력 받기
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];


	queue <pair<int, int>> q;

	for (int i = 0; i < N; i++) //초기 1인거 q 삽입
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 1)
				q.push(make_pair(i, j));

	while (!q.empty())
	{
		if (q.front().first > 0 && arr[q.front().first - 1][q.front().second] == 0) // 위에 비교
		{
			arr[q.front().first - 1][q.front().second] = arr[q.front().first][q.front().second] + 1;
			q.push(make_pair(q.front().first - 1, q.front().second));
		}
		if (q.front().second > 0 && arr[q.front().first][q.front().second - 1] == 0) // 왼쪽 비교
		{
			arr[q.front().first][q.front().second - 1] = arr[q.front().first][q.front().second] + 1;
			q.push(make_pair(q.front().first, q.front().second - 1));
		}
		if (q.front().second < M - 1 && arr[q.front().first][q.front().second + 1] == 0) // 오른쪽 비교
		{
			arr[q.front().first][q.front().second + 1] = arr[q.front().first][q.front().second] + 1;
			q.push(make_pair(q.front().first, q.front().second + 1));
		}
		if (q.front().first < N - 1 && arr[q.front().first + 1][q.front().second] == 0) // 아래 비교
		{
			arr[q.front().first + 1][q.front().second] = arr[q.front().first][q.front().second] + 1;
			q.push(make_pair(q.front().first + 1, q.front().second));
		}

		q.pop();
	}

	int max = 1, possible = 1;

	for (int i = 0; i < N; i++) //안익은 토마토 있는지, 익은 토마토 몇일걸렸는지 확인
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				possible = -1;
			if (arr[i][j] > max)
				max = arr[i][j];
		}

	if (possible == -1)
		cout << possible << endl;
	else
		cout << max - 1 << endl;
}
