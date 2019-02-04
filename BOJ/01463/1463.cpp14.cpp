#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool cache[1000001] = {false};

int Make_one_bfs(int N) 
{
	queue<int> q;
	q.push(N);
	int temp = 0;
	while (true)
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			if (q.front() == 1)
				return temp;
			if (q.front() % 3 == 0 && cache[q.front() / 3]==false)
			{
				cache[q.front() / 3] = true;
				q.push(q.front() / 3);
			}
			if (q.front() % 2 == 0 && cache[q.front() / 2]==false)
			{
				cache[q.front() / 2] = true;
				q.push(q.front() / 2);
			}
			if(cache[q.front() -1] == false)
			{
				cache[q.front() - 1] = true;
				q.push(q.front() - 1);
			}

			q.pop();
		}
		temp++;
	}
}


int main()
{
	int N;
	cin >> N;

	printf("%d\n", Make_one_bfs(N));
}