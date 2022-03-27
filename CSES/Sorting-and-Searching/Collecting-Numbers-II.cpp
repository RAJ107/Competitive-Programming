#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int n, q;
vector<int> pos, arr;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    
    cin >> n >> q;
	pos.resize(n+2);
    arr.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    pos[n+1] = n+1;
    int res = 1;
    for(int i = 2; i <= n; i++) res += (pos[i-1] > pos[i]);
    while(q--)
    {
        int p1, p2; cin >> p1 >> p2;
        res -= ((pos[arr[p1] - 1] > pos[arr[p1]]) + (pos[arr[p1]] > pos[arr[p1] + 1]));
        res -= ((pos[arr[p2] - 1] > pos[arr[p2]]) + (pos[arr[p2]] > pos[arr[p2] + 1]));
        swap(pos[arr[p1]], pos[arr[p2]]);
        swap(arr[p1], arr[p2]);
        res += ((pos[arr[p1] - 1] > pos[arr[p1]]) + (pos[arr[p1]] > pos[arr[p1] + 1]));
        res += ((pos[arr[p2] - 1] > pos[arr[p2]]) + (pos[arr[p2]] > pos[arr[p2] + 1]));
        if(arr[p1] == arr[p2] - 1)
        {
            if(pos[arr[p1]] > pos[arr[p2]]) res --;
            else res ++;
        }
        if(arr[p2] == arr[p1] - 1)
        {
            if(pos[arr[p2]] > pos[arr[p1]]) res --;
            else res ++;
        }
        cout << res << "\n";
    }
	return 0;
}