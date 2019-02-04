#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n,temp=0,ans=0;

	cin >> n;

	temp = n;
	do 
	{
		temp = ((temp / 10 + temp % 10) % 10) + (temp % 10) * 10;
		ans++;
	} while (n != temp);

	cout << ans << endl;
}