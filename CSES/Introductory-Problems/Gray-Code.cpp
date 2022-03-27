#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

void print(int x, int n)
{
    string bits = "";
    for(int i = 0; i < n; i++)
    {
        if(x & (1 << i)) bits += '1';
        else bits += '0';
    }
    reverse(bits.begin(), bits.end());
    cout << bits << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	int n; cin >> n;
    vector<bool> visited(1 << n, false);
    int cnt = 0, total = (1 << n), cur = 0;
    while(cnt < total)
    {
        visited[cur] = true;
        cnt ++;
        print(cur, n);
        for(int i = 0; i < n; i++)
        {
            if(!visited[cur ^ (1 << i)])
            {
                cur = (cur ^ (1 << i));
                break;
            }
        }
    }
	return 0;
}