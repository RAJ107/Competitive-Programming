#include <bits/stdc++.h>
// #include <unordered_set>
using namespace std;
#define int long long
const int MOD = 1e9+7;

set<string> permutations;

void find_permutation(string str, int l, int r)
{
    if(l == r)
    {
        permutations.insert(str);
        return;
    }
    for(int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        find_permutation(str, l+1, r);
        swap(str[l], str[i]);
    }
    return;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	string str; cin >> str;
    find_permutation(str, 0, str.size()-1);
    cout << permutations.size() << "\n";
    for(auto p : permutations) cout << p << "\n";
	return 0;
}