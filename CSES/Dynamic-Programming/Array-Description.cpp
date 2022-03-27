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
 
	int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int> > dp(n, vector<int> (m+1));
    if(arr[0]) dp[0][arr[0]] = 1;
    else 
    {
        for(auto i = 1; i <= m; i++) dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != 0)
        {
            dp[i][arr[i]] = dp[i-1][arr[i]-1] + dp[i-1][arr[i]];
            if(arr[i] < m) dp[i][arr[i]] += dp[i-1][arr[i]+1];
            dp[i][arr[i]] %= MOD;
        } 
        else 
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                if(j < m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) ans += dp[n-1][i];
    ans %= MOD;
    cout << ans;
	return 0;
}