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
    for(int i = 1; i <= n; i++) S.insert(i);
    int cnt = 1;
    auto it = S.begin();
    vector<int> store;
    while(!S.empty())
    {
        ++it;
        if(it == S.end())
        {
            for(auto x : store) S.erase(x);
            store.clear();
            it = S.begin();
        }
        cnt ++;
        if(cnt % 2 == 0)
        {
            cout << *it << " ";
            store.push_back(*it);
        }
    }
	return 0;
}