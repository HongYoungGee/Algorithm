#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int count_5 = 0; //5가 항상 작기때문에 2는 안새고 5만.

	for (int i = 5; i <= n; i *= 5) count_5 += n / i; 
    //n에서 5로 나눠지는 갯수, 25로 나눠지는 갯수...

	printf("%d\n", count_5);
}