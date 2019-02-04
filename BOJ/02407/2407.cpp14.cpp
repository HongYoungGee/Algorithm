#include <iostream>
#include <vector>
#define M 1000000000000000000UL
using namespace std;

class bigInteger
{
private:
	unsigned long long a, b; 

public:
	bigInteger(unsigned long long a = 0)
	{
		this->a = a;
		this->b = 0;
	};

	void print()
	{
		if (b == 0)
			printf("%llu", a);
		else
			printf("%llu%018llu", b, a);
	}

	bigInteger &operator+(const bigInteger &val)
	{
		b = b + val.b + (a + val.a) / M;
		a = (a + val.a) % M;

		return *this;
	}

	bool operator!=(unsigned long long a)
	{
		return this->a != a;
	}
};


#define Max_size 105 // The maximum size of a.
bigInteger cache[Max_size][Max_size];
bigInteger combination(int a, int b) // Compute aCb
{
	if (cache[a][b] != 0) return cache[a][b]; //cache hit

	if (a == b || b == 0) return cache[a][b] = 1; // nCn or nC0 = 1
	if (b == 1) return cache[a][b] = a;  // nC1 = n

	return cache[a][b]= combination(a - 1, b)+ combination(a - 1, b - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	combination(n, m).print();
}
