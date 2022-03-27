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
 
	int n, req; cin >> n >> req;
    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];
    vector<int> dp(req+1, 1e10);
    dp[0] = 0;
    for(int i = 1; i <= req; i++)
    {
        for(auto c : coin) if(i >= c) dp[i] = min(dp[i], dp[i-c] + 1);
    }
    cout << (dp[req] == 1e10 ? -1 : dp[req]);
	return 0;
}