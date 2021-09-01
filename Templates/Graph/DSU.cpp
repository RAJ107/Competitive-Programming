#include <bits/stdc++.h>
#define ll long long
const ll MOD = (1e9+7);
using namespace std;

struct DSU {
    vector<int> par, siz;
    DSU(int n) : par(n), siz(n, 1) {iota(par.begin(), par.end(), 0);}
    int parent(int x) {
        while (x != par[x]) x = par[x];
        return x;
    }
    bool same(int x, int y) { return parent(x) == parent(y); }
    void merge(int x, int y) {
        x = parent(x);
        y = parent(y);
        if(siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return;
    }
    int size(int x) {return siz[parent(x)];}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // DSU dsu(n);
    return 0;
}