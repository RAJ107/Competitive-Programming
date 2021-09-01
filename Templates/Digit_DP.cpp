#include <bits/stdc++.h>
#define ll long long
const ll MOD = (1e9 + 7);
using namespace std;

ll dp[20][10][2][2];
vector<int> digits;


ll calculate(ll pos, ll prev, int equal, int leading_zero)
{
	if(pos == digits.size()) return 1; // base case, we reach the end

	if(dp[pos][prev][equal][leading_zero] != -1) return dp[pos][prev][equal][leading_zero]; // already calculated

	ll res = 0; // the result variable
	ll limit = 9; // setting the limit
	if(equal) limit = digits[pos]; // resetting the limit for special case

	for(int d = 0; d <= limit; d++) // the algorithm
	{
		if(leading_zero) res += calculate(pos+1, d, equal & (d == limit), leading_zero & (d == 0));
		else 
		{
			if(d == prev) continue;
			res += calculate(pos+1, d, equal & (d == limit), leading_zero);
		}
	}
	return dp[pos][prev][equal][leading_zero] = res; // returning the obtained result
}

ll solve(ll n)
{
	if(n < 0) return 0;
	if(n == 0) return 1;
	digits.clear();
	while(n)
	{
		digits.push_back(n%10);
		n /= 10;
	}
	reverse(digits.begin(), digits.end());
	memset(dp, -1, sizeof(dp));
	return calculate(0, 0, 1, 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ll a, b; cin >> a >> b;
	cout << solve(b) - solve(a-1);
	return 0;
}