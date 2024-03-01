#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int mod = 1e9 + 7;
int dp[1001][1001];

vector<string> grid;

int f(int x, int y)
{
    if(x >= n || y >= n) return 0;
    if(grid[x][y] == '*') return 0;

    if(x+1 == n && y+1 == n) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    return dp[x][y] = (f(x+1, y) + f(x, y+1)) % mod;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        grid.push_back(s);
    }

    memset(dp, -1, sizeof dp);

    cout << f(0, 0) << endl;
}