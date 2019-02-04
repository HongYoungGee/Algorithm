#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void BFS(int N, int K)
{
	int check[100003] = { 0 }, count = 0;

	queue<int> q;
	q.push(N);
	check[N] = 1;

	while (!q.empty() && !check[K])
	{
		int qsize = q.size();
		set<int> thisTurn;
		while (qsize--)
		{
			if (q.front() - 1 >= 0) 
			{
				if (!check[q.front() - 1])
				{
					q.push(q.front() - 1);
					thisTurn.insert(q.front() - 1);
				}

				if(thisTurn.find(q.front()-1) != thisTurn.end()) check[q.front() - 1] += check[q.front()];
			}
			if (q.front() + 1 <= 100000)
			{
				if (!check[q.front() + 1])
				{
					q.push(q.front() + 1);
					thisTurn.insert(q.front() + 1);
				}

				if (thisTurn.find(q.front() + 1) != thisTurn.end())	check[q.front() + 1] += check[q.front()];
			}
			if (q.front() * 2 <= 100000)
			{
				if (!check[q.front() * 2])
				{
					q.push(q.front() * 2);
					thisTurn.insert(q.front() * 2);
				}

				if (thisTurn.find(q.front() * 2) != thisTurn.end()) check[q.front() * 2] += check[q.front()];
			}
			q.pop();
		}
		count++;
	}

	cout << count << '\n';
	cout << check[K] << '\n';
}

int main()
{
	int N, K;
	cin >> N >> K;

	BFS(N, K);
}