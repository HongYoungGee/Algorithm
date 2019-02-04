#include <iostream>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int arr[1000005];

int main()
{
	int N, B, C,temp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	scanf("%d %d", &B, &C);

	long long sum = N;
	for (int i = 0; i < N; i++)
	{
		temp = arr[i] - B;
		if (temp > 0 && temp%C == 0) sum += temp / C;
		else if(temp > 0) sum += (temp / C) + 1;
	}

	cout << sum << endl;
}