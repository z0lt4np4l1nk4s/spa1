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

    //moving all the items that are smaller than the pivot to the left
    //and the items that are greater or equal than the pivot to the right
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

bool checkIfSorted(vector<int>& V)
{
    for(int i = 1; i < V.size(); i++)
    {
        if(V[i - 1] > V[i]) return false;
    }

    return true;
}

void sortArray(vector<int>& V)
{
    cout << "Initial array: ";
    printArray(V);

    quickSort(V);
    
    cout << "Sorted array: ";
    printArray(V);

    bool isSorted = checkIfSorted(V);
    cout << "The array is " << (isSorted ? "" : "not ") << "sorted!" << endl << endl;
}

int main()
{
    vector<int> V{1, 17, 7, 22, 2, 14, 9, 8, 11, 1, -5, 10, -12, -7, 8, 9, 28};
    sortArray(V);

    vector<int> V1{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sortArray(V1);

    vector<int> V2{2, 1, 3};
    sortArray(V2);

    vector<int> V3{4};
    sortArray(V3);

    vector<int> V4{1, 2, 3, 4, 5, 6};
    sortArray(V4);

    //Quick sort is a varying algorithm. In the worst-case the complexity is O(n^2)
    //whilst the average and base case scenario is O(n log(n)). The complexity depends on the input.

    //Since the implementation is in place, the space complexity is always O(n)

    return 0;
}