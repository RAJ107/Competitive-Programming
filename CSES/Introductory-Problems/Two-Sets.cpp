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
    if(n == 1)
    {
        cout << "NO\n";
        return 0;
    }
    long long int req = n*(n+1)/2;
    if(req & 1)
    {
        cout << "NO\n";
        return 0;
    }
    req >>= 1;
    long long int ptr1 = 1, ptr2 = 1, sum = 1;
    bool possible = false;
    while(ptr2 <= n)
    {
        ptr2 ++;
        sum += ptr2;
        while(sum > req)
        {
            sum -= ptr1;
            ptr1 ++;
        }
        if(sum == req)
        {
            possible = true;
            break;
        }
    }
    if(!possible)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << ptr2 - ptr1 + 1 << "\n";
    for(int i = ptr1; i <= ptr2; i++) cout << i << " "; cout << "\n";
    cout << n - ptr2 + ptr1 - 1 << "\n";
    for(int i = 1; i < ptr1; i++) cout << i << " ";
    for(int i = ptr2+1; i <= n; i++) cout << i << " ";
	return 0;
}