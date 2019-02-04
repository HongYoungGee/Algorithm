#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int cache[10002] = { 0 };

int Make_coin(int n, int k, int arr[]) // n종류의 동전이 있을때 k를 만들수있는 경우의수
{
	for (int i = 0; i <= k; i++) //첫번째 코인 할당
		if (i%arr[0] == 0)
			cache[i]++;

	for (int i = 1; i < n; i++) //배열 순차적으로
		for (int j = arr[i]; j <= k; j++)
			cache[j] = cache[j] + cache[j - arr[i]];

	return cache[k];
}


int main()
{
	int n,k , arr[101];
	cin >> n>>k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	printf("%d\n", Make_coin(n,k,arr));
}