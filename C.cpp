#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    while(t--)
    {
        ll a, b; cin >> a >> b;
        ll n = a+b;
        ll na = n/2, nb = n - na;
        set<ll> ans;
        for(ll i = 0; i <= a; i++)
        {
            if(nb >= (a - i) && na >= i) ans.insert(a - 2*i + na);
        }
        swap(na, nb);
        for(ll i = 0; i <= a; i++)
        {
            if(nb >= (a - i) && na >= i) ans.insert(a - 2*i + na);
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " "; cout << "\n";
    }
	return 0;
}