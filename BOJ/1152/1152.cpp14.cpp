#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int temp = 0, x = 0,flag=0;
	string s;

	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			flag = 1;
		else if (s[i] == ' ' && flag == 1)
		{
			flag = 0;
			temp++;
		}
		if (i == s.size() - 1 && s[i] != ' ')
			temp++;

	}

	cout << temp<< endl;
}