#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	list<char> li;
	string temp = "abcd";

	cin >> temp;
	cin >> n;

	for (int i = 0; i < temp.size(); i++)
	{
		li.push_back(temp[i]);
	}

	list<char>::iterator itor = li.end();

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp[temp.size() - 1] == 'L' && itor != li.begin())
			itor--;
		else if (temp[temp.size() - 1] == 'D' && itor != li.end())
			itor++;
		else if (temp[temp.size() - 1] == 'P')
		{
			cin >> temp;
			li.insert(itor, temp[temp.size() - 1]);
		}
		else if (temp[temp.size() - 1] == 'B' && itor != li.begin())
		{
				list<char>::iterator itor2 = itor;
				li.erase(--itor2);		
		}
	}

	for (itor = li.begin(); itor != li.end(); itor++)
		cout << *itor;

	cout << endl;
}

