#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

class customer{
    public:
    int time, type, id;
};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	int n; cin >> n;
    customer cust[2*n];
    set<int> S;
    for(int i = 0; i < n; i++)
    {
        int a, d; cin >> a >> d;
        cust[2*i] = {a, 1, i+1};
        cust[2*i+1] = {d, -1, i+1};
        S.insert(i+1);
    }
    sort(cust, cust + 2*n, [](customer A, customer B){
        return A.time == B.time ? A.type > B.type : A.time < B.time;
    });
    vector<int> ans(n+1);
    for(int i = 0; i < 2*n; i++)
    {
        if(cust[i].type == 1)
        {
            ans[cust[i].id] = *S.begin();
            S.erase(S.begin());
        }
        else
        {
            S.insert(ans[cust[i].id]);
        }
    }
    int rooms = 0;
    for(int i = 0; i <= n; i++) rooms = max(rooms, ans[i]);
    cout << rooms << "\n";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}