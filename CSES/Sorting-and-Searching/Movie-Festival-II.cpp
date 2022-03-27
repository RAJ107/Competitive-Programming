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
    
    int n, k; cin >> n >> k;
    vector<pair<int, int> > arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int ans = 0;
    multiset<int> S;
    for(int i = 0; i < n; i++)
    {
        while(!S.empty() && (*S.begin()) <= arr[i].first) S.erase(S.begin());
        if(S.size() < k)
        {
            S.insert(arr[i].second);
            ans ++;
        }
        else 
        {
            S.insert(arr[i].second);
            S.erase(S.find(*S.rbegin()));
        }
    }
    cout << ans;
	return 0;
}