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
    int mx = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    cout << max(2*mx, sum);
	return 0;
}