#include <iostream>
#define swap(a,b,c) {c=a; a=b; b=c;}

using namespace std;

int main()
{
	char A[4],B[4];
	char temp = 0;

	cin >> A >> B;

	swap(A[0], A[2], temp);
	swap(B[0], B[2], temp);

	cout << (atoi(A)>atoi(B) ? A : B) << endl;
}