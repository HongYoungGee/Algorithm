#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int euclid(int A, int B)
{
	if (B == 0) return A;
	else euclid(B, A%B);
}

long long sumOfGCD(int N, int arr[])
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			sum += euclid(arr[i], arr[j]);

	return sum;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N, arr[103];
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		cout << sumOfGCD(N,arr) << endl;
	}
}