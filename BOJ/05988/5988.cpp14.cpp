#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int Ta;
	cin >> Ta;

	string s;

	for(int i=0; i<Ta; i++)
	{
		cin.ignore();
		getline(cin, s);
		
		cout << (s[s.length()-1]%2 ? "odd" : "even" )<< endl;
	}
}