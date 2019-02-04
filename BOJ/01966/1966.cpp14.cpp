#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, M,temp;	

	cin >> T;

	while (T--)
	{
		queue<int> qu;
		priority_queue<int> pqu;

		cin >> N >> M;
		for (int i = 0; i < N; i++) { scanf("%d", &temp); qu.push(temp); pqu.push(temp); }

		while (!qu.empty())
		{
			while (qu.front() != pqu.top()) 
			{ 
				qu.push(qu.front()); 
				qu.pop(); 
				(M > 0 ? M-- : M = qu.size() - 1); 
			}

			if (M == 0)
				break;

			qu.pop(); 
			pqu.pop(); 
			M--;
		}

		cout << N - qu.size() + 1 << endl;
	}
}

	