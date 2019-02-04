#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool PrimeArray[1000001];
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
	int M, N,sum=0,min_prime=0;
	cin >> M>>N;

	Eratos(N);

	for (int i = M; i <= N; i++) 
		if (PrimeArray[i])
			printf("%d\n", i);
}