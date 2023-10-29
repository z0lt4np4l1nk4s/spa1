#include <iostream>
#include <vector>

using namespace std;

int* binary_search(vector<int>& V, int x)
{
    int l = 0, r = V.size() - 1;

    while(l <= r)
    {
        int m = l + (r - l) / 2;
        if(V[m] == x) return &V[m];

        if(V[m] > x) r = m - 1;
        else l = m + 1;
    } 

    return nullptr;
}

bool find(vector<int>& V, int x)
{
    int* res = binary_search(V, x);

    cout << "Element " << x << (res == nullptr ? " not" : "") << " found in the array" << endl;

    return res != nullptr;
}

int main()
{
    vector<int> V{1, 2, 3, 4, 6, 8, 13, 16, 19, 20};

    find(V, 6);
    find(V, 20);
    find(V, 5);
    find(V, 1);
    find(V, 19);
    find(V, 2);
    find(V, 17);

    return 0;
}