#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool cache[1000001] = { false };

int Make_one_coin2(int n, int k, int arr[]) // n종류의 동전이 있을때 k를 만들수있는 최소수
{
	queue<int> q;
	q.push(k);
	int temp = 0;
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			if (q.front() == 0) //최소 경우의수를 찾음
				return temp;

			for (int j = 0; j < n; j++)
			{
				if (q.front() - arr[j] >= 0 && !cache[q.front() - arr[j]]) //방문하지 않았고 0보다 크면 방문
				{
					cache[q.front() - arr[j]] = true;
					q.push(q.front() - arr[j]);
				}
			}

			q.pop();
		}
		temp++;
	}

	return -1; //경우의수 없음
}

int main()
{
	int n,k , arr[102];
	cin >> n>>k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	printf("%d\n", Make_one_coin2(n,k,arr));
}