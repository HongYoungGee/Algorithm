#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

struct ground
{
	int mineral = 5;
	std::deque <int> namu;
};

using namespace std;
int N, M, K, arr[13][13],
direct[8][2] = { { -1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
ground land[13][13];

void spring_summer()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!land[i][j].namu.empty())
			{
				for (int k = 0; k < land[i][j].namu.size(); k++)
				{
					if (land[i][j].namu[k] <= land[i][j].mineral) //자원먹기
					{
						land[i][j].mineral -= land[i][j].namu[k];
						land[i][j].namu[k]++;
					}
					else
					{
						while (land[i][j].namu.size() != k) //모두 죽는다
						{
							land[i][j].mineral += land[i][j].namu.back() / 2;
							land[i][j].namu.pop_back();
						}
						break;
					}
				}
			}
}

void fall()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!land[i][j].namu.empty()) //모든 배열 순회 뭐가 있으면
			{
				for (int k = 0; k < land[i][j].namu.size(); k++)
					if (land[i][j].namu[k] % 5 == 0) //5의배수면
					{
						for (int z = 0; z < 8; z++) //8개의 방향
						{
							int rx = i + direct[z][0];
							int ry = j + direct[z][1];

							if (rx >= 0 && ry >= 0 && rx < N && ry < N) land[rx][ry].namu.push_front(1);
						}
					}
			}
}

void winter()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			land[i][j].mineral += arr[i][j];
}

int number_of_namu()
{
	int sum = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sum += land[i][j].namu.size();

	return sum;
}

int main()
{
	int x, y, age;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]); //주는 양분
	for (int i = 0; i < M; i++) { scanf("%d %d %d", &x, &y, &age); land[x - 1][y - 1].namu.push_back(age); } //초기 나무

	while (K--)
	{
		spring_summer();
		fall();
		winter();
	}

	printf("%d\n", number_of_namu());
}