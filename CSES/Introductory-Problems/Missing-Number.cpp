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
 
	long long int n, xr = 0;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int num; cin >> num;
        xr ^= num;
    }
	for(int i = 1; i <= n; i++) xr ^= i;
    cout << xr;
	return 0;
}