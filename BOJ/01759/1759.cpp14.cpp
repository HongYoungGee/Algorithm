#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void makeCrypto(int L,int C, char *vec,int vowel=1, int consonant=2, string s="")
{
	if (s.size() == L && vowel<=0 && consonant <=0) cout << s << endl;
	else
	{
		for (int i = 0; i < C; i++)
			if (vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u')
				makeCrypto(L,C-1-i, vec + 1+i, vowel - 1, consonant, s + vec[i]);
			else
				makeCrypto(L,C-1-i, vec + 1 +i, vowel, consonant -1 , s + vec[i]);
	}
}

int main()
{
	int L, C;
	cin >> L >> C;

	char p[16];
	for(int i=0; i<C; i++)
		cin >> p[i];
	sort(p, p+C);	

	makeCrypto(L, C, p);
}