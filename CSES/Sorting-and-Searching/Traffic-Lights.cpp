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
 
	int x, n; cin >> x >> n;
    set<int> pos;
    multiset<int> len;
    pos.insert(0);
    pos.insert(x);
    len.insert(x);
    int ans = x;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        auto it = pos.lower_bound(p);
        int right = *it;
        int left = *(--it);
        int diff = right - left;
        pos.insert(p);
        auto it2 = len.find(diff);
        len.erase(it2);
        len.insert(right - p);
        len.insert(p - left);
        cout << *len.rbegin() << " ";
    }
	return 0;
}