#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	while (s != "EOI")
	{
		int flag = 0;
		bool ans = false;

		for (int i = 0; i < s.length(); i++)
		{
			if (flag == 0 && (s[i] == 'n' || s[i] == 'N'))
			{
				flag = 1;
			}
			else if (flag == 1)
			{
				if (s[i] == 'e' || s[i] == 'E')
					flag = 2;
				else
					flag = 0;
			}
			else if (flag == 2)
			{
				if (s[i] == 'm' || s[i] == 'M')
					flag = 3;
				else
					flag = 0;
			}
			else if (flag == 3)
			{
				if (s[i] == 'o' || s[i] == 'O')
				{
					ans = true;
					break;
				}
				else
					flag = 0;
			}
		}

		cout << (ans ? "Found" : "Missing") << endl;
		getline(cin, s);
	}
}