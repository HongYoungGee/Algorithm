#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T=1,answer=0;
	//cin >> T;
	while (T--)
	{
		int n;
		int *dp,*arr;
		cin >> n;
		dp = new int[n+1];
		arr = new int[n+1];
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++)
		{
			dp[i] = arr[i];
			int max = 0;
			for (int j = i - 1; j > 0; j--)
			{
				if (max < dp[i - j] + arr[j])
					max = dp[i - j] + arr[j];
			}
			if (dp[i] < max)
				dp[i] = max;
		}
		cout << dp[n]<<endl;
	}
	
}