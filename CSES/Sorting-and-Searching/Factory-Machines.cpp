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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans, low = 0, high = 1e18;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int res = 0;
        for(int i = 0; i < n && res < x; i++) res += mid/arr[i];
        if(res >= x) 
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans;
	return 0;
}