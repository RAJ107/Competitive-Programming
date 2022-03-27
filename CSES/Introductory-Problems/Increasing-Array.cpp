#include <bits/stdc++.h>
using namespace std;


int main()
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
    long long int ans = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1]) 
        {
            ans += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << ans;
	return 0;
}