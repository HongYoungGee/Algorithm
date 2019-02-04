#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

#define maxNum 10000+3

using namespace std;

bool nextPermutation(int N, int arr[])
{
	int maxi = N-1;
	while (maxi > 0 && arr[maxi - 1] > arr[maxi]) maxi--;
	if (maxi == 0) return false;

	int maxj = N - 1;
	for (; maxj > maxi; maxj--) if (arr[maxj] > arr[maxi - 1]) break;

	swap(arr[maxi - 1], arr[maxj]);

	for (int i = maxi; i < (N + maxi) / 2; i++)
		swap(arr[i], arr[N + maxi - i-1]);
}

void printarr(int N, int arr[])
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}

int main()
{
	int N, arr[maxNum] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	if (nextPermutation(N, arr)) printarr(N, arr);
	else cout << -1 << endl;
}