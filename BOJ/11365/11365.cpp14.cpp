#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;

	for(getline(cin, s); s!="END"; getline(cin, s))
	{
		for (int i = s.length() - 1; i >= 0; i--)
			cout << s[i];

		cout << endl;
	}
}