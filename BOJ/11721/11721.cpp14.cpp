#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		printf("%c",s[i]);
		if (i % 10 == 9)
			printf("\n");
	}	

}

