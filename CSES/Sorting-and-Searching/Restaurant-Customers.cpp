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
    vector<pair<int, int> > events;
    for(int i = 0; i < n; i++)
    {
        int a, d; cin >> a >> d;
        events.push_back(make_pair(a, 1));
        events.push_back(make_pair(d, -1));
    }
    sort(events.begin(), events.end(), [](pair<int, int> A, pair<int, int> B){
        return A.first == B.first ? A.second < B.second : A.first < B.first;
    });
    int ans = 0, sum = 0;
    for(int i = 0; i < 2*n; i++)
    {
        sum += events[i].second;
        ans = max(ans, sum);
    }
    cout << ans;
	return 0;
}