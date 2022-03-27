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
 
	ll t; cin >> t;
    while(t--)
    {
        ll n, m; cin >> n >> m;
        ll no_of_1 = 2*n - m, no_of_2 = 2*m - n;
        if(no_of_1 < 0 || no_of_1 % 3 > 0 || no_of_2 < 0 || no_of_2 % 3 > 0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
	return 0;
}