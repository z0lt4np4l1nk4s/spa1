#include <iostream>
#include <vector>

using namespace std;

bool canSplit(const vector<int>& V, int k, int maxSum)
{
    int subArrayCount = 1;
    int currentSum = 0;

    for(int i = 0; i < V.size(); i++)
    {
        if(currentSum + V[i] > maxSum)
        {
            subArrayCount++;
            currentSum = 0;
        }
        currentSum += V[i];
    }

    return subArrayCount <= k;
}

int find_sum(const vector<int>& V, int k)
{
    int l = V[0];
    int r = V[0];
    for(int i = 1; i < V.size(); i++)
    {
        l = max(l, V[i]);
        r += V[i];
    }

    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(canSplit(V, k, mid)) 
        {
            r = mid;
        }
        else l = mid + 1;
    }

    return l;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> V(n);

    for(int i = 0; i < n; i++) cin >> V[i];

    cout << find_sum(V, k) << endl;

    return 0;
}