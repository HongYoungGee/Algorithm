#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void BFS(int N, int K)
{
	int check[100003], qf, count = 0;
	for (int i = 0; i < 100003; i++) check[i] = -1;

	queue<int> q;
	q.push(N);
	check[N] = 1;

	while (!q.empty() && check[K] == -1)
	{
		int qsize = q.size();
		count++;
		while (qsize--)
		{
			if (q.front() - 1 >= 0 && check[q.front() - 1] == -1)
			{
				check[q.front() - 1] = q.front();
				q.push(q.front() - 1);
			}
			if (q.front() + 1 <= 100000 && check[q.front() + 1] == -1)
			{
				check[q.front() + 1] = q.front();
				q.push(q.front() + 1);
			}
			if (q.front() * 2 <= 100000 && check[q.front() * 2] == -1)
			{
				check[q.front() * 2] = q.front();
				q.push(q.front() * 2);
			}
			q.pop();
		}
	}

	cout << count << endl;
	vector<int> vec;
	for (int i = 0; i <= count; i++, K = check[K])
		vec.push_back(K);

	for (int i = vec.size() - 1; i >= 0; i--)
		cout << vec[i] << " ";
}

int main()
{
	int N, K;
	cin >> N >> K;

	BFS(N, K);
}