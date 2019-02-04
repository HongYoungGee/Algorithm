#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct triple
{
	int a, b, c;
};

void triple_push(int a, int b, int c, queue <triple> *q)
{
	triple temp;
	temp.a = a;
	temp.b = b;
	temp.c = c;
	q->push(temp);
}

int main()
{
	int M, N,H, arr[101][101][101];
	cin >> M >> N>>H;

	for(int k = 0; k < H; k++) // 입력 받기
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++)
				cin >> arr[j][i][k];


	queue <triple> q;

	for (int k = 0; k < H; k++) //초기 1인거 q 삽입
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (arr[j][i][k] == 1)
					triple_push(j, i, k, &q);


	while (!q.empty())
	{
		if (q.front().a > 0 && arr[q.front().a - 1][q.front().b][q.front().c] == 0) // 위에 비교
		{
			arr[q.front().a - 1][q.front().b][q.front().c] = arr[q.front().a][q.front().b][q.front().c] + 1;
			triple_push(q.front().a-1, q.front().b, q.front().c, &q);
		}
		if (q.front().b > 0 && arr[q.front().a][q.front().b - 1][q.front().c] == 0) // 왼쪽 비교
		{
			arr[q.front().a][q.front().b - 1][q.front().c] = arr[q.front().a][q.front().b][q.front().c] + 1;
			triple_push(q.front().a, q.front().b-1, q.front().c, &q);
		}
		if (q.front().b < N - 1 && arr[q.front().a][q.front().b + 1][q.front().c] == 0) // 오른쪽 비교
		{
			arr[q.front().a][q.front().b + 1][q.front().c] = arr[q.front().a][q.front().b][q.front().c] + 1;
			triple_push(q.front().a, q.front().b + 1, q.front().c, &q);
		}
		if (q.front().a < M - 1 && arr[q.front().a + 1][q.front().b][q.front().c] == 0) // 아래 비교
		{
			arr[q.front().a + 1][q.front().b][q.front().c] = arr[q.front().a][q.front().b][q.front().c] + 1;
			triple_push(q.front().a + 1, q.front().b, q.front().c, &q);
		}
		if (q.front().c < H-1 && arr[q.front().a][q.front().b][q.front().c +1] == 0) // 높이 위에 비교
		{
			arr[q.front().a][q.front().b][q.front().c +1] = arr[q.front().a][q.front().b][q.front().c] + 1;
			triple_push(q.front().a, q.front().b, q.front().c+1, &q);
		}
		if (q.front().c > 0 && arr[q.front().a][q.front().b][q.front().c - 1] == 0) // 높이 아래 비교
		{
			arr[q.front().a][q.front().b][q.front().c - 1] = arr[q.front().a][q.front().b][q.front().c] + 1;
			triple_push(q.front().a, q.front().b, q.front().c - 1, &q);
		}

		q.pop();
		/*
		for (int k = 0; k < H; k++)
	    	for (int i = 0; i < N; i++) 
	    	{
		    	for (int j = 0; j < M; j++)
		    	    cout<<arr[j][i][k]<<" ";
		    	cout<<endl;
	    	}
	    	
	    cout<<endl;
	    */
	}

	int max = 1, possible = 1;

	for (int k = 0; k < H; k++) //안익은 토마토 있는지, 익은 토마토 몇일걸렸는지 확인
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++)
			{
				if (arr[j][i][k] == 0)
					possible = -1;
				if (arr[j][i][k] > max)
					max = arr[j][i][k];
			}

	if (possible == -1)
		cout << possible << endl;
	else
		cout << max - 1 << endl;
		
}
