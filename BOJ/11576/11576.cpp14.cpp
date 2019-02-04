#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int Atoten(int A, int T)
{
	int sum = 0;
	while (T--)
	{
		int num;
		cin >> num;
		sum += num * pow(A, T); 
	}
	return sum;
}

void tenToB(int num, int B)
{
	vector<int> vec;
	while (num > 0)
	{
		vec.push_back(num%B);
		num /= B;
	}

	for (int i = vec.size()-1; i >= 0; i--)
		cout << vec[i] << endl;
}

int main()
{
	int A, B,T,sum=0;
	cin >> A >> B>>T;

	sum = Atoten(A, T);
	tenToB(sum, B);
}