#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define maxnum 22
int N, ans = 0; //왼쪽으로, 오른쪽으로, 위로, 아래로

void fill_queue(queue<int> &q, int temp)
{
	if (temp != 0)
		if (q.empty()) q.push(temp);
		else if (q.back() == temp) q.back() += temp, q.push(0);
		else q.push(temp);
}

void fill_arrary(queue<int> &q, int *temp)
{
	if (!q.empty() && q.front() == 0) q.pop();

	if (!q.empty())
	{
		*temp = q.front();
		q.pop();
	}
	else *temp = 0;
}

void moveBlock(int array[][maxnum], int temp[][maxnum], int direct) //
{
	queue<int> q;
	for (int x = 0; x < N; x++)
		if (direct == 0) //왼쪽으로
		{
			for (int y = 0; y < N; y++) fill_queue(q, array[x][y]);
			for (int y = 0; y < N; y++) fill_arrary(q, &temp[x][y]);
		}
		else if (direct == 1) //오른쪽으로
		{
			for (int y = N - 1; y >= 0; y--) fill_queue(q, array[x][y]);
			for (int y = N - 1; y >= 0; y--) fill_arrary(q, &temp[x][y]);
		}
		else if (direct == 2) //위로
		{
			for (int y = 0; y < N; y++) fill_queue(q, array[y][x]);
			for (int y = 0; y < N; y++) fill_arrary(q, &temp[y][x]);
		}
		else if (direct == 3)
		{
			for (int y = N - 1; y >= 0; y--) fill_queue(q, array[y][x]);
			for (int y = N - 1; y >= 0; y--) fill_arrary(q, &temp[y][x]);
		}
}

int countarray(int temp[][maxnum], int sum = 0)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (temp[i][j] > sum) sum = temp[i][j];

	return sum;
}

void twozerofour(int array[][maxnum], int count = 0)
{
	if (count == 5)	ans = max(ans, countarray(array));
	else
		for (int i = 0; i < 4; i++)
		{
			int temp[maxnum][maxnum];
			moveBlock(array, temp, i);
			twozerofour(temp, count + 1);
		}
}

int main()
{
	int  arr[maxnum][maxnum];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)	scanf("%d", &arr[i][j]); //입력

	twozerofour(arr);

	printf("%d\n", ans);
}