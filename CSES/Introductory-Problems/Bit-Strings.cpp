#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll power(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1) res = (res * x)%MOD;
        x = (x * x)%MOD;
        y >>= 1;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL); 
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	ll n; cin >> n;
    cout << power(2, n);
	return 0;
}