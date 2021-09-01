#include <bits/stdc++.h>
#define ll long long
#define ld long double
const ll MOD = 1e9 + 7;
using namespace std;

ll n, m, k;
vector<vector<pair<ll, ll> > > adj;

void Dijkstra()
{
	vector<priority_queue<ll> > dist(n+1);
	priority_queue<pair<ll, ll> > pq;
	dist[1].push(0);
	for(int i = 2; i <= n; i++) dist[i].push(1e16);
	pq.push(make_pair(0, 1));
	while(!pq.empty())
	{
		ll node = pq.top().second, d = -pq.top().first;
		pq.pop();
		if(dist[node].top() < d) continue;
		for(auto x : adj[node])
		{
			ll child = x.first, w = x.second;
			dist[child].push(d+w);
			if(dist[child].size() > k) dist[child].pop();
			pq.push(make_pair(-d-w, child));
		}
	}
	// for(int i = 1; i <= n; i++)
	// {
	// 	cout << i << "  -->\n";
	// 	while(!dist[i].empty())
	// 	{
	// 		cout << dist[i].top() << " ";
	// 		dist[i].pop();
	// 	}
	// 	cout << "\n";
	// }
	vector<ll> ans;
	while(!dist[n].empty())
	{
		ans.push_back(dist[n].top());
		dist[n].pop();
	}
	reverse(ans.begin(), ans.end());
	for(auto x : ans) cout << x << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
	adj.resize(n+1);
	for(int i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		// adj[v].push_back(make_pair(u, w));
	}
	Dijkstra();
	return 0;
}