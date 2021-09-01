#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;

ll n, m;
vector<vector<ll> > adj;

void Dijkstra()
{
    vector<ll> dist(n+1, -1e9), parent(n+1, -1);
    vector<bool> processed(n+1, false);
    priority_queue<pair<ll, ll> > pq;
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        ll node = pq.top().second;
        pq.pop();
        // if(processed[node]) continue;
        processed[node] = true;
        // cout << node << ' ' << dist[node] << "\n";
        for(auto child : adj[node])
        {
            if(dist[child] < 1 + dist[node])
            {
                dist[child] = 1 + dist[node];
                pq.push(make_pair(dist[child], child));
                parent[child] = node;
            }
        }
    }
    if(dist[n] == -1e9) cout << "IMPOSSIBLE";
    else 
    {
        vector<ll> cycle;
        for(int v = n; v != 1; v = parent[v]) cycle.push_back(v);
        cycle.push_back(1);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for(auto x : cycle) cout << x << " ";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++) 
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    Dijkstra();
	return 0;
}