#include <iostream>


using namespace std;

int main() {
	
	int sum=0,temp;
	
	for(int i=0; i<5; i++)
	{
		cin>>temp;
		sum+= temp>40 ? temp : 40;
	}
	
	cout<<sum/5<<endl;
	return 0;
}