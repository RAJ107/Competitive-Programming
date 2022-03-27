#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll MOD = 1e9 + 7;
 
vector<vector<ll> > dp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);
  
  ll n, m; cin >> n >> m;
  vector<ll> arr(n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  dp.resize(n, vector<ll> (m+1, 0));
  if(arr[0] == 0)
  {
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
  }
  else dp[0][arr[0]] = 1;
  for(int i = 1; i < n; i++)
  {
        if(arr[i] > 0)
        {
              for(auto k : {arr[i]-1, arr[i], arr[i]+1})
              {
                    if(k > 0 && k <= m) (dp[i][arr[i]] += dp[i-1][k]) %= MOD;
              }
        }
        else 
        {
              for(int k = 1; k <= m; k++)
              {
                    if(k < m) (dp[i][k] += (dp[i-1][k-1] + dp[i-1][k] + dp[i-1][k+1])) %= MOD;
                    else (dp[i][k] += (dp[i-1][k-1] + dp[i-1][k])) %= MOD;
              }
        }
  }
  for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= m; j++) cout << dp[i][j] << ' ';
        cout << '\n';
    }
  ll ans = 0;
  for(int i = 1; i <= m; i++) (ans += dp[n-1][i]) %= MOD;
  cout << ans;
  return 0;
}
 