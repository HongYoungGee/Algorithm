#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[501][501];
int temp[501][501];
int M, N;

int Downhill(int x=0, int y=0)
{
	if (x == M - 1 && y == N - 1) return 1;
	if (temp[x][y] != -1) return temp[x][y];
	
	int sum = 0;

	if (x < M - 1 && arr[x][y] > arr[x + 1][y]) sum += Downhill(x + 1, y); //아래
	if (y < N - 1 && arr[x][y] > arr[x][y + 1]) sum += Downhill(x, y +1); //오른쪽
	if (x > 0 && arr[x][y] > arr[x - 1][y]) sum += Downhill(x - 1, y); //위
	if (y > 0 && arr[x][y] > arr[x][y - 1]) sum += Downhill(x, y - 1); //왼쪽

	return temp[x][y]=sum;
}

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = -1;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

 	printf("%d\n", Downhill());
}