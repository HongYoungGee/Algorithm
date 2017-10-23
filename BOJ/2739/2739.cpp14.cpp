#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, a, b;

	cin >> n;

	for (int i = 0; i < 9; i++)
		printf("%d * %d = %d\n",n, i + 1,(n*(i+1)));
}

