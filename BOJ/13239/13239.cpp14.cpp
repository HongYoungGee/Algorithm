#include <stdio.h>
#include <iostream>

using namespace std;

int cache[1001][501] = { 0 };

int combination(int a, int b)
{
	if (cache[a][b] != 0) return cache[a][b]; //cache hit

	if (a == b || b == 0) return cache[a][b] = 1; //조건
	if (b == 1) return cache[a][b] = a;

	return cache[a][b] = (combination(a - 1, b) + combination(a - 1, b - 1)) % 1000000007;
}

int main()
{
	int T, a, b;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &a, &b);

		if (b > a / 2)
			b = a - b;

		printf("%d\n", combination(a, b));
	}
}