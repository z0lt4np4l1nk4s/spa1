#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> V)
{
    if(V.size() == 1) return V[0];
    if(V[0] > V[1]) return V[0];

    int l = 0, r = V.size() - 1;

    if(V[r-1] < V[r]) return V[r];

    while(l <= r)
    {
        int m = l + (r - l) / 2;
        if(V[m-1] < V[m] && V[m] > V[m+1]) return V[m];

        if(V[m-1] < V[m] && V[m] < V[m+1]) l = m;
        else r = m;
    } 

    // this should never happen
    return -1;
}

void printArray(vector<int> V)
{
    for(int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}

int find_max(vector<int> V)
{
    if(V.size() == 0)
    {
        cout << "Can't find max element in empty array!" << endl;
        return -1;
    }
    cout << "Array ";
    printArray(V);

    int max = binary_search(V);

    cout << "Maximum element is: " << max << endl << endl;

    return max;
}

int main()
{
    vector<int> V1 {1, 2, 3, 4, 6, 8, 7, 3, 0};
    find_max(V1);

    vector<int> V2 {9, 8, 7, 6, 5, 4, 3, 2, 1};
    find_max(V2);

    vector<int> V3 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    find_max(V3);

    vector<int> V4 {1, 10, 8, 7, 6, 5, 4, 3, 2, 1};
    find_max(V4);

    vector<int> V5 {1, 2, 3, 4, 5, 6, 7, 8, 15, 5};
    find_max(V5);

    vector<int> V6 {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 ,0};
    find_max(V6);

    return 0;
}