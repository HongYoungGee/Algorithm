#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long int sum;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
			b = (b % 4)+4;
			sum = pow(a, b);
        	if (sum % 10 == 0)
			{
				cout << 10 << endl;
				continue;
			}
		cout << sum%10 << endl;
	}
}