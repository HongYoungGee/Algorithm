#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,a,b;

	cin >> n;

	a = n / 5;


	while(a+1)
	{
		if ((n - a * 5) % 3 != 0)
			a--;
		else
		{
			cout << ((n - a * 5) / 3 + a) << endl;
			break;
		}
	}
	
	if (a == -1)
		cout << a << endl;
}

