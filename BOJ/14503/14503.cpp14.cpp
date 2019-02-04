#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; 

int N, M, arr[52][52],ans=0;
bool check[52][52] = { false };
int direct[4][2] = { {0,-1},{-1,0},{0,1},{1,0} }; //서 북 동 남

int robotclean(int r, int c, int d)
{
	if (arr[r][c]==0) ans++;
	arr[r][c] = 2;

	for (int i = 0; i < 12; i+=3)
	{
		if (arr[r + direct[(i + d) % 4][0]][c + direct[(i + d) % 4][1]] == 0) //방향 청소 안했으면
		{
			robotclean(r + direct[(i + d) % 4][0], c + direct[(i + d) % 4][1], ((i + d + 3) % 4));
			break;
		}

		if (i == 9 && arr[r + direct[(d+3) % 4][0]][c + direct[(d+3) % 4][1]] != 1) //뒷방향 벽 아니면 후진
			robotclean(r + direct[(d + 3) % 4][0], c + direct[(d + 3) % 4][1], d);
	}

	return ans;
}

int main()
{
	int r, c, d; //0북 1동 2남 3서
	scanf("%d %d %d %d %d", &N, &M ,&r, &c, &d); //입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &arr[i][j]);

	printf("%d\n", robotclean(r,c,d));
}