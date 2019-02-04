#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x, y, arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string s[7] = { "MON","TUE", "WED", "THU", "FRI", "SAT","SUN" };

	cin >> x >> y;

	for (int i = 0; i < x; i++)
		y += arr[i];

	cout << s[(y - 1) % 7] << endl;

}

