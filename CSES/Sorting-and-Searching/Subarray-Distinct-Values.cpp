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
    for(int i = 0; i < n; i++) cin >> arr[i];
    int left = 0, ans = 0;;
    map<int, int> mmp;
    for(int i = 0; i < n; i++)
    {
        mmp[arr[i]] ++;
        while(mmp.size() > k)
        {
            mmp[arr[left]] --;
            if(mmp[arr[left]] == 0) mmp.erase(arr[left]);
            left ++;
        }
        ans += (i - left + 1);
    }
    cout << ans;
	return 0;
}