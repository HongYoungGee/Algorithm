#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main()
{
	int N, M, arr[101][101], ans[101][101] = { 0 };
	queue <pair<int, int>> q;
	string s;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
			arr[i][j]=s[j]-'0';
	}

	ans[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		if (q.front().first > 0 && arr[q.front().first - 1][q.front().second] == 1) // 위에 비교
		{
			if (ans[q.front().first - 1][q.front().second] == 0 || (ans[q.front().first - 1][q.front().second] > ans[q.front().first][q.front().second] + 1))
			{
				ans[q.front().first - 1][q.front().second] = ans[q.front().first][q.front().second] + 1;
				q.push(make_pair(q.front().first - 1, q.front().second));
			}
		}
		if (q.front().second > 0 && arr[q.front().first][q.front().second - 1] == 1) // 왼쪽 비교
		{
			if (ans[q.front().first][q.front().second-1] == 0 || (ans[q.front().first][q.front().second - 1] > ans[q.front().first][q.front().second] + 1))
			{
				ans[q.front().first][q.front().second - 1] = ans[q.front().first][q.front().second] + 1;
				q.push(make_pair(q.front().first, q.front().second - 1));
			}
		}
		if (q.front().second < M - 1 && arr[q.front().first][q.front().second + 1] == 1) // 오른쪽 비교
		{
			if (ans[q.front().first ][q.front().second+1] == 0 ||  (ans[q.front().first][q.front().second + 1] > ans[q.front().first][q.front().second] + 1))
			{
				ans[q.front().first][q.front().second + 1] = ans[q.front().first][q.front().second] + 1;
				q.push(make_pair(q.front().first, q.front().second + 1));
			}
		}
		if (q.front().first < N - 1 && arr[q.front().first + 1][q.front().second] == 1) // 아래 비교
		{
			if (ans[q.front().first + 1][q.front().second]==0 ||(ans[q.front().first + 1][q.front().second] > ans[q.front().first][q.front().second] + 1))
			{
				ans[q.front().first + 1][q.front().second] = ans[q.front().first][q.front().second] + 1;
				q.push(make_pair(q.front().first + 1, q.front().second));
			}
		}

		q.pop();

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
		cout << endl;*/

	}

	cout << ans[N - 1][M - 1] << endl;
}