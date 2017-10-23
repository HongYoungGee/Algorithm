#include <iostream>
using namespace std;
int main()
{
	int n;
	int *A, *B;
	cin >> n;
	
	A = new int[n];
	B = new int[n+1];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n+1; i++)
		B[i] = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] == n)
		{
			B[A[i]] = 1;
			continue;

		}
			
		if (B[A[i] + 1] == 0)
		{
			B[A[i]] = 2;
		}
		else
		{
			B[A[i]] = 1;
		}
			
	}
	int max = 0, num = 0;;
	for (int i = 0; i < n + 1; i++)
	{
		if (B[i] == 2)
			num++;
		else
			num = 0;
		if (num > max)
			max = num;
	}
	cout << n-1-max;
}