#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define maxNum 1000+3

using namespace std;

int permutationCycle(int N, int arr[]) //모든 정점은 하나의 순열을 이룬다
{
	bool check[maxNum] = { false };
	int ans = 0;

	for (int i = 1; i <= N; i++)
		if (!check[i])
		{
			int num = i;
			while (!check[num])
			{
				check[num] = true;
				num = arr[num];
			}

			ans++;
		}

	return ans;
}

int main()
{
	int T, N;

	cin >> T;
	while (T--)
	{
		int arr[maxNum] = { 0 };
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		cout << permutationCycle(N, arr) << endl;
	}
}