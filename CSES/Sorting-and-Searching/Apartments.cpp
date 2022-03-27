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
 
	int n, m, k; cin >> n >> m >> k;
    vector<int> desired(n);
    for(int i = 0; i < n; i++) cin >> desired[i];
    multiset<int> apartment;
    for(int i = 0; i < m; i++)
    {
        int x; cin >> x;
        apartment.insert(x);
    }
    int ans = 0;
    sort(desired.begin(), desired.end());
    for(auto req : desired)
    {
        auto it = apartment.lower_bound(req - k);
        if(it != apartment.end() && (*it) <= (req + k))
        {
            ans ++;
            apartment.erase(it);
        }
    }
    cout << ans;
	return 0;
}