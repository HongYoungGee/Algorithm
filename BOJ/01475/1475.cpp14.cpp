#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
	int n, arr[10] = { 0 }, ma = 0;;
	
	cin >> n;
	if (n == 0) ma = 1;

	while (n > 0)
	{
		arr[n % 10]++;
		n /= 10;
	}
	arr[6] = arr[9] = (arr[6] + arr[9] + 1) / 2;

	for (int i = 0; i < 10; i++) if (arr[i] > ma) ma = arr[i];

	printf("%d\n", ma);
}
