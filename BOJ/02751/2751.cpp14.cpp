#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T,temp;
	vector<int> vc;

	cin >> T;
	while (T--)
	{
		cin >> temp;
		vc.push_back(temp);
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++)
		printf("%d\n", vc[i]);
}
