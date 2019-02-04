#include <iostream>

using namespace std;

int main()
{
	int n, sum = 1, ans = 2;

	cin >> n;

	while ( n>sum) sum += ans++;

	cout <<(ans % 2 == 1 ? ans - sum + n - 1 : sum - n + 1 )<<"/"<< (ans % 2 == 1 ?  sum - n + 1 : ans - sum + n - 1) << endl;
}
