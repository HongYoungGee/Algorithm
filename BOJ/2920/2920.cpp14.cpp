#include <iostream>


using namespace std;

int main() {
	
	int sum=0,arr[8],temp;
	
	for(int i=0; i<8; i++)
	{
		cin>>temp;
		arr[i]=temp;
	}
	
	temp=arr[0]-arr[1];
	for(int i=1; i<7; i++)
	{
		if(temp != arr[i]-arr[i+1])
			temp=0;
	}
	if(temp==1)
		cout<<"descending"<<endl;
	else if(temp==0)
		cout<<"mixed"<<endl;
	else
		cout<<"ascending"<<endl;
	return 0;
}