#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;

vector<vector<int> > adj;

struct Print_cycle_in_undirected_graph
{
    vector<bool> visited;
    vector<int> parent;
    int cycle_start = -1, cycle_end;
    Print_cycle_in_undirected_graph(int n)
    {
        visited.resize(n+1, false);
        parent.resize(n+1, -1);
        find_cycle(n);
    }
    void find_cycle(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(visited[i]) continue;
            if(dfs(i, parent[i])) break;
        }
        if(cycle_start == -1)
        {
            cout << "Graph is Acyclic\n";
        }
        else 
        {
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for(int i = cycle_end; i != cycle_start; i = parent[i])
            {
                cycle.push_back(i);
            }
            cycle.push_back(cycle_start);
            cout << cycle.size() << "\n";
            for(auto x : cycle) cout << x << " ";
            cout << "\n";
        }
    }
    bool dfs(int node, int par)
    {
        // cout << node << ' ' << par << "\n";
        visited[node] = true;
        for(auto child : adj[node])
        {
            if(child == par) continue;
            if(visited[child])
            {
                cycle_start = child;
                cycle_end = node;
                // cout << node << " " << child << " raj\n";
                return true;
            }
            parent[child] = node;
            if(dfs(child, node)) return true;
        }
        return false;
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

	int n, m; cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Print_cycle_in_undirected_graph solve(n);
	return 0;
}