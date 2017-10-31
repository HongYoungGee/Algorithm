#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N, temp, sum = 0, ma = 0,flag=-1;
	cin >> N;

	vector<int> vec, frequency;
	frequency.resize(N,1);

	for (int i = 0; i < N; i++) { scanf("%d",&temp);  vec.push_back(temp); }

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		sum += vec[i];

		if (i>0 && vec[i] == vec[i - 1])
			frequency[i] = frequency[i - 1] + 1;

		ma=max(ma, frequency[i]);
	}

	for (int i = 0; i < N; i++)
		if (frequency[i] == ma && flag == -1)
			flag = i;
		else if (frequency[i] == ma && flag != -1)
		{
			flag = i;
			break;
		}
		
	printf("%.0lf %d %d %d", 1.0*sum / N, vec[N/2] , vec[flag], vec[N-1]-vec[0]);
	
}