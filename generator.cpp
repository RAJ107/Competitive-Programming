#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f(i, a, n) for (int i = a; i < n; i++)
#define f1(i, a, n) for (int i = n; i >= a; i--)
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vbl vector<bool>
#define upb upper_bound
#define lwb lower_bound
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define umap unordered_map
#define uset unordered_set
#define gcd __gcd
#define MOD 998244353
#define INF INT_MAX
using namespace std;

ll r(ll a, ll b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
    //freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	srand(atoi(argv[1]));
    ll t = r(1, 200);
    cout << t << "\n";
    while(t--)
    {
        ll n = r(1, 1000);
        string str = "";
        for(int i = 0; i < n; i++)
        {
            ll x = r(0, 25);
            str += (char)(x + 'a');
        }
        cout << str << "\n";
    }
   // puts("\n");
    return 0;
}
