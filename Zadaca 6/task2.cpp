#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> A, B, C;
int dp[100000][4];

int getPoints(int i, int last)
{
    if(last == 1) return A[i];
    else if(last == 2) return B[i];
    return C[i];
}

int f(int i, int last)
{
    if(i == n) return 0;
    if(dp[i][last] != -1) return dp[i][last];
    int m = 0;
    for(int j = 1; j <= 3; j++)
    {
        if(j == last) continue;
        m = max(m, getPoints(i, j) + f(i+1, j));
    }
    return dp[i][last] = m;
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
    }
    cout << f(0, 0);
}