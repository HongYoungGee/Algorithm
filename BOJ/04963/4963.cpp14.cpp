#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define maxNum 50+3

using namespace std;

int numberIsland(int w, int h, int arr[][maxNum])
{
	bool check[maxNum][maxNum] = { false }; //방문 여부 확인
	int count = 0;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (!check[i][j] && arr[i][j]==1) //방문하지 않았고 섬이면 ij부터 탐색
			{
				count++;
				queue<pair<int,int>> q;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					if (q.front().first > 0 && q.front().second > 0 && !check[q.front().first - 1][q.front().second - 1] && arr[q.front().first - 1][q.front().second - 1] == 1) //왼위 
						check[q.front().first - 1][q.front().second - 1] = true, q.push(make_pair(q.front().first - 1, q.front().second - 1));
					if (q.front().first > 0 && !check[q.front().first - 1][q.front().second] && arr[q.front().first - 1][q.front().second] == 1) //위
						check[q.front().first - 1][q.front().second] = true, q.push(make_pair(q.front().first - 1, q.front().second));
					if (q.front().first > 0 && q.front().second < w-1 && !check[q.front().first - 1][q.front().second + 1] && arr[q.front().first - 1][q.front().second + 1] == 1) //오위
						check[q.front().first - 1][q.front().second + 1] = true, q.push(make_pair(q.front().first - 1, q.front().second + 1));
					if (q.front().second < w - 1 && !check[q.front().first][q.front().second + 1] && arr[q.front().first][q.front().second + 1] == 1) //오
						check[q.front().first][q.front().second + 1] = true, q.push(make_pair(q.front().first, q.front().second + 1));
					if (q.front().first < h - 1 && q.front().second < w - 1 && !check[q.front().first + 1][q.front().second + 1] && arr[q.front().first + 1][q.front().second + 1] == 1) //오아
						check[q.front().first + 1][q.front().second + 1] = true, q.push(make_pair(q.front().first + 1, q.front().second + 1));
					if (q.front().first < h - 1 && !check[q.front().first + 1][q.front().second] && arr[q.front().first + 1][q.front().second] == 1) //아
						check[q.front().first + 1][q.front().second] = true, q.push(make_pair(q.front().first + 1, q.front().second));
					if (q.front().first < h - 1 && q.front().second > 0 && !check[q.front().first + 1][q.front().second - 1] && arr[q.front().first + 1][q.front().second - 1] == 1) //왼아
						check[q.front().first + 1][q.front().second - 1] = true, q.push(make_pair(q.front().first + 1, q.front().second - 1));
					if (q.front().second > 0 && !check[q.front().first][q.front().second - 1] && arr[q.front().first][q.front().second - 1] == 1) //왼
						check[q.front().first][q.front().second - 1] = true, q.push(make_pair(q.front().first, q.front().second - 1));

					q.pop();
				}
			}

	return count;
}

int main()
{
	int w, h, arr[maxNum][maxNum] = { 0 };

	scanf("%d %d", &w, &h);
	while (!(w == 0 && h == 0))
	{
		for (int i = 0; i < h; i++)
			for(int j=0; j<w; j++) scanf("%d", &arr[i][j]);

		cout << numberIsland(w, h, arr) << '\n';

		scanf("%d %d", &w, &h);
	}
}


