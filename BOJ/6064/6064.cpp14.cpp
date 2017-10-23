#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define swap_max(a,b,c,d) {if(a>b) {int temp=a; a=b; b=temp; temp=c; c=d; d=temp;}}

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int main()
{
	int T, M, N, x, y;

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> x >> y;

		swap_max(M, N,x,y);
		unsigned int ans = x, max_case = M*N / gcd(M, N);

		while (ans <= max_case && y != x)
		{
			ans += M;
			x = ((x - 1 + M) % N) + 1;
			if (y == x)
				break;
		}

		if (ans > max_case)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
}