#include <iostream>
#include <algorithm>

#define maxNum 8+3

using namespace std;

bool nextPermutation(int N, int arr[])
{
	int maxi = N - 1;
	while (maxi > 0 && arr[maxi - 1] > arr[maxi]) maxi--;
	if (maxi == 0) return false;

	int maxj = N - 1;
	for (; maxj > maxi; maxj--) if (arr[maxj] > arr[maxi - 1]) break;

	swap(arr[maxi - 1], arr[maxj]);

	for (int i = maxi; i < (N + maxi) / 2; i++)
		swap(arr[i], arr[N + maxi - i - 1]);
}

void printarr(int N, int arr[])
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int N, arr[maxNum] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) arr[i] = i + 1;

	do { printarr(N, arr);} 
	while (nextPermutation(N, arr));
}