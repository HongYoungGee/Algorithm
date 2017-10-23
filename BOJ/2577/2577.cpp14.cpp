#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

int main() {
	int a,b,c,sum;
	cin >> a>>b>>c;
	sum = a*b*c;
	int arr[10] = { 0 };

	while (sum)
	{
		arr[sum % 10]++;
		sum /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;

}