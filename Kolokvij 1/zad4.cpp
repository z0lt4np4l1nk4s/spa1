#include <iostream>
#include <vector>

using namespace std;

int missing(vector<int>& A, int k)
{
    vector<int> count(k+1);
    for(auto i: A)
    {
        count[i]++;
    }

    for(int i = 0; i < A.size(); i++)
    {
        if(count[i] == 0) return i;
    }

    //this should never happen
    return -1;
}

int main()
{
    vector<int> A = { 2, 2, 3, 0, 3 };
    cout << missing(A, 3) << endl; // 1

    vector<int> B = { 2, 1, 3, 0, 3 };
    cout << missing(B, 4) << endl; // 4

    vector<int> C = { 1, 2, 3, 4, 5, 6, 7 };
    cout << missing(C, 7) << endl; // 0
}