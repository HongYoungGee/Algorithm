#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, x,temp;

	cin >> n >> x;

	while (n--)
	{
		cin >> temp;
		if (temp < x)
			cout << temp << " ";
	}



}


