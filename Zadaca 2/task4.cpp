#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std;

vector<int> generateRandomArray(int size)
{
    vector<int> V;

    for(int i = 0; i < size; i++)
    {
        V.push_back(rand());
    }

    return V;
}

void merge(vector<int>& V, int start1, int mid, int end)
{
    int start2 = mid + 1;

    while(start1 <= mid && start2 <= end)
    {
        if(V[start1] <= V[start2]) start1++;
        else {
            int currentValue = V[start2];
            int currentIndex = start2;

            while(currentIndex != start1)
            {
                V[currentIndex] = V[currentIndex - 1];
                currentIndex--;
            }
            
            V[start1] = currentValue;

            start1++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(vector<int>& V, int start, int end)
{
    if(end - start <= 1) return;
    int mid = (end + start) / 2;
    mergeSort(V, start, mid);
    mergeSort(V, mid + 1, end);
    merge(V, start, mid, end);
}

//NOTE added a and b parameters just so that I can make my measureRunningTime method generic
void selectionSort(vector<int>& V, int a, int b)
{
    int min; 

    for(int i = 0; i < V.size() - 1; i++)
    {
        min = i;
        for(int j = i+1; j < V.size(); j++)
        {
            if(V[j] < V[min]) min = j;
        }
        if(i != min) swap(V[i], V[min]);
    }
}

void measureRunningTime(vector<int>& V, string sortType, void (*sort)(vector<int>&, int, int))
{
    auto start = chrono::high_resolution_clock::now();
        
    sort(V, 0, V.size() - 1);
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Average time needed to sort arrays using " << sortType << " of size " << V.size() << " is: " << duration.count() << " microseconds" << endl;
}

void printArray(const vector<int>& V)
{
    for(auto i : V)
    {
        cout << i << " ";
    }
    cout << endl;
}

void compareSortMethods(int size)
{
    cout << size << " elements:" << endl;

    vector<int> test = generateRandomArray(size);
    vector<int> test2 = {test};

    measureRunningTime(test, "Selection sort", &selectionSort);
    measureRunningTime(test2, "Merge sort", &mergeSort);
}

int main()
{
    cout << "--- A part of the task ---" << endl;

    vector<int> V = {2, 5, 1, 10, 1, 4, 11, 6};

    cout << "Initial array: ";
    printArray(V);

    mergeSort(V, 0, V.size() - 1);

    cout << "Sorted array: ";
    printArray(V);

    cout << endl << "--- D part of the task ---" << endl;

    // selection sort - ~53 microseconds
    // merge sort - ~24 microseconds
    compareSortMethods(100);
    
    // selection sort - ~5604 microseconds
    // merge sort - ~2020 microseconds
    compareSortMethods(1000);
    
    // selection sort - ~471 ms
    // merge sort - ~186 ms
    compareSortMethods(10000);

    // selection sort - No result
    // merge sort - No result
    compareSortMethods(1000000);

    return 0;
}