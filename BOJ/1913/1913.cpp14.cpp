#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int N, ans, **arr;

	cin >> N >> ans;
	arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			arr[i][j] = { 0 };
	}

	int x = 0, y = 0, d_x = 1, d_y = 0;
	int ans_x, ans_y;

	for(int i=N*N; i>0; i--)
	{
		arr[x][y] = i;
		if ((d_x==1 && d_y==0) && (x == N-1 || arr[x + 1][y] != 0)) //아래로 가다가 벽 -> 오른쪽
		{
			d_x = 0; d_y = 1;
		}
		else if ((d_x == 0 && d_y == 1) &&  (y == N-1 || arr[x][y + 1] != 0)) //오른쪽 가다가 벽 -> 위로
		{
			d_x = -1; d_y = 0;
		}
		else if ((d_x == -1 && d_y == 0) && (x == 0 || arr[x - 1][y] != 0)) //위로 가다가 벽 -> 왼쪽
		{
			d_x = 0; d_y = -1;
		}
		else if ((d_x == 0 && d_y == -1) && ( arr[x][y-1] != 0)) //왼쪽 가다가 벽 -> 아래
		{
			d_x = 1, d_y = 0;
		}

		if (i == ans)
		{
			ans_x = x+1;
			ans_y = y+1;
		}

		x += d_x;
		y += d_y;
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);

		printf("\n");
	}

	printf("%d %d\n", ans_x, ans_y);

}