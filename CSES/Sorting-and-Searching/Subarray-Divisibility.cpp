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
    vector<int> cnt(n);
    cnt[0] = 1;
    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        sum = (sum + x) % n;
        if(sum < 0) sum += n;
        ans += cnt[sum];
        cnt[sum] ++;
    }
    cout << ans;
	return 0;
}