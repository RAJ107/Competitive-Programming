#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
    ordered_set S;
    for(int i = 1; i <= n; i++) S.insert(i);
    int next = k%n;
    while(n--)
    {
        auto it = S.find_by_order(next);
        cout << *it << " ";
        S.erase(it);
        if(n) next = (next + k) % n;
    }
	return 0;
}