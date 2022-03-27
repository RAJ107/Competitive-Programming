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
    vector<int> arr(n);
    int mx = -1;
    for(int i = 0; i < n; i++) {cin >> arr[i]; mx = max(mx, arr[i]);}
    int ans, low = mx, high = 1e16;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int sum = 0, cnt = 1;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum > mid)
            {
                cnt ++;
                sum = arr[i];
            }
        }
        if(cnt <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans;
	return 0;
}