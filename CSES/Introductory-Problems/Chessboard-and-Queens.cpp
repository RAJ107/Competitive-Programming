#include <bits/stdc++.h>
// #include <unordered_set>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int solve(vector<vector<bool> > board, int row, int queen)
{
    if(row == 7)
    {
        if(queen > 1) return 0;
        int res = 0;
        for(int i = 0; i < 8; i++)
        {
            if(board[row][i]) res ++;
        }
        return res;
    }
    int ans = 0;
    for(int i = row; i < 8; i++)
    {
        vector<vector<bool> > temp = board;
        for(int j = 0; j < 8; j++)
        {
            if(board[row][j])
            {
                board[row][j] = false;
                for(int dx = -7; dx < 8; dx ++)
                {
                    for(int dy = -7; dy < 8; dy++)
                    {
                        if(abs(dx) != abs(dy)) continue;
                        int new_row = row + dy, new_col = j + dx;
                        if(new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8)
                        board[new_row][new_col] = false;
                    }
                }
                ans += solve(board, row+1, queen - 1);
                board = temp;
            }
        }
    }
    return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
 
	vector<vector<bool> > board(8, vector<bool> (8, true));
    for(int i = 0; i < 8; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < 8; j++)
        {
            if(str[j] == '*') board[i][j] = false;
        }
    }
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++) cout << board[i][j] << " "; 
        cout << '\n';
    }
    //cout << solve(board, 0, 8);
	return 0;
}