#include <iostream>
//#define swap_max(a, b) {if(b>a){unsigned long long temp=a; a=b; b=temp;}}

using namespace std;

int main()
{
	unsigned long long a, b, temp;
	cin >> a >> b;

	//swap_max(a, b);

	temp = a%b;
	while (temp)
	{
		a = b;
		b = temp;
		temp = a%b;
	}
    
    cout << string(b, '1') << endl;
}
