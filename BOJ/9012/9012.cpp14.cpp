#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
	int T;
	string s;

	cin >> T;
	while (T--)
	{
		cin >> s;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				sum++;
			else if (s[i] == ')')
				sum--;
			if (sum < 0)
				break;
		}

		cout << (sum == 0 ? "YES" : "NO") << endl;


	}
}