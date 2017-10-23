#include <iostream>
#include <string>

using namespace std;

int main()
{
    int arr[26];
   string s;
   cin>>s;
   
   for(int i=0; i<26; i++)
        arr[i]=-1;
   
   for(int i=s.size()-1; i>=0; i--)
        arr[s[i]-'a']=i;
        
    for(int i=0; i<26; i++)
        printf("%d ",arr[i]);
}