#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string s;
	int arr[26] = { 0 }, max = 0, flag = -1;
	getline(cin, s);

	for (auto &c : s) c = toupper(c);
	
	for (int i = 0; i < s.size(); i++) arr[s[i] - 'A']++;

	for (int i = 1; i < 26; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
			flag = -1;
		}
		else if (arr[i] == arr[max])
			flag = 1;
	}

	if (flag==1)
		cout << "?" << endl;
	else
		cout << (char)('A'+max) << endl;
}