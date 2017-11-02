#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	list<int>  list1;
	

	for (int i = m + 1; i <= n; i++) list1.push_back(i);
	for (int i = 1; i < m; i++) list1.push_back(i);

	list<int>::iterator itor = list1.begin();
	list<int>::iterator itor2;

	cout << "<"<<m;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (itor == --list1.end())
				itor = list1.begin();
			else
				itor++;
		}
		cout << ", " << *itor;
		itor2 = itor;
		if (itor == --list1.end())
			itor = list1.begin();
		else
			itor++;
		list1.erase(itor2);

	}
	cout << ">" << endl;


}