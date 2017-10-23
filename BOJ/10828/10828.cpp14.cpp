#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int  T, temp;
	string s;
	stack<int> qu;

	cin >> T;
	while (T--)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> temp;
			qu.push(temp);
		}
		else if (s == "top")
			cout << (qu.empty() ? -1 : qu.top()) << endl;
		else if (s == "pop")
		{
			if (qu.empty())
				cout << -1 << endl;
			else
			{
				cout << qu.top() << endl;
				qu.pop();
			}
		}
		else if (s == "size")
			cout << qu.size() << endl;
		else if (s == "empty")
			cout << (qu.empty() ? 1 : 0) << endl;
	}
}
