#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;
#define maxnum 100003

int BFS(int N, int K)
{
    if (N >= K) return N - K; //테스트 케이스엔 없지만 예외
    
	int check[maxnum];
	for (int i = 0; i < maxnum; i++) check[i] = -1;
	check[N] = 0;

	bitset<maxnum> bit; //*2연산 체크용
	bit.set();

	queue<int> q;
	q.push(N);

	while (!q.empty() && check[K]==-1)
	{
		int qf2 = q.front() * 2;
		while (qf2 <= 100000 && bit.test(qf2))
		{
			bit.set(qf2, 0);
			if (check[qf2] ==-1)
			{
				check[qf2] = check[q.front()];
				q.push(qf2);
			}
			qf2 *= 2;
		}
		if (q.front() - 1 >= 0 && check[q.front() - 1]==-1)
		{
			check[q.front() - 1] = check[q.front()] + 1;
			q.push(q.front() - 1);
		}
		if (q.front() + 1 <= 100000 && check[q.front() + 1]==-1)
		{
			check[q.front() + 1] = check[q.front()] + 1;
			q.push(q.front() + 1);
		}

		q.pop();
	}

	return check[K];
}

int main()
{
	int N, K;
	cin >> N >> K;

	cout << BFS(N, K) << endl;
}