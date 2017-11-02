#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool PrimeArray[10001];
void Eratos(int n)
{
	if (n <= 1) return;

	for (int i = 2; i <= n; i++) PrimeArray[i] = true;

	for (int i = 2; (i*i) <= n; i++)
	{
		if (PrimeArray[i])
		{
			for (int j = i*i; j <= n; j += i) PrimeArray[j] = false;
		}
	}
}

int main()
{
	int T, Goldbach;
	Eratos(10000);

	cin >> T;
	while (T--)
	{
		cin >> Goldbach;

		for (int i = Goldbach/2; i > 1; i--)
			if (PrimeArray[i] && PrimeArray[Goldbach - i])
			{
				printf("%d %d\n", i, Goldbach - i);
				break;
			}
	}
}