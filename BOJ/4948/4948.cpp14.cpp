#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool PrimeArray[246913];
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
	int temp;
	Eratos(246912);

	while (scanf("%d", &temp))
	{
		if (temp == 0)
			break;
		
		int sum = 0;
		for (int i = temp+1; i <= temp * 2; i++)
			if (PrimeArray[i])
				sum++;

		printf("%d\n", sum);
	}
}