#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, temp, A_size, M_size;

	vector<int> A;

	scanf("%d", &A_size);
	while (A_size--) { scanf("%d", &temp); A.push_back(temp); }
	sort(A.begin(), A.end());

	scanf("%d", &M_size);
	while (M_size--)
	{
		scanf("%d", &temp);
		printf("%d\n", binary_search(A.begin(), A.end(), temp));
	}
}