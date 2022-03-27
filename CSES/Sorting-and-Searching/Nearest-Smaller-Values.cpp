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
    vector<int> ans(n);
    stack<pair<int, int> > st;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        while(!st.empty() && st.top().first >= x) st.pop();
        if(st.empty()) ans[i] = 0;
        else ans[i] = st.top().second;
        st.push(make_pair(x, i+1));
    }
    for(auto x : ans) cout << x << " ";
	return 0;
}