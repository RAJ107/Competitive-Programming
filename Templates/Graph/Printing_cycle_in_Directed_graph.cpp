#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;
vector<ll> topo;

bool dfs(int v) { // passing vertex
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if(dfs(u)) return true;
        }
        else if(color[u] == 1)
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    topo.push_back(v);
    return false;
}

void find_cycle() {
    color.assign(n+1, 0);
    parent.assign(n+1, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if(cycle_start == -1)
    {
        cout << "Acyclic Graph : Topological sort is valid:-\n";
        reverse(topo.begin(), topo.end());
        for(auto x : topo) cout << x << " ";
        cout << "\n";
    }
    else 
    {
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for(int v = cycle_end; v != cycle_start; v = parent[v]) cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << "Cycle Found!!\n";
        for(auto x : cycle) cout << x << " ";
        cout << "\n";
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

	int m; cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    find_cycle();
	return 0;
}