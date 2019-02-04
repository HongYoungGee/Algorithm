#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void factoring(int n)
{
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i << endl;
			n /= i;
			i--;
		}
	}

	if(n >1)
		cout << n << endl;
}

int main()
{
	int N;
	cin >> N;

	factoring(N);
}