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
 
    int t; cin >> t;
    while(t--)
    {
        long long int row, col; cin >> row >> col;
        if(row >= col)
        {
            if(row & 1) cout << (row - 1) * (row - 1) + col << "\n";
            else cout << row * row - (col - 1) << "\n";
        }
        else 
        {
            if(col & 1) cout << col * col - (row - 1) << "\n";
            else cout << (col - 1) * (col - 1) + row << "\n";
        }
    }
	return 0;
}