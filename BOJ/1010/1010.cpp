#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int a, b;
		double sum = 1;
		cin >> a >> b;
		for (int i = 0; i < a; i++)
			sum =sum*(b - i)/(i+1);
		cout << (int)sum << endl;
	}
}