#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Climbing_stairs(int n, int arr[], int cache[][2]) 
{
	cache[0][0] = arr[0];
	cache[0][1] = 0;

	cache[1][0] = arr[0]+arr[1];
	cache[1][1] = arr[1]; 

	for (int i = 2; i < n; i++)
	{
		cache[i][0] = arr[i] + cache[i-1][1]; //직전 밟기
		cache[i][1] = arr[i] + (cache[i-2][0] > cache[i-2][1] ? cache[i - 2][0] : cache[i - 2][1]); //직전 안밟기
	}
}



int main()
{
	int n, arr[301], cache[301][2]; //0 직전 계단을 밟고 최대값, 1 직전 계단을 안밟고 최대값
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Climbing_stairs(n, arr, cache);

	printf("%d\n", max(cache[n-1][0], cache[n-1][1]));
}