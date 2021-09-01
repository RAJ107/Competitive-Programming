#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;

bool is_vowel(char ch)
{
    string str = "AEIOU";
    for(auto s : str)
    {
        if(s == ch) return true;
    }
    return false;
}

void solve()
{
    string str; cin >> str;
    ll ans = 2 * str.size();
    for(auto ch = 'A'; ch <= 'Z'; ch++)
    {
        ll res = 0;
        for(auto s : str)
        {
            if(ch == s) continue;
            if((is_vowel(ch) & is_vowel(s)) || ((!is_vowel(ch) & (!is_vowel(s))))) res += 2;
            else res ++;
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    for(int test = 1; test <= t; test ++)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
	return 0;
}