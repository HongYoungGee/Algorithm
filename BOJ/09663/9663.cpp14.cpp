#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

int N_Queen(int N, bitset<225> bit, int num=0, int must=0)
{
	if (num == N) return 1; // N개를 체스판에 두면 1 리턴
	if (bit.none()) return 0; //둘 곳이 없으면 0 리턴

	int ans = 0;
	for (int i = must; i < must+1; i++) //한줄에 하나는 놓아야함
		for (int j = 0; j < N; j++)
		{
			if (bit.test(i * N + j))
			{
				bitset<225> temp = bit;
				
				for (int x = i, y = 0; y < N; y++) temp.set(x*N + y, false); //i행 전부
				for (int x = 0, y = j; x < N; x++) temp.set(x*N + y, false); //j열 전부
				for (int x = i, y = j; x>=0 && y < N; x--, y++) temp.set(x*N + y, false); //오른쪽 위
				for (int x = i, y = j; x < N && y < N; x++, y++) temp.set(x*N + y, false); //오른쪽 아래
				for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) temp.set(x*N + y, false); //왼쪽 위
				for (int x = i, y = j; x < N && y >= 0; x++, y--) temp.set(x*N + y, false); //왼쪽 아래

				ans += N_Queen(N, temp, num + 1,must+1);
			}
			bit.set(i * N + j, false);
		}

	return ans;
}

int main()
{
	int N;
	cin >> N;
	bitset<225> bit;
	bit.set();
	
	cout << N_Queen(N, bit) << endl;
}