#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int M, x, S = 0;
	char instruct[10];

	scanf("%d", &M);
	while (M--)
	{
		scanf("%10s", instruct);

		if (instruct[1] != 'l' && instruct[0] != 'e') scanf("%d", &x);

		if (instruct[1] == 'd') S = S | (1 << x);
		else if (instruct[0] == 'r') S = S & ~(1 << x);
		else if (instruct[0] == 'c') cout << (bool)(S & (1 << x)) << '\n';
		else if (instruct[0] == 't') S=S^(1<<x);
		else if (instruct[1] == 'l') S=S| ((1<<21)-1);
		else if (instruct[0] == 'e') S = S & 0;
	}
}