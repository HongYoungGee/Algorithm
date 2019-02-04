#include <iostream>
#include <algorithm>

using namespace std;
#define maxNum 500003

void insertButton(int M, bool button[])
{
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		button[num] = false;
	}
}

int possibleNumber(int num, bool button[]) //num이 누를수 없는 버튼이면 0, 있으면 횟수
{
	if (num == 0) return button[0];

	int len = 0;
	while (num > 0)
	{
		if (!button[num % 10]) return 0;

		num /= 10;
		len++;
	}

	return len;
}

int remocon(int N, bool button[]) //0부터 100만까지 완탐
{
	int ans = abs(N - 100);

	for (int i = 0; i < maxNum * 2; i++)
	{
		int num = possibleNumber(i, button);
		if (num > 0 && ans > abs(N - i) + num)
			ans = abs(N - i) + num;
	}

	return ans;
}

int main()
{
	int N, M;
	bool button[10] = { 1,1,1,1,1,1,1,1,1,1 }; //안되면 false

	cin >> N>>M;

	insertButton(M, button);

	cout << remocon(N, button) << endl;
}