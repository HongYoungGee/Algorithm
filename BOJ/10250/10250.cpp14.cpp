#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
	int T, H, W, N;

	cin >> T;

	while (T--)
	{
		cin >> H >> W >> N;

		if (N%H != 0)
		{
			printf("%d", N%H);
			if (N / H + 1 < 10)
				printf("0");
			printf("%d\n", N / H + 1);
		}
		else
		{
			printf("%d", H);
			if (N / H < 10)
				printf("0");
			printf("%d\n", N / H);
		}

		
	}

}
