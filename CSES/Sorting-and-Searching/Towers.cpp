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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> tower;
    for(int i = 0; i < n; i++)
    {
        auto it = upper_bound(tower.begin(), tower.end(), arr[i]);
        if(it == tower.end()) tower.push_back(arr[i]);
        else tower[it - tower.begin()] = arr[i];
    }
    cout << tower.size();
	return 0;
}