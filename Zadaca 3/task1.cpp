#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& V, int start, int end)
{
    int middle = start + (end - start) / 2;
    int pivot = V[middle];

    //setting the pivot to the first place
    swap(V[middle], V[start]);

    int index = start;

    for(int j = index + 1; j <= end; j++)
    {
        if(V[j] < pivot)
        {
            index++;
            swap(V[index], V[j]);
        }
    }

    //finally placing the pivot somewhere "in the middle"
    swap(V[start], V[index]);

    return index;
}

void quickSortHelp(vector<int>& V, int start, int end)
{
    if(start < end)
    {
        int pivotIndex = partition(V, start, end);
        quickSortHelp(V, start, pivotIndex - 1);
        quickSortHelp(V, pivotIndex + 1, end);
    }
}

void quickSort(vector<int>& V)
{
    if(V.size() <= 1) return;
    quickSortHelp(V, 0, V.size() - 1);
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
    vector<int> V{1, 17, 7, 22, 2, 14, 9, 8, 11, 1, -5, 10, -12, -7, 8, 9, 28};

    printArray(V);
    quickSort(V);
    printArray(V);

    cout << endl;

    vector<int> V1{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printArray(V1);
    quickSort(V1);
    printArray(V1);

    cout << endl;

    vector<int> V2{2, 1, 3};

    printArray(V2);
    quickSort(V2);
    printArray(V2);

    cout << endl;

    //Quick sort is a varying algorithm. In the worst-case the complexity is O(n^2)
    //whilst the average and base case scenario is O(n log(n)). The complexity depends on the input.

    //Since the implementation is in place, the space complexity is always O(n)

    return 0;
}