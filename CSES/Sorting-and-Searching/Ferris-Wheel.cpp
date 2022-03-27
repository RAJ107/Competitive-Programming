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
 
	int n, x; cin >> n >> x;
    vector<int> wt(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    int l = 0, r = n-1, ans = 0;
    sort(wt.begin(), wt.end());
    while(r >= l)
    {
        if(x >= (wt[r] + wt[l])) l++;
        r --;
        ans ++;
    }
    cout << ans;
	return 0;
}