#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std;

const int five = 5;
const int thousand = 1000;
const int million = 1000000;

int** generateArrays(int size)
{
    int** array = new int*[100];

    for(int i = 0; i < 100; i++)
    {
        array[i] = new int[size];
        for(int j = 0; j < size; j++)
        {
            array[i][j] = rand();
        }
    }

    return array;
}

void selectionSort(int* arr, int n)
{
    int min; 

    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min]) min = j;
        }
        if(i != min) swap(arr[i], arr[min]);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void deleteArray(int** arrays, int size)
{
    for(int i = 0; i < size; i++)
    {
        delete [] arrays[i];
    }
    delete [] arrays;
}

void measureRunningTime(int** arrays, int size)
{
    auto start = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < 100; i++)
    {
        if(size == million) cout << endl << i;
        selectionSort(arrays[i], size);
    }
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Average time needed to sort arrays of size " << size << " is: " << (duration.count() / 100.0) << " miliseconds" << endl;
}

int main()
{
    // A part of the task
    int arr[five] = {4, 3, 5, 1, 2};
    cout << "Input array: ";
    printArray(arr, five);
    selectionSort(arr, five);
    cout << endl << "Sorted array: ";
    printArray(arr, five);
    cout << endl << endl;

    // D part of the task
    // measuring execution time
    int** thousandSizedArray = generateArrays(thousand);
    measureRunningTime(thousandSizedArray, thousand);

    //for the arrays of size thousand the average
    //sorting time was 1.47 miliseconds on my machine

    int** millionSizedArray = generateArrays(million);
    measureRunningTime(millionSizedArray, million);

    //When I changed the arrays size to million
    //I never got any results, my PC couldn't handle that

    //That means when I increased the arrays size the running time increased as well, 
    //but the complexity remained the same


    deleteArray(thousandSizedArray, thousand);
    deleteArray(millionSizedArray, million);

    return 0;
}