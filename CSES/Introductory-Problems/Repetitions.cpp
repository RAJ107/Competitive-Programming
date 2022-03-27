#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL); 
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	string str; cin >> str;
    int ans = 1, cur_len = 1;
    for(int i = 1; i < str.size(); i++)
    {
        if(str[i] == str[i-1]) cur_len ++;
        else 
        {
            ans = max(ans, cur_len);
            cur_len = 1;
        }
    }
    ans = max(ans, cur_len);
    cout << ans;
	return 0;
}