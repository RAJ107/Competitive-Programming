#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;


int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL); 
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	ll n; cin >> n;
    ll ans = 0;
    while(n)
    {
        n /= 5;
        ans += n;
    }
    cout << ans;
	return 0;
}