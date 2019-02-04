#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << endl;
			continue;
		}
		double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (a > r1 + r2)
		{
			cout << 0 << endl;
		}
		else if (a == r1 + r2)
		{
			cout << 1 << endl;
		}
		else
		{
			if (r1 > r2 && r1 > a)
			{
				if (r2 + a == r1)
					cout << 1 << endl;
				else if (r2 + a < r1)
					cout << 0 << endl;
				else
					cout << 2 << endl;
				continue;
			}
			else if (r2 > r1 && r2 > a)
			{
				if (r1 + a == r2)
					cout << 1 << endl;
				else if (r1 + a < r2)
					cout << 0 << endl;
				else
					cout << 2 << endl;
				continue;
			}
			cout << 2 << endl;
		}
	}
}