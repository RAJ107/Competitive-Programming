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
 
	long long int n;
    cin >> n;

    while(n > 1)
    {
        cout << n << " ";
        if(n & 1) n = 3LL * n + 1;
        else n >>= 1;
    }
    cout << 1;
	return 0;
}