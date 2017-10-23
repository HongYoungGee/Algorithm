#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int a,b,c;
	int x, y, z;

	cin >> a>>b>>c;

	x = max(max(a, b), c);

	if (x == a)
		cout << max(b, c) << endl;
	else if (x == b)
		cout << max(a, c) << endl;
	else
		cout << max(a, b) << endl;

}


