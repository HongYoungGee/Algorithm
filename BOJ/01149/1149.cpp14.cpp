#include <iostream>
#include <vector>

using namespace std;

void RGB_draw(int N, int arr[][1001], int cache[][1001]) //cache에 해당 색갈을 칠할수있는 최소값 저장
{
	for (int i = 0; i < 3; i++)
		cache[i][0] = arr[i][0];

	for (int i = 1; i < N; i++)
	{
		cache[0][i] = arr[0][i] + (cache[1][i - 1] > cache[2][i - 1] ? cache[2][i - 1] : cache[1][i - 1]);
		cache[1][i] = arr[1][i] + (cache[0][i - 1] > cache[2][i - 1] ? cache[2][i - 1] : cache[0][i - 1]);
		cache[2][i] = arr[2][i] + (cache[1][i - 1] > cache[0][i - 1] ? cache[0][i - 1] : cache[1][i - 1]);
	}
}

int minValue (int a, int b, int c)
{
	if (a > b)
	{
		if (b > c)
			return c;
		else
			return b;
	}
	else
	{
		if (a > c)
			return c;
		else
			return a;
	}
}

int main()
{
	int N, arr[3][1001], cache[3][1001];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];

	RGB_draw(N, arr, cache);

	cout << minValue(cache[0][N-1], cache[1][N - 1], cache[2][N - 1]) << '\n';
}