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
    vector<pair<int, pair<int, int> > > arr(n);
    for(int i = 0; i < n; i++) {cin >> arr[i].first >> arr[i].second.first; arr[i].second.second = i;}
    sort(arr.begin(), arr.end(), [](pair<int, pair<int,int> > A, pair<int, pair<int,int> > B){
        return A.first == B.first ? A.second.first > B.second.first : A.first < B.first;
    });
    vector<int> ans1(n), ans2(n);
    deque<pair<int, int> > dq;
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        while(!dq.empty() && dq.back().first >= arr[i].second.first)
        {
            ans1[dq.back().second] = 1;
            dq.pop_back();
        }
        if(arr[i].second.first <= mx) ans2[arr[i].second.second] = 1;
        dq.push_back(arr[i].second);
        mx = max(mx, arr[i].second.first);
    }
    for(auto x : ans1) cout << x << " "; cout << "\n";
    for(auto x : ans2) cout << x << " "; cout << "\n";
	return 0;
}