#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() 
{
	int T, mi = 1000000, ma = -1000000;

	int temp;
	cin >> T;
	while (T--)
	{
		cin >> temp;
		mi = min(mi, temp);
		ma = max(ma, temp);
	}

	cout << mi << " " << ma << endl;
}