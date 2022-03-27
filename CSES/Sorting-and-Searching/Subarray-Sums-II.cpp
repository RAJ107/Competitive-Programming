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
    map<int, int> M;
    int ans = 0, sum = 0;
    M[0] = 1;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        sum += num;
        ans += M[sum - x];
        M[sum] ++;
    }
    cout << ans;
	return 0;
}