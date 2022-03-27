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
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    multiset<int> left, right;
    int lsum = 0, rsum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i > k)
        {
            if(left.find(arr[i-k]) != left.end()) {left.erase(left.find(arr[i-k])); lsum -= arr[i-k];}
            else {right.erase(right.find(arr[i-k])); rsum -= arr[i-k];}
        }
        left.insert(arr[i]);
        lsum += arr[i];
        if(!right.empty())
        {
            left.insert(*right.begin());
            lsum += (*right.begin());
            rsum -= (*right.begin());
            right.erase(right.begin());
        }
        while(left.size() > (k+1)/2)
        {
            right.insert(*left.rbegin());
            rsum += (*left.rbegin());
            lsum -= (*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
        // if(i > k) cout << lsum << " " << (*left.rbegin())*(left.size()) << ' ' << rsum << ' ' << (*left.rbegin()) * (right.size()) << "\n";
        if(i >= k) cout << rsum - lsum + (*left.rbegin()) * (k & 1) << " ";
    }
	return 0;
}