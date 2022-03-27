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
 
    long long int n; cin >> n;
    for(long long int i = 1; i <= n; i++)
    {
        if(i == 1) 
        {
            cout << 0 << "\n";
            continue;
        }
        if(i == 2)
        {
            cout << 6 << "\n";
            continue;
        }
        if(i == 3)
        {
            cout << 28 << "\n";
            continue;
        }
        long long int sum = 2*4 + 3*8 + 4*4 + 4*(4*i - 16) + 6*(4*i - 16) + 8*(i-4)*(i-4);
        cout << (i*i*(i*i - 1))/2 - sum/2 << '\n';
    }
	return 0;
}