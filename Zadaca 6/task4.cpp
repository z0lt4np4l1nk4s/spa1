#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> A;
int dp[100001];

int f(int k)
{
    if(k == 0) return 0;
    if(k < 0) return 1;
    if(dp[k] != -1) return dp[k];

    bool res = false;
    for(int j = 0; j < n; j++)
    {
        res = res || (f(k-A[j]) == 0 ? true : false);
    }

    return dp[k] = res;
}

int main()
{
    int k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        A.push_back(a);
    }

    memset(dp, -1, sizeof dp);

    bool res = f(k);

    if(res) cout << "Marica" << endl;
    else cout << "Ivica" << endl;
}