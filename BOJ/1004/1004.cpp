#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;
		int a = 0;
		for (int j = 0; j < n; j++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			double num1 = pow(x - x1, 2) + pow(y - y1, 2);
			double num2 = pow(x - x2, 2) + pow(y - y2, 2);
			if ((num1<r*r && num2>r*r) || (num1>r*r && num2<r*r))
				a++;
		}
		cout << a << endl;
	}
}