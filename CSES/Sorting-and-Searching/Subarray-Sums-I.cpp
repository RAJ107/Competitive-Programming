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
    int left = -1, sum = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        while(sum > x)
        {
            left ++;
            sum -= arr[left];
        }
        if(sum == x) ans ++;
    }
    cout << ans;
	return 0;
}