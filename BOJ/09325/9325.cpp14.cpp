#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;

	scanf("%d", &T);
	while (T--)
	{
		int sum = 0,n;
		scanf("%d %d", &sum,&n);

		while (n--) {
			int num, price;
			scanf("%d %d", &num, &price);
			sum += num*price;
		}

		printf("%d\n", sum);
	}
}