#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T, a, b;

	char s[4];
	cin >> T;

	while (T--)
	{
		cin >> s;
		cout << s[0] + s[2] - 96 << endl;
	}
}