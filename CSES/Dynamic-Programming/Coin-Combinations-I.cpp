#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	int n, sum; cin >> n >> sum;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for(int i = 1; i <= sum; i++)
    {
        for(auto c : coin)
        if(i >= c) dp[i] += dp[i-c];
        dp[i] %= MOD;
    }
    cout << dp[sum];
	return 0;
}