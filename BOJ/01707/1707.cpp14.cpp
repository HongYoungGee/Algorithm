#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define maxNum 20000

using namespace std;

string twoDivision(int V, int E, vector<int> arr[])
{
	int flag = 1, check[maxNum + 2] = { 0 };
	queue <int> q;

	for (int i = 1; i <= V; i++)
	{
		if (check[i] == 0) q.push(i);
		
		while (!q.empty())
		{
			int qsize = q.size();
			while (qsize--)
			{
				check[q.front()] = flag;
				for (int i = 0; i < arr[q.front()].size(); i++)
					if (check[arr[q.front()][i]] == 0) q.push(arr[q.front()][i]);
					else if (check[arr[q.front()][i]] == flag) return "NO";

				q.pop();
			}
			if (++flag == 3) flag = 1;
		}
	}

	return "YES";
}

int main()
{
	int K, V, E;

	cin >> K;
	while (K--)
	{
		vector<int> arr[maxNum + 2];

		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			arr[u].push_back(v);
			arr[v].push_back(u);
		}

		cout << twoDivision(V, E, arr) << '\n';
	}
}