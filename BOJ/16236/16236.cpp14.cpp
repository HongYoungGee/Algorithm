#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define maxnum 22
int N, arr[maxnum][maxnum], ans = 0; //아기상어 크기, 먹은 횟수, 지난 시간
int direct[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void bfs(int px, int py, int size=2, int count=0)
{
	vector<pair<int, int>> v;
	v.push_back(make_pair(px, py));
	bool check[maxnum][maxnum] ={ false};
	check[px][py] = true;

	int time = 1;


	while (!v.empty())
	{
		int vsize = v.size();
		for(int i= 0; i<vsize; i++ ) //완탐
		{
			for (int j = 0; j < 4; j++)
			{
				int rx = direct[j][0] + v[i].first;
				int ry = direct[j][1] + v[i].second;

				if (rx >= 0 && rx < N && ry >= 0 && ry < N &&  arr[rx][ry] <= size && !check[rx][ry])
				{
					v.push_back(make_pair(rx, ry));
					check[rx][ry] = true;
				}
			}
		}

		v.erase(v.begin(), v.begin() + vsize); //정렬 및 삭제
		sort(v.begin(), v.end());

		for(int i=0; i<v.size(); i++) //먹을수 있는게 있으면 먹어버림
			if (arr[v[i].first][v[i].second] != 0 && arr[v[i].first][v[i].second] < size)
			{
				ans += time;
				arr[v[i].first][v[i].second] = 0;
				if (size - 1 == count) bfs(v[i].first, v[i].second, size + 1);
				else bfs(v[i].first, v[i].second, size,count+1);
			}

		time++;
	}

}


int main()
{
	int px, py;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)	scanf("%d", &arr[i][j]); //입력

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) if (arr[i][j] == 9) { px = i, py = j, arr[i][j] = 0; };

	bfs(px, py);

	printf("%d\n", ans);
}