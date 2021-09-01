#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vbl vector<bool>
#define upb upper_bound
#define lwb lower_bound
#define sz(x) ((int) x.size())
#define gcd __gcd
const ll MOD = 1e9+7;
#define INF 2e18
using namespace std;

ll n; 

struct Matrix
{
    vector<vll> a;
    Matrix() {
		a.resize(n, vll(n, INF));
	}
    Matrix operator *(const Matrix& other)
    {
        Matrix product;
        //vector<vll> tmp(65, vll(65));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    product.a[i][k] = min(product.a[i][k], a[i][j] + other.a[j][k]);
                    
                }
                // tmp[i][j] %= MOD;
            }
        }
        // for(int i = 0; i < 65; i++)
        // {
        //     for(int j = 0; j < 65; j++)
        //     {
        //         product.a[i][j] = tmp[i][j]%MOD;
        //     }
        // }
        return product;
    }
};

Matrix exp_power(Matrix a,ll k)
{
    Matrix product;
    for(int i = 0; i < n; i++) product.a[i][i] = 0;
    while(k)
    {
        if(k&1) product = product * a;
        a = a*a;
        k >>= 1;
    }
    return product;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll m, k; cin >> n >> m >> k;
    Matrix single;
    for(int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        single.a[u-1][v-1] = w;
    }
    Matrix total = exp_power(single, k);
    ll ans = INF;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) ans = min(ans, total.a[i][j]);
    }
    if(ans > INF/2) cout << "IMPOSSIBLE";
    else cout << ans;
    return 0;
}