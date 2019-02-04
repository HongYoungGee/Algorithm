#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define maxNum 100+3

using namespace std;

void numberBfs(int N, int arr[][maxNum]) //bfs알고리즘으로 인접한 섬을 2,3,4로 색칠
{
	int count = 2;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 1)
			{
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				arr[i][j] = count;

				while (!q.empty())
				{
					if (q.front().first > 0 && arr[q.front().first - 1][q.front().second] == 1) // 위에 비교
					{
						arr[q.front().first - 1][q.front().second] = count;
						q.push(make_pair(q.front().first - 1, q.front().second));
					}
					if (q.front().second > 0 && arr[q.front().first][q.front().second - 1] == 1) // 왼쪽 비교
					{
						arr[q.front().first][q.front().second - 1] = count;
						q.push(make_pair(q.front().first, q.front().second - 1));
					}
					if (q.front().second < N - 1 && arr[q.front().first][q.front().second + 1] == 1) // 오른쪽 비교
					{
						arr[q.front().first][q.front().second + 1] = count;
						q.push(make_pair(q.front().first, q.front().second + 1));
					}
					if (q.front().first < N - 1 && arr[q.front().first + 1][q.front().second] == 1) // 아래 비교
					{
						arr[q.front().first + 1][q.front().second] = count;
						q.push(make_pair(q.front().first + 1, q.front().second));
					}

					q.pop();
				}

				count++;
			}
}

int makeBridge(int N, int arr[][maxNum]) //최소 다리 수
{
	int ans = 300;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (arr[i][j] != 0)
			{
				bool check[maxNum][maxNum] = { false }; //방문 여부 확인
				int count = 0;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));

				while (!q.empty() && count < ans) //q가 채워져 있고 ans보다 작아야함
				{
					int qsize = q.size();
					while (qsize--)
					{
						if (q.front().first > 0 && !check[q.front().first - 1][q.front().second] && arr[q.front().first - 1][q.front().second] != arr[i][j]) // 위에 비교
						{
							check[q.front().first - 1][q.front().second] = true;
							if (arr[q.front().first - 1][q.front().second] == 0) q.push(make_pair(q.front().first - 1, q.front().second));
							else { ans = min(ans, count); break; }
						}
						if (q.front().second > 0 && !check[q.front().first][q.front().second - 1] && arr[q.front().first][q.front().second - 1] != arr[i][j]) // 왼쪽 비교
						{
							check[q.front().first][q.front().second - 1] = true;
							if (arr[q.front().first][q.front().second - 1] == 0) q.push(make_pair(q.front().first, q.front().second - 1));
							else { ans = min(ans, count); break; }
						}
						if (q.front().second < N - 1 && !check[q.front().first][q.front().second + 1] && arr[q.front().first][q.front().second + 1] != arr[i][j]) // 오른쪽 비교
						{
							check[q.front().first][q.front().second + 1] = true;
							if (arr[q.front().first][q.front().second + 1] == 0) q.push(make_pair(q.front().first, q.front().second + 1));
							else { ans = min(ans, count); break; }
						}
						if (q.front().first < N - 1 && !check[q.front().first + 1][q.front().second] && arr[q.front().first + 1][q.front().second] != arr[i][j]) // 아래 비교
						{
							check[q.front().first + 1][q.front().second] = true;
							if (arr[q.front().first + 1][q.front().second] == 0) q.push(make_pair(q.front().first + 1, q.front().second));
							else { ans = min(ans, count); break; }
						}

						q.pop();
					}
					count++;
				}
			}

	return ans;
}

int main()
{
	int N, arr[maxNum][maxNum] = { 0 };

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);

	numberBfs(N, arr);

	printf("%d\n", makeBridge(N, arr));
}