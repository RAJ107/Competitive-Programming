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
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '*') {dp[j] = 0; continue;}
            if(j) dp[j] += dp[j-1];
            dp[j] %= MOD;
        }
        // for(int j = 0; j < n; j++) cout << dp[j] << " "; cout << "\n";
    }
    cout << dp[n-1];
	return 0;
}