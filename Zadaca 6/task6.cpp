#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100001];
int inf = 1e9;

int f(int n)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int minimum = inf;
    int number = n;
    while(number != 0)
    {
        int k = number % 10;
        number /= 10;
        if(k == 0) continue;
        minimum = min(minimum, 1 + f(n - k));
    }

    return dp[n] = minimum;
}

int main()
{
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    cout << f(n) << endl;
}