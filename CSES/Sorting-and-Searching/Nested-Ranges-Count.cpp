#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int n, l, r;
vector<int> fen;

class range
{
    public :
    int idx, start, end;
};

void update(int idx)
{
    while(idx <= 2*n+4)
    {
        fen[idx] ++;
        idx += (idx & (-idx));
    }
}

int query(int idx)
{
    int res = 0;
    while(idx)
    {
        res += fen[idx];
        idx -= (idx & (-idx));
    }
    return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	cin >> n;
    vector<int> pos(2*n);
    vector<range> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i].start >> arr[i].end;
        arr[i].idx = i;
        pos[2*i-2] = arr[i].start;
        pos[2*i-1] = arr[i].end;
    }
    sort(pos.begin(), pos.end());
    for(int i = 1; i <= n; i++)
    {
        arr[i].start = (lower_bound(pos.begin(), pos.end(), arr[i].start) - pos.begin()) + 1;
        arr[i].end = (lower_bound(pos.begin(), pos.end(), arr[i].end) - pos.begin()) + 1;
    }
    vector<int> ans1(n+1), ans2(n+1);
    fen = vector<int> (2*n+5);
    sort(arr.begin(), arr.end(), [](range A, range B){
        return A.start == B.start ? A.end > B.end : A.start < B.start;
    });
    // for(int i = 1; i <= n; i++) cout << arr[i].first << " " << arr[i].second << "\n";
    for(int i = n; i > 0; i--)
    {
        // for(int j = 0; j <= 8; j++) cout << fen[j] << " "; cout << "\n";
        ans1[arr[i].idx] = query(arr[i].end);
        update(arr[i].end);
        // cout << arr[i].idx << " " << ans1[arr[i].idx] << "\n";
    }
    fen = vector<int> (2*n+5);
    for(int i = 1; i <= n; i++)
    {
        ans2[arr[i].idx] = i - query(arr[i].end - 1) - 1;
        update(arr[i].end);
    }
    for(int i = 1; i <= n; i++) cout << ans1[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << ans2[i] << " ";
	return 0;
}