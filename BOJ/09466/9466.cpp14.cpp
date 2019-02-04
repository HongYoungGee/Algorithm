#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define maxNum 100000+3

using namespace std;

int termProject(int N, int arr[])
{
	int ans = N;
	bool check2[maxNum] = { false };

	for (int i = 1; i <= N; i++)
		if (!check2[i]) //방문하지 않은 원소면 순차 탐색
		{
			vector<int> iscycle;
			int num = i;

			check2[i] = true;
			iscycle.push_back(num);
			while (!check2[arr[num]]) //방문했던 원소를 찾으면 종료
			{
				num = arr[num];
				check2[num] = true;
				iscycle.push_back(num);
			}

			vector<int>::iterator it = find(iscycle.begin(), iscycle.end(), arr[num]); //이번 for문에서 cycle을 찾을 경우
			if (it != iscycle.end())
				ans -= iscycle.end() - it;

		}

	return ans;
}

int main()
{
	int T, N, arr[maxNum] = { 0 };

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);

		printf("%d\n", termProject(N, arr));
	}
}