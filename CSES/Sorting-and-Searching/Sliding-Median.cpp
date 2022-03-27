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
 
	int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    multiset<int> S1, S2;
    for(int i = 0; i < n; i++)
    {
        if(i >= k)
        {
            if(S1.find(arr[i-k]) != S1.end()) S1.erase(S1.find(arr[i-k]));
            else S2.erase(S2.find(arr[i-k]));
        }
        if(!S2.empty())
        {
            S1.insert(*S2.begin());
            S2.erase(S2.begin());
        }
        S1.insert(arr[i]);
        while(S1.size() > (k+1)/2)
        {
            S2.insert(*S1.rbegin());
            S1.erase(S1.find(*S1.rbegin()));
        }
        if(i >= k-1) cout << *S1.rbegin() << " ";
    }
	return 0;
}