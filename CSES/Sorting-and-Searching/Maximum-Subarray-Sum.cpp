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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = arr[0], sum = arr[0];
    for(int i = 1; i < n; i++)
    {
        sum = max(sum, 0LL);
        sum += arr[i];
        ans = max(ans, sum);
    }
    cout << ans;
	return 0;
}