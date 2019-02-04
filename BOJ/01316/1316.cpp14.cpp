#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int  T,sum=0;
	string s;
	
	cin >> T;
	sum = T;
	while (T--)
	{
		cin >> s;
		int arr[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
			if (arr[s[i] - 'a'] == 0)
				arr[s[i] - 'a'] = 1;
			else if (s[i] != s[i - 1])
			{
				sum--;
				break;
			}
	}

	cout << sum << endl;
}
