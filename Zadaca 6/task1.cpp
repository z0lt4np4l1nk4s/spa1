#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "ACAATCC";
    string t = "AGCATGC";

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= t.size(); j++)
        {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else 
            {
                int m = INT_MAX;
                m = min(m, dp[i-1][j]);
                m = min(m, dp[i][j-1]);
                m = min(m, dp[i-1][j-1]);
                dp[i][j] = m + 1;
            }
        }
    }

    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= t.size(); j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}