#include <iostream>
#include <vector>

using namespace std;

bool canSplit(const vector<int>& V, int k, int maxSum)
{
    // calculating the number of subarrays we can make such 
    // that their sum is less than the given maximum sum
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
    //looking for the maximum element in the array for the lower limit
    int start = V[0];
    //looking for the sum of all elements in the array for the upper limit
    int end = V[0];
    for(int i = 1; i < V.size(); i++)
    {
        start = max(start, V[i]);
        end += V[i];
    }

    while(start < end)
    {
        int middle = start + (end - start) / 2;
        if(canSplit(V, k, middle)) 
        {
            // if the array can be split into k or less pieces, such that all the sums of 
            // subarrays are less than the current minimum maximum sum (middle)
            // then we have a new minimum maximum sum,
            // so we change the upper limit
            end = middle;
        }
        //otherwise we change the lower limit
        else start = middle + 1;
    }

    return start;
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