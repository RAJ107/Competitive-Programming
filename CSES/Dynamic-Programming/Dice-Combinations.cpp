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
 
	int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            if(i >= j) dp[i] += dp[i-j];
        }
        dp[i] %= MOD;
    }
    cout << dp[n];
	return 0;
}