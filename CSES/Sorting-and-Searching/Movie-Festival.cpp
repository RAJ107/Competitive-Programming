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
    vector<pair<int, int> > slot;
    for(int i = 0; i < n; i++)
    {
        int start, end; cin >> start >> end;
        slot.push_back(make_pair(end, start));
    }
    sort(slot.begin(), slot.end());
    int ans = 1, end = slot[0].first;
    for(int i = 1; i < n; i++)
    {
        if(slot[i].second >= end)
        {
            ans ++;
            end = slot[i].first;
        }
    }
    cout << ans;
	return 0;
}