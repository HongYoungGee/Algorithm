#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

int N, M, H, arr[32][12] = { 0 },ans=4; //N 세로줄 H 가로줄

bool isTrue()
{
	for (int i = 1; i <= N; i++)
	{
		int currentN = i;
		int currentH = 1;

		while (currentH != H+1)
		{
			if (currentN > 1 && arr[currentH][currentN - 1] == 1) currentN--; //왼쪽
			else if (currentN < N && arr[currentH][currentN] == 1) currentN++; //오른쪽

			currentH++;
		}
		if (currentN != i) return false; //i번째가 i에서 안끝나면 false
	}

	return true;
}

void ladder(int rx, int ry, int max, int count = 0)
{
	if (isTrue()) ans = min(ans, count);
	if (ans <= count || max == count) return;

	int statex = rx, statey = ry;
	while (!(statex == H && statey == N))
	{
		if (statey == N) statex++;
		statey = (statey % N) + 1;

		if (arr[statex][statey] == 0)
		{
			if (statey > 1 && arr[statex][statey - 1] == 1) continue;
			if (statey < N && arr[statex][statey + 1] == 1) continue;

			arr[statex][statey] = 1;
			if(max > count) ladder(statex, statey,max, count + 1);
			arr[statex][statey] = 0;
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++)
	{
		int tempx, tempy;
		scanf("%d %d", &tempx, &tempy);
		arr[tempx][tempy] = 1;
	}

	ladder(1, 0, 3);
	if(ans == 4) printf("%d\n", -1);
	else printf("%d\n", ans);
}