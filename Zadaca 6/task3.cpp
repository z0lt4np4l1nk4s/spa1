#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

string s, t;
int dp[3001][3001];

int f (int l, int r)
{
    if(l == s.size() || r == t.size()) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    
    int res = 0;
    
    if(s[l] == t[r]) return dp[l][r] = 1 + f(l+1, r+1);

    return dp[l][r] = max(f(l+1, r), f(l, r+1));
}

int main()
{
    cin >> s >> t;
    memset(dp, -1, sizeof dp);

    f(0, 0);

    int i = 0, j = 0;
    while(i < s.size() && j < t.size())
    {
        if(s[i] == t[j] && dp[i][j] == f(i+1, j+1) + 1) 
        {
            cout << s[i];
            i++; j++;
        }
        else if (dp[i][j] == f(i+1, j)) i++;
        else j++;
    }
}