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
    vector<int> pos(n+1);
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        pos[x] = i+1;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++) ans += (pos[i-1] > pos[i]);
    cout << ans;
	return 0;
}