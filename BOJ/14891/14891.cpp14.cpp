#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std; 

void lotate(bitset<8> &tob, int direct) 
{
	if (direct == -1) tob = tob >> 1 | tob << (8 - 1); //오른쪽 1칸 (tob이 뒤집어져 있기 때문에)
	else if (direct == 1) tob = tob << 1 | tob >> (8-1); //왼쪽 1칸 (tob이 뒤집어져 있기 때문에)
}

int main()
{
	bitset<8> tobni[4];
	char arr[10];
	for (int i = 0; i < 4; i++) //입력
	{
		scanf("%s", arr); 
		for (int j = 7; j >= 0; j--) tobni[i].set(j,arr[j]-'0');
	}

	int K, num, direct;
	scanf("%d", &K);

	while (K--) 
	{
		scanf("%d %d", &num, &direct);
		vector<int> v(1,num-1);

		for (int i = v[0]+1; i < 4; i++) //오른쪽 i-1이 돌아갈때 i는?
			if (tobni[i - 1].test(2) != tobni[i].test(6)) v.push_back(i);
			else break;

		for (int i = v[0] - 1; i >= 0; i--) //왼쪽 i+1이 돌아갈때 i는?
			if (tobni[i + 1].test(6) != tobni[i].test(2)) v.push_back(i);
			else break;

		for (int i = 0; i < v.size(); i++) lotate(tobni[v[i]], direct * pow(-1, abs(v[i] - v[0]))); //회전
	}

	printf("%d\n", tobni[0].test(0) + tobni[1].test(0)*2 + tobni[2].test(0)*4 + tobni[3].test(0)*8);
}