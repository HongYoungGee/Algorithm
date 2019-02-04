#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long cache[50] = { 0,1,1,2,0 };
unsigned long long pivonachi(int n)
{
	if (n == 0 || cache[n] != 0) return cache[n];

	return cache[n] = pivonachi(n - 1) + pivonachi(n - 2);
}


int main()
{
	int T,n;
	scanf("%d", &T);

	pivonachi(47);

	while (T--)
	{
		int max_pivonachi = 45;
		vector<int> arr;

		scanf("%d", &n);

		while (n>0)
		{
			if (cache[max_pivonachi] <= n)
			{
				arr.push_back(cache[max_pivonachi]);
				n -= cache[max_pivonachi];
			}

			max_pivonachi--;
		}

		for (int i = arr.size() - 1; i >= 0; i--)
			printf("%d ", arr[i]);

		printf("\n");
	}
}