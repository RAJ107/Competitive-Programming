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
    vector<int> dp(n+1, 1e7);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        vector<bool> vis(10, false);
        for(auto ch : s) vis[ch - '0'] = true;
        for(int d = 1; d < 10; d++)
        {
            if(vis[d]) dp[i] = min(dp[i], 1 + dp[i-d]);
        }
    }
    cout << dp[n];
	return 0;
}