#include <iostream>
#include <queue>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int BFS(int N, int K)
{
	int check[100003] = { 0 };

	queue<int> q;
	q.push(N);

	check[N] == 1;

	while (!q.empty())
	{
		int qf = q.front();
		q.pop();

		if (qf == K)
			break;

		if (qf - 1 >= 0 && !check[qf - 1])
		{
			check[qf - 1] = check[qf]+1;
			q.push(qf - 1);
		}
		if (qf + 1 <= 100000 && !check[qf + 1])
		{
			check[qf + 1] = check[qf] + 1;
			q.push(qf + 1);
		}
		if (qf * 2 <= 100000 && !check[qf * 2])
		{
			check[qf * 2] = check[qf] + 1;
			q.push(qf * 2);
		}

	}

	return check[K];
}

int main()
{
	int N, K;
	cin >> N >> K;

	cout << BFS(N, K) << endl;

}