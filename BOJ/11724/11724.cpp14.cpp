#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define maxnum 1000
bool check[maxnum + 2] = { false };

void bfs(int num, vector<vector<int>> arr)
{
	queue<int> q;
	q.push(num);

	while (!q.empty())
	{
		for (int i = 0; i < arr[q.front()].size(); i++)
			if(!check[arr[q.front()][i]])
            {
				q.push(arr[q.front()][i]);
                check[arr[q.front()][i]]=true;
            }

		q.pop();
	}
}
int numberOfConnection(int N, int M, vector<vector<int>> arr)
{
	int ans = 0;

	for (int i = 1; i <= N; i++)
		if (!check[i]) 
		{
			bfs(i,arr);
			ans++;
		}
	
	return ans;
}

int main()
{
	vector<vector<int>> arr(maxnum + 2);
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}

	cout << numberOfConnection(N, M, arr) << endl;
}

