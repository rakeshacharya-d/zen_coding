/*
Author : Dharoori Rakesh Acharya
Language : C++

After visiting a childhood friend, Chef wants to get back to his home. 
Friend lives at the first street, and Chef himself lives at the N-th (and the last) street. 
Their city is a bit special: you can move from the X-th street to the Y-th street if and only 
if 1 <= Y - X <= K, where K is the integer value that is given to you. Chef wants to get to home 
in such a way that the product of all the visited streets' special numbers is minimal (including 
the first and the N-th street). Please, help him to find such a product.*/
/*-----------------------------------------------------------------------------------------------*/

#include <iostream>
#include<vector>
#include<set>
using namespace std;
#define mod (long)(1e9+7)
int main() {
	int n, t;
	cin >> n >> t;
	vector<long>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	multiset<pair<double, long>> s;
	vector<pair<double, long>> dp(n);
	dp[0] = { log10(arr[0]),arr[0] };
	s.insert({ log10(arr[0]),arr[0] });
	for (int i = 1; i <= t; ++i)
	{
		auto x = *s.begin();
		s.insert({ x.first + log10(arr[i]),(x.second * arr[i]) % mod });
		dp[i] = { x.first + log10(arr[i]),(x.second * arr[i]) % mod };
	}
	for (int i = 0; i + t + 1 < n; ++i)
	{
		s.erase(s.find(dp[i]));
		auto x = *s.begin();

		s.insert({ x.first + log10(arr[i + t + 1]),(x.second * arr[i + t + 1]) % mod });
		dp[i + t + 1] = { x.first + log10(arr[i + t + 1]),(x.second * arr[i + t + 1]) % mod };


	}
	cout << dp[n - 1].second;
	return 0;
}
