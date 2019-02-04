#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std; 

int direct[4][2] = { {0,1},{0,-1},{-1,0},{1,0} }; //동 서 북 남

int main()
{
	int N, M, x, y, K, arr[23][23], dice[6] = { 0,0,0,0,0,0 };
	int floor = 1, front = 5,go;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++) //배열 입력
		for(int j=0; j<M; j++)
			scanf("%d", &arr[i][j]);

	while (K--)
	{
		scanf("%d", &go);

		if (x + direct[go - 1][0] >= 0 && x + direct[go - 1][0] < N && y + direct[go - 1][1] >= 0 && y + direct[go - 1][1] < M)
		{
			x = x + direct[go - 1][0];
			y = y + direct[go - 1][1];

			if (go == 1)
			{
				int temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;

			}
			else if (go == 2)
			{
				int temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
			}
			else if (go == 3)
			{
				int temp = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = dice[0];
				dice[0] = temp;
			}
			else if (go == 4)
			{
				int temp = dice[1];
				dice[1] = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = temp;
			}

			printf("%d\n", dice[5]);
			if (arr[x][y] == 0)
			{
				arr[x][y] = dice[0];
			}
			else
			{
				dice[0] = arr[x][y];
				arr[x][y] = 0;
			}
		}
	}
}