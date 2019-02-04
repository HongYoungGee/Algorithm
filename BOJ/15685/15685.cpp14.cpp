#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int N, direct[4][2] = { {0,1}, {-1,0}, {0,-1},{1,0} }, arr[102][102] = { 0 };

void dragoncurve(int x, int y, int see, int generation)
{
	vector<pair<int,int>> v(1,make_pair(x,y)); 
	v.push_back(make_pair(x + direct[see][0], y + direct[see][1]));

	for (int i = 0; i < v.size(); i++) arr[v[i].first][v[i].second] = 1; //0세대 입력

	while (generation--) //세대 수 만큼
	{
		int cx = v.back().first, cy = v.back().second;
		for (int i = v.size() - 2; i >= 0; i--) //cx,cy를 기준으로 모든 좌표 90도 회전
		{
			int rx = cx + v[i].second - cy; //x2 = (y1 - y) + x;  (y의 변화량 + x좌표)
			int ry = cy - v[i].first + cx; //y2=-(x1-x) + y; (x의 변화량의 음수  + y좌표)
			arr[rx][ry] = 1;
			v.push_back(make_pair(rx, ry));			
		}
	}
}

int nofs()
{
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) ans += arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1];

	return ans;
}

int main()
{
	int x, y, see, generation;
	scanf("%d", &N);

	while (N--)
	{
		scanf("%d %d %d %d", &x, &y, &see, &generation);
		dragoncurve(y, x, see, generation);
	}

	printf("%d\n", nofs());
}