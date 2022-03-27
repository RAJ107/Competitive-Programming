#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;


int main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL); 
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	string str; cin >> str;
    vector<int> cnt(26);
    for(auto x : str) cnt[x - 'A']++;
    char odd_occuring_character = '0';
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] & 1)
        {
            if(odd_occuring_character == '0') odd_occuring_character = (char)(i + 'A');
            else 
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    }
    string ans = "";
    for(int i = 0; i < 26; i++)
    {
        cnt[i] >>= 1;
        for(int j = 0; j < cnt[i]; j++) ans += (char)(i + 'A');
    }
    if(odd_occuring_character != '0') ans += odd_occuring_character;
    for(int i = 25; i >= 0; i--)
    {
        for(int j = 0; j < cnt[i]; j++) ans += (char)(i + 'A');
    }
    cout << ans;
	return 0;
}