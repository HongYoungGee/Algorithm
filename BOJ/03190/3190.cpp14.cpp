#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int N,K,L;
int arr[104][104] = { 0 };
vector<pair<int, char>> v;
int direct[4][2] = { {1,0},{0,-1},{-1,0},{0,1} }; //아래, 왼, 위, 오른

int bam()
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	arr[1][1] = 1;

	int x = 1, y = 1, dnow = 3, time = 0 ,vcount=0;

	while (!q.empty())
	{
		if (vcount < v.size() && v[vcount].first == time) //방향 전환
		{
			if (v[vcount].second == 'D') dnow = (dnow + 1) % 4;
			if (v[vcount].second == 'L') dnow = (dnow + 3) % 4;
			vcount++;
		}
		time++;

		x += direct[dnow][0]; //다음 x 계산
		y += direct[dnow][1]; //다음 y 계산

		if (arr[x][y] == 1) return time; //벽을 만나면 끝

		if (arr[x][y] != 2) //사과가 아니면 pop
		{
			arr[q.front().first][q.front().second] = 0;
			q.pop();
		}

		q.push(make_pair(x, y)); 
		arr[x][y] = 1;
	}
}

int main()
{
	int temp1, temp2;
	char temp3;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N + 2; i++) //1은 벽
		arr[0][i] = arr[i][0]=arr[i][N+1]=arr[N+1][i]=1;

	for (int i = 0; i < K; i++) //2는 사과
	{
		scanf("%d %d", &temp1, &temp2);
		arr[temp1][temp2] = 2;
	}
	
	scanf("%d", &L);
	for (int i = 0; i < L; i++) //경로
	{
		scanf("%d %c", &temp1, &temp3);
		v.push_back(make_pair(temp1, temp3));
	}

	printf("%d\n", bam());
}