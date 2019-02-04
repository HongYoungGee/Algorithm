#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, *arr;

	scanf("%d",&N);
	arr = new int[N + 2];
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);

	sort(arr, arr + N);
	
	for (int i = N-1; i >=0; i--) printf("%d\n", arr[i]);
}
