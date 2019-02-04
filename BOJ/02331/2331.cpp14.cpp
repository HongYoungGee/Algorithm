#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>

#define maxNum 236196+100

using namespace std;

int cal(int num,int P) //각 자리수를 P만큼 곱한것의 합 출력
{
	int sum = 0;
	for(;num>0; num/=10)
		sum+= pow(num % 10, P);

	return sum;
}

int repeatNumber(int N, int P) 
{
	int check[maxNum] = { 0 };

	int num = N,count=1;
	while (check[num] == 0) //0이 아닐 경우 반복 시작
	{
		check[num] = count++;
		num = cal(num, P);
	}

	return check[num] - 1;
	
}

int main()
{
	int N, P;
	cin >> N>> P;

	cout << repeatNumber(N, P) << '\n';
}