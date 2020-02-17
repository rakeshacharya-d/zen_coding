/*
Appy and Chef are participating in a contest. There are N problems in this contest; 
each problem has a unique problem code between 1 and N inclusive. Appy and Chef decided to 
split the problems to solve between them ― Appy should solve the problems whose problem codes are 
divisible by A but not divisible by B, and Chef should solve the problems whose problem codes are 
divisible by B but not divisible by A (they decided to not solve the problems whose codes are divisible 
by both A and B).*/


#include <iostream>
using namespace std;

long int gcd(long int a, long int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if(a==b)
	  return a;
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}
long int lcm(long int a, long int b)
{
	long int g = gcd(a, b);
	return (a * b / g);
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		long int n, a, b, k;
		cin >> n;
		cin >> a;
		cin >> b;
		cin >> k;
		long int cnta, cntb, cntab;
		cnta = n / a;
		cntb = n / b;
		cntab = n / lcm(a, b);
		if (cnta + cntb - 2 * cntab >= k)
			cout << "Win\n";
		else
			cout << "Lose\n";

	}

	return 0;


}
