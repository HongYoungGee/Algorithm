#include <stdio.h>
#include <iostream>

using namespace std;

int cache[16][16] = { 0 };

int how_people(int a, int b)
{
	if (cache[a][b] != 0) return cache[a][b]; //cache hit

	if (a == 0) return cache[a][b] = b; //조건
	if (b == 1) return cache[a][b] = 1;

	return cache[a][b] = how_people(a - 1, b) + how_people(a , b - 1);
}

int main()
{
	int T, a, b;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", how_people(a, b));
	}
}