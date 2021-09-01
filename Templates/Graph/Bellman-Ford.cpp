/*
---> Works for Directed graph (with no negative length cycle)
---> Can work for Undirected graph (if there is no negative edge)
---> Can detect if the graph contains a negative length cycle
---> Time Comlexity O(nm)
*/


#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;

struct Bellman_Ford
{
    vector<ll> dist, parent;
    Bellman_Ford(vector<tuple<ll, ll, ll> >& edges, ll source, ll n)
    {
        dist.resize(n+1, 1e15);
        parent.resize(n+1, -1);
        dist[source] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(auto e : edges)
            {
                ll u, v, w;
                tie(u, v, w) = e;
                if(dist[v] > dist[u] + w)
                {
                    if(i == n)
                    {
                        cout << "Negative Edge Cycle\n";
                    }
                    parent[v] = u;
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    void print_path(ll destination)
    {
        vector<ll> path;
        for(int i = destination; i != -1; i = parent[i]) 
        {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for(auto x : path) cout << x << " ";
        cout << "\n";
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ll n, m; cin >> n >> m;
    vector<tuple<ll, ll, ll> > edges(m);
    for(int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        edges[i] = tie(u, v, w);
    }
    ll source = 1;
    Bellman_Ford BeFo(edges, source, n);
    for(int i = 1; i <= n; i++) cout << BeFo.dist[i] << " "; cout << "\n";
    for(int i = 1; i <= n; i++) BeFo.print_path(i);
	return 0;
}