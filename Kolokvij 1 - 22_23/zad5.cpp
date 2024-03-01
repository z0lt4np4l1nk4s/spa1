#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int closest(vector<int>& A)
{
    sort(A.begin(), A.end());

    int m = A[1] - A[0];
    for(int i = 2; i < A.size(); i++)
    {
        m = min(m, A[i] - A[i-1]);
    }

    return m;
}

int main()
{
    vector<int> A = { 4, 2, 5, 10 };
    cout << closest(A) << endl; // 1

    vector<int> B = { 1, 3, 5, 10, 1 };
    cout << closest(B) << endl; // 0

    vector<int> C = { 2000, 100, 1000, 10 };
    cout << closest(C) << endl; // 90
}