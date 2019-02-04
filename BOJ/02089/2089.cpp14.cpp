#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string minusTwo(int N)
{
	if (N == 0) return "0";

	string ans;
	while (N != 0)
	{
		ans.push_back(abs(N % 2)+'0'); 

		if (N % 2 != 0 && N < 0) N--; //음수일 경우 1을 빼줌
		N /= -2;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	int N;
	cin >> N;
	
	cout << minusTwo(N) << endl;
}