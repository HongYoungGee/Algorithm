#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, sum = 0;;

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (i <= 99)
			sum++;
		else if ((i % 10 - i / 10 % 10) == (i / 10 % 10 - i / 100))
			sum++;
	}

	cout << sum << endl;
}