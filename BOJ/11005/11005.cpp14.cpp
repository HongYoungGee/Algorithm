#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string methodCon(int N, int B)
{
	string s;
	while (N > 0)
	{
		int a = N % B;

		if (a <= 9) s.push_back(a + '0');
		else s.push_back(a + 55);

		N /= B;
	}

	reverse(s.begin(), s.end());

	return s;
}

int main()
{
	int N, B;
	cin >> N >> B;
	
	cout << methodCon(N, B) << endl;
}