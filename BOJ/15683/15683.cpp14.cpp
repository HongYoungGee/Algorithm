#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

#define maxnum 9
int N, M, vmin = 100, direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
vector<pair<int, int>> v;
int arr[maxnum][maxnum];

void arrcopy(int arr[][maxnum], int temp[][maxnum]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) temp[i][j] = arr[i][j]; }

void watch(int temp[][maxnum], int rx, int ry, int i)
{
	rx += direct[i][0];
	ry += direct[i][1];

	while (rx >= 0 && rx <= N && ry >= 0 && ry <= M && temp[rx][ry] != 6)
	{
		if (temp[rx][ry] == 0) temp[rx][ry] = 7;
		rx += direct[i][0];
		ry += direct[i][1];
	}
}

void cctv(int num, int arrary[][maxnum])
{
	if (num == v.size())
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (arrary[i][j] == 0) sum++;

		vmin = min(vmin, sum);
		return;
	}

	if (arrary[v[num].first][v[num].second] == 5)
	{
		for (int i = 0; i < 4; i++) //경우의수 4개
			watch(arrary, v[num].first, v[num].second, i);

		cctv(num + 1, arrary);
	}
	else if (arrary[v[num].first][v[num].second] == 1)
	{
		for (int i = 0; i < 4; i++) //경우의수 4개
		{
			int temp[maxnum][maxnum];
			arrcopy(arrary, temp);
			watch(temp, v[num].first, v[num].second, i);

			cctv(num + 1, temp);
		}
	}
	else if (arrary[v[num].first][v[num].second] == 2)
	{
		for (int i = 0; i < 2; i++) //경우의수 2개
		{
			int temp[maxnum][maxnum];
			arrcopy(arrary, temp);

			for (int j = i; j < 4; j += 2) //2개의 방향
				watch(temp, v[num].first, v[num].second, j);

			cctv(num + 1, temp);
		}
	}
	else if (arrary[v[num].first][v[num].second] == 3)
	{
		for (int i = 0; i < 4; i++) //경우의수 4개
		{
			int temp[maxnum][maxnum];
			arrcopy(arrary, temp);

			for (int j = 0; j < 2; j++) //2개의 방향
				watch(temp, v[num].first, v[num].second, (i + j) % 4);

			cctv(num + 1, temp);
		}
	}
	else if (arrary[v[num].first][v[num].second] == 4)
	{
		for (int i = 0; i < 4; i++) //경우의수 4개
		{
			int temp[maxnum][maxnum];
			arrcopy(arrary, temp);

			for (int j = 0; j<3 ; j ++) //3개의 방향
				watch(temp, v[num].first, v[num].second, (i + j) % 4);

			cctv(num + 1, temp);
		}
	}
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 5) v.push_back(make_pair(i, j));
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] >=1 && arr[i][j]<=4) v.push_back(make_pair(i, j));
		
	cctv(0, arr);

	printf("%d\n", vmin);
}