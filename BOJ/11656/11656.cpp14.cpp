#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void suffix(string s, vector<string> *vec)
{
	for(int i=0; i<s.size(); i++)
		vec->push_back(s.substr(i,s.size()-i));
	
	sort(vec->begin(), vec->end());
}

int main()
{
	string s;
	vector<string> vec;

	cin >> s;
	suffix(s, &vec);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}

