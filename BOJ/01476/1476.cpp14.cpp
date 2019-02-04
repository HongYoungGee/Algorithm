#include <iostream>

using namespace std;

int main()
{
	int e, s, m;
	cin >> e >> s >> m;

	int temp = s - 1;

	while (!((temp - e + 1) % 15 == 0) || !((temp - m + 1) % 19 == 0))
	{
		temp += 28;
	}

	cout << temp + 1 << endl;

}