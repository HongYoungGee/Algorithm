#include <string>
#include <iostream>

using namespace std;

void numberOfAlpa(string s, int arr[])
{
	for (int i = 0; i < s.size(); i++)
		arr[s[i] - 'a']++;
}

int main()
{
	string s;
	cin >> s;

	int arr[27] = { 0 };

	numberOfAlpa(s, arr);

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
}