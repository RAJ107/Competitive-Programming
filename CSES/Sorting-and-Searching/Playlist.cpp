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
    set<int> S;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0, left = 0;
    for(int i = 0; i < n; i++)
    {
        if(S.find(arr[i]) != S.end())
        {
            ans = max(ans, i - left);
            while(arr[left] != arr[i])
            {
                S.erase(arr[left]);
                left ++;
            }
            S.erase(arr[left]);
            left ++;
        }
        S.insert(arr[i]);
    }
    ans = max(ans, n - left);
    cout << ans;
	return 0;
}
