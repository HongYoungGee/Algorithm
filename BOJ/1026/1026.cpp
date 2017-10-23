#include <iostream>
using namespace std;
int main()
{
	int n;
	int *A, *B,*A1,*B1,*temp;
	cin >> n;
	
	A = new int[n];
	B = new int[n];
	A1 = new int[n];
	B1 = new int[n];
	temp = new int[n];
	
	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		cin >> B[i];

	for (int i = 0; i < n; i++)
		temp[i] = B[i];
	
	int min, temp2;                   //B선택정렬
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (temp[j] < temp[min]) min = j;
		}
		temp2 = temp[i];
		temp[i] = temp[min];
		temp[min] = temp2;
	}

	for (int i = 0; i < n; i++)           //B우선순위
	{
		for (int j = 0; j < n; j++)
		{
			if (B[i] == temp[j])
			{
				temp[j] = -1;
				B1[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		temp[i] = A[i];

                  //A선택정렬
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (temp[j] < temp[min]) min = j;
		}
		temp2 = temp[i];
		temp[i] = temp[min];
		temp[min] = temp2;
	}

	for (int i = 0; i < n; i++)           //A우선순위
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == temp[j])
			{
				temp[j] = -1;
				A1[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (n-1 - B1[i] == A1[j])
			{
				temp2 = A1[i];
				A1[i] = A1[j];
				A1[j] = temp2;

				temp2 = A[i];
				A[i] = A[j];
				A[j] = temp2;
				break;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += A[i] * B[i];

	cout << sum;
}