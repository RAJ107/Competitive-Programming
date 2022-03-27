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
    vector<pair<int, int> > arr(n);
    for(int i = 0; i < n; i++) {cin >> arr[i].first; arr[i].second = i+1;}
    sort(arr.begin(), arr.end());
    int val1 = -1, val2, val3;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int idx = lower_bound(arr.begin() + j + 1, arr.end(), make_pair(x - arr[i].first - arr[j].first, 0LL)) - arr.begin();
            if(idx < n && arr[idx].first == (x - arr[i].first - arr[j].first))
            {
                cout << arr[i].second << " " << arr[j].second << " " << arr[idx].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
	return 0;
}