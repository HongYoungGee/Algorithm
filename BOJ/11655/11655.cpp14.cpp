#include <string>
#include <iostream>

using namespace std;

string ROT13(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] <= 'm' && s[i] >= 'a') s[i] += 13;
		else if (s[i] <= 'z' && s[i] >= 'n') s[i] -= 13;
		else if (s[i] <= 'M' && s[i] >= 'A') s[i] += 13;
		else if (s[i] <= 'Z' && s[i] >= 'N') s[i] -= 13;

		return s;
}

int main()
{
	string s;

	getline(cin, s);


	cout << ROT13(s) << endl;
}