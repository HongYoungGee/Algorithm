#include <string>
#include <iostream>

using namespace std;

void numberOfAlpa(string s, int &small_letter, int &capital, int &number, int &space)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] <= 'z' && s[i] >= 'a') small_letter++;
		else if (s[i] <= 'Z' && s[i] >= 'A') capital++;
		else if (s[i] <= '9' && s[i] >= '0') number++;
		else if (s[i] == ' ') space++;
}

int main()
{
	string s;

	while (getline(cin, s))
	{
		int small_letter = 0, capital = 0, number = 0, space = 0;

		numberOfAlpa(s, small_letter, capital, number, space);

		cout << small_letter << " " << capital << " " << number << " " << space << endl;
	}

}