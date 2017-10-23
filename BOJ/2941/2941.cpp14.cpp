#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int ans;
	char s[101];
	
	cin >> s;
	ans = strlen(s);
	for (int i = 0; i <strlen(s)-1; i++)
		if (s[i] == 'c' && s[i + 1] == '=')
			ans--;
		else if (s[i] == 'c' && s[i + 1] == '-')
			ans--;
		else if (s[i] == 'd' && s[i + 1] == '-')
			ans--;
		else if (s[i] == 'l' && s[i + 1] == 'j')
			ans--;
		else if (s[i] == 'n' && s[i + 1] == 'j')
			ans--;
		else if (s[i] == 's' && s[i + 1] == '=')
			ans--;
		else if (i != 0 && s[i-1]=='d' && s[i] == 'z' && s[i + 1] == '=')
			ans-=2;
		else if (s[i] == 'z' && s[i + 1] == '=')
			ans--;
	cout << ans << endl;
}
