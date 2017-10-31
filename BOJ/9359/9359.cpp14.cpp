#include <iostream>
#include <vector>
#include <algorithm>
#define Compute_prime 1000000
using namespace std;

bool* PrimeArray;

void swap(vector< long long> &arr, int i, int j)
{
	int temp;
	if (i != j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void Permutation(vector< long long> &arr, vector< long long> &arr2, int n, int r, int depth) //Permutation(N,R,0); NcR
{
	int i;
	long long mid_value = 1;
	if (n == r)
	{
		for (i = 0; i<r; i++) {
			mid_value *= arr[i];
		}
		arr2.push_back(mid_value);
		return;
	}
	if (r == depth) {
		for (i = 0; i<r; i++) {
			mid_value *= arr[i];
		}
		arr2.push_back(mid_value);
	}

	for (i = depth; i<n; i++) {
		swap(arr, i, depth);
		Permutation(arr, arr2, n, r, depth + 1);
		swap(arr, i, depth);
	}
}


long long numberOfMultuples(long long A, long long B, long long n)
{
	if (n == 1)
		return B + 1 - A;
	else if (A%n == 0)
		return (B / n) - (A / n) + 1;
	else
		return (B / n) - (A / n);
}

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

void Factorization(vector< long long> &arr, long long N)
{
	for (long long i = 2; i <= N; i++)
		if (i<Compute_prime && PrimeArray[i] && N%i == 0)
		{
			arr.push_back(i);
			while (N%i == 0) N /= i;
		}
		else if (i >= Compute_prime - 2)
		{
			arr.push_back(N);
			break;
		}
}

int main()
{
	int T;

	cin >> T;

	PrimeArray = new bool[Compute_prime + 1];
	Eratos(Compute_prime);

	for (int j = 0; j<T; j++)
	{
		long long A, B, N, sum = 0;
		cin >> A >> B >> N;

		vector< long long> arr;

		Factorization(arr, N);

		sum = B + 1 - A;
		for (int i = 1; i <= arr.size(); i++) //i가 1일때는 arr.size() C 1
		{
			vector< long long> arr2;
			Permutation(arr, arr2, arr.size(), i, 0);
			sort(arr2.begin(), arr2.end());
			arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
			if (i % 2 == 1) // -차례
			{
				for (int j = 0; j < arr2.size(); j++)
					sum -= numberOfMultuples(A, B, arr2[j]);

			}
			else // +차례
			{
				for (int j = 0; j < arr2.size(); j++)
					sum += numberOfMultuples(A, B, arr2[j]);
			}
		}

		printf("Case #%d: %lld\n", j + 1, sum);
	}
}