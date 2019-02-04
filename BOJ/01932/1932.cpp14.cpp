#include <iostream>
#include <vector>

using namespace std;

void Triangle_draw(int n, int arr[][501], int cache[][501]) //바로위 또는 위 왼쪽만 접근가능
{
	cache[0][0] = arr[0][0];

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			if (j == 0)
				cache[i][j] = arr[i][j] + cache[i - 1][j];
			else if (j == i)
				cache[i][j] = arr[i][j] + cache[i - 1][j - 1];
			else
				cache[i][j] = arr[i][j] + (cache[i - 1][j] > cache[i - 1][j - 1] ? cache[i - 1][j] : cache[i - 1][j - 1]);
}

int maxValue (int n, int cache[][501])
{
	int max = 0;

	for (int i = 0; i < n; i++)
		if (cache[n - 1][i] > max)
			max = cache[n - 1][i];

	return max;
}

int main()
{
	int n, arr[501][501], cache[501][501];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			scanf("%d", &arr[i][j]);

	Triangle_draw(n, arr, cache);

	cout << maxValue(n, cache) << '\n';
}