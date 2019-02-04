#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int cache[103][10] = { 0 };

int Number_of_stairs(int N, int a) //a로 시작하는 N자리 만들수 있는 계단수의 수
{
	if (N == 1)
		return 1;

	if (cache[N][a] != 0)
		return cache[N][a];

	int ans = 0;
	if (a - 1 >= 0)
		ans += Number_of_stairs(N - 1, a - 1);
	if (a + 1 < 10)
		ans += Number_of_stairs(N - 1, a + 1);

	return cache[N][a]=ans % 1000000000;
}


int main()
{
	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i < 10; i++)
		ans = (ans + Number_of_stairs(N, i)) % 1000000000;

	printf("%d\n", ans);
}