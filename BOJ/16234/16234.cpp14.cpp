#include <iostream>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int movement(int N, int L, int R, int arr[][53])
{
	int ans = 0, direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

	while (true)
	{
		int temp[53][53] = { 0 }, count = 1;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				if (temp[i][j] == 0) //i,j시작으로 bfs하며 count채운다
				{
					int people = arr[i][j], number = 1; //조정 변수
					vector<pair<int, int>> v(1,make_pair(i,j));

					queue<pair<int, int>> q; //순회 변수
					q.push(make_pair(i, j));
					temp[i][j] = count;

					while (!q.empty())
					{
						for (int di = 0; di < 4; di++)
						{
							int rx = q.front().first + direct[di][0];
							int ry = q.front().second + direct[di][1];

							if (rx >= 0 && ry >= 0 && rx < N && ry < N)
								if (temp[rx][ry] == 0 &&
									abs(arr[rx][ry] - arr[q.front().first][q.front().second]) >= L &&
									abs(arr[rx][ry] - arr[q.front().first][q.front().second]) <= R )
								{
									temp[rx][ry] = count;
									q.push(make_pair(rx, ry));
									v.push_back(make_pair(rx, ry));

									people += arr[rx][ry];
									number++;
								}
						}

						q.pop();
					}
					
					if(v.size()>1) for (int vi = 0; vi < v.size(); vi++) arr[v[vi].first][v[vi].second] = people / number; //숫자 조정
					count++;
				}


		if (count == N * N +1 ) break;

		ans++;
	}

	return ans;
}

int main()
{
	int N, L, R, arr[53][53];

	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);

	printf("%d\n", movement(N, L, R, arr));
}
