#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	int n, x; cin >> n >> x;
    map<int, vector<pair<int, int> > > umap;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++) umap[arr[i] + arr[j]].push_back(make_pair(i, j));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int req = x - arr[i] - arr[j];
            if(umap.find(req) != umap.end()){
            for(auto temp : umap[req])
            {
                    if(temp.first != i && temp.first != j && temp.second != i && temp.second != j)
                    {
                        cout << i+1 << " " << j+1 << " " << temp.first+1 << " " << temp.second+1;
                        return 0;
                    }
            }
            }
        }
    }
    cout << "IMPOSSIBLE";
	return 0;
}