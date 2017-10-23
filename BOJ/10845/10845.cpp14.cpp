#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int  T,temp;
	string s;
	queue<int> qu;

	cin >> T;
	while (T--)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> temp;
			qu.push(temp);
		}
		else if (s == "front")
			cout << (qu.empty() ? -1 : qu.front()) << endl;
		else if (s == "back")
			cout << (qu.empty() ? -1 : qu.back()) << endl;
		else if (s == "pop")
		{
			if(qu.empty())
				cout << -1 << endl;
			else
			{
				cout << qu.front() << endl;
				qu.pop();
			}
		}
		else if (s == "size")
			cout << qu.size() << endl;
		else if (s == "empty")
			cout << (qu.empty() ? 1 : 0) << endl;
	}
}


