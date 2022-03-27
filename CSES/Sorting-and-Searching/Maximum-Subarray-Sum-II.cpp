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
    
    int n, a, b; cin >> n >> a >> b;
    vector<int> pre(n+1);
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		pre[i] = pre[i-1] + x;
	}
	multiset<int> S;
	int ans = -1e15;
	for(int i = 0; i <= n; i++)
	{
		if(i-b-1 >= 0) S.erase(S.find(pre[i-b-1]));
		if(i >= a) 
		{
			S.insert(pre[i-a]);
			ans = max(ans, pre[i] - (*S.begin()));
		}
		// cout << pre[i] << " " << ans << "\n";
		// for(auto x : S) cout << x << " "; cout << "\n";
	}
	cout << ans;
	return 0;
}