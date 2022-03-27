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
 
	int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int temp = 9, digit = 1;
        while(n > temp)
        {
            n -= temp;
            temp *= 10;
            digit ++;
        }
        int num = temp/9 + n/digit - 1;
        cout << num << ' ' << temp << ' ' << digit << "\n";
        for(int i = 0; i < (digit - n%digit)%digit; i++) num /= 10;
        cout << num%10 << "\n";
    }
	return 0;
}