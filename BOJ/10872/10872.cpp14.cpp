#include <iostream>
#include <vector>

using namespace std;

int Factorial(int n)
{
	int temp = 1;

	for (int i = 2; i <= n; i++)
		temp *= i;

	return temp;
}

int main()
{
	int n;
	cin >> n;

	printf("%d\n", Factorial(n));

}