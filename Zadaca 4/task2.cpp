#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_SIZE = 200000;

void countingSort(vector<int>& V)
{
    vector<int> countVector(MAX_SIZE);

    for(auto i: V)
    {
        if(i >= MAX_SIZE) throw runtime_error("Array can't contain items that are greater than " + to_string(MAX_SIZE));
        countVector[i]++;
    }

    int k = 0;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < countVector[i]; j++)
        {
            V[k++] = i;
        }
        
    }
}

void printArray(const vector<int>& V)
{
    for(auto i: V)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> V {10, 15, 100, 4, 7, 12, 76, 45, 89, 94, 34, 67, 15, 8, 4};
    countingSort(V);
    printArray(V);

    return 0;
}