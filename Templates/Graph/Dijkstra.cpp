/*
---> No negative weight should be present in the graph
---> Time Complexity O(V + ElogE) 
{because each edge is processes once in the algorithm as there is no negative edge in the graph}
*/

#include <bits/stdc++.h>
#define ll long long
const ll MOD = (1e9 + 7);
using namespace std;

class Dijkstra
{
    public :
    vector<ll> distance, parent;
    vector<bool> processed;
    priority_queue<pair<ll, ll> > pq;
    Dijkstra(vector<vector<pair<ll, ll> > >& adj, ll source)
    {
        ll n = adj.size();
        parent.resize(n, -1);
        distance.resize(n, 1e12);
        processed.resize(n, false);
        distance[source] = 0;
        pq.push(make_pair(0LL, source));
        while(!pq.empty())
        {
            ll node = pq.top().second;
            pq.pop();
            if(processed[node]) continue;
            processed[node] = true;
            for(auto child : adj[node])
            {
                ll child_node = child.first, wt = child.second;
                if(distance[node] + wt < distance[child_node])
                {
                    distance[child_node] = distance[node] + wt;
                    pq.push(make_pair(-distance[child_node], child_node));
                    parent[child_node] = node;
                    // cout << node << ' ' << child_node << " " << distance[child_node] << "\n";
                }
            }
        }
    }
    void print_path(ll destination)
    {
        vector<ll> path;
        ll curr_node = destination;
        while(curr_node != -1)
        {
            path.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        reverse(path.begin(), path.end());
        for(auto x : path) cout << x << ' ';
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
    vector<vector<pair<ll, ll> > > adj(n+1);
    for(int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    ll source = 1;
    Dijkstra dij(adj, source);
    for(int i = 1; i <= n; i++) cout << dij.distance[i] << " "; cout << "\n";
    for(int i = 1; i <= n; i++) dij.print_path(i);
	return 0;
}