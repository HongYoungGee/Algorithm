#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int methodCon(string s, int B)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z') sum +=(s[i]-55)* pow(B, s.size() - i-1);
		else if (s[i] >= '1' && s[i] <= '9') sum += (s[i] -'0')* pow(B, s.size() - i-1);

	return sum;
}

int main()
{
	string s;
	int B;
	cin >> s >> B;
	
	cout << methodCon(s, B) << endl;
}