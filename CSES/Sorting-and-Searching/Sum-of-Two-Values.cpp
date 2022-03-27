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
 
	int n, req; cin >> n >> req;
    vector<pair<int, int> > arr(n);
    for(int i = 0; i < n; i++) {cin >> arr[i].first; arr[i].second = i+1;}
    sort(arr.begin(), arr.end());
    int l = 0, r = n-1;
    while(l < r)
    {
        while(arr[l].first + arr[r].first > req && l < r) r--;
        if(arr[l].first + arr[r].first == req) break;
        l++;
    }
    if(l >= r) cout << "IMPOSSIBLE";
    else cout << arr[l].second << " " << arr[r].second;
	return 0;
}