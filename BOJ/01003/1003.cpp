#include <iostream>

using namespace std;

int main()
{
	int num[41];
	num[0] = 0;
	num[1] = 1;
	num[2] = 1;
	for (int i = 3; i <= 40; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			cout << 1 << " " << 0 << endl;
			continue;
		}
		cout << num[n-1] << " " << num[n] << endl;
	}
}