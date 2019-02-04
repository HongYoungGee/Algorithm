#include <iostream>
#include <algorithm>

#define maxNum 8+3

using namespace std;

int maxdiff(int N, int arr[])
{
	int sum = 0;
	do { 
	int temp = 0;
	for (int i = 1; i < N; i++)
		temp += abs(arr[i] - arr[i - 1]);
	sum = max(sum, temp);
	} while (next_permutation(&arr[0], &arr[N]));

	return sum;
}

int main()
{
	int N, arr[maxNum] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(&arr[0], &arr[N]);

	cout << maxdiff(N, arr) << endl;
}