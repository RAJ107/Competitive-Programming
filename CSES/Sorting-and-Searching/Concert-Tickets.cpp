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
 
	int n, m; cin >> n >> m;
    multiset<int> S;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        S.insert(-x);
    }
    for(int i = 0; i < m; i++)
    {
        int req; cin >> req;
        auto it = S.lower_bound(-req);
        if(it == S.end()) cout << -1 << "\n";
        else 
        {
            cout << -(*it) << "\n";
            S.erase(it);
        }
    }
	return 0;
}