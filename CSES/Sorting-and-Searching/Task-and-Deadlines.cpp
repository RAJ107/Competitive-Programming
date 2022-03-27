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
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int x; cin >> x;
        sum += x;
    }
    sort(arr.begin(), arr.end());
    sum -= arr[0];
    for(int i = 1; i < n; i++)
    {
        arr[i] += arr[i-1];
        sum -= arr[i];
    }
    cout << sum;
	return 0;
}