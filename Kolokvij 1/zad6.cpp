#include <iostream>
#include <vector>

using namespace std;

int subarray_sum(vector<int>& A, int x)
{
    vector<int> sums;
    sums.push_back(A[0]);

    for(int i = 1; i < A.size(); i++)
    {
        sums.push_back(sums[i-1] + A[i]);
    }

    int l = -1, r = 0;
    int c = 0;

    while(r < A.size())
    {
        int res = sums[r] - (l == -1 ? 0 : sums[l]);

        if(res == x)
        {
            l++;
            r++;
            c++;
        }
        else if (res > x) l++;
        else r++;
    }

    return c;
}


int main()
{
    vector<int> A = { 2, 4, 1, 2, 7 };
    cout << subarray_sum(A, 7) << endl; // 3

    vector<int> B = { 1, 1, 1, 1, 1, 1, 1, 1, 3, 4 };
    cout << subarray_sum(B, 7) << endl; // 4

    vector<int> C = { 1, 2, 3, 4, 5, 6, 7 };
    cout << subarray_sum(C, 8) << endl; // 0

    vector<int> D = { 2, 2, 2, 4, 2, 2 };
    cout << subarray_sum(D, 4) << endl; // 4
}