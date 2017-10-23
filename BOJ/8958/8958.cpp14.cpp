#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
	int T,arr[82];
	string s;

	cin >> T;
	while (T--)
	{
		cin >> s;
		int sum = 0;
		
		for (int i = 0; i < s.size() + 1; i++)
			arr[i] = 0;

		for (int i = 1; i < s.size() + 1; i++)
			if (s[i - 1] == 'O')
			{
				arr[i] = arr[i - 1] + 1;
				sum += arr[i];
			}

		cout << sum << endl;
	}
}