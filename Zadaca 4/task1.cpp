#include <iostream>
#include <vector>

using namespace std;

int getMax(const vector<int>& V)
{
    int m = V[0];

    for(int i = 1; i < V.size(); i++)
    {
        m = max(V[i], m);
    }

    return m;
}

void countingSort(vector<int>& V, int divisor)
{
    vector<int> result((int)V.size());
    vector<int> countVector(10);

    for(auto i: V)
    {
        int a = (i / divisor) % 10;
        countVector[a]++;
    }

    for (int i = 1; i < 10; i++)
    {
        countVector[i] += countVector[i - 1];
    }

    for (int i = V.size() - 1; i >= 0; i--) 
    {
        int a = (V[i] / divisor) % 10;
        result[countVector[a] - 1] = V[i];
        countVector[a]--;
    }

    for(int i = 0; i < V.size(); i++)
    {
        V[i] = result[i];
    }
}

void radixSort(vector<int>& V)
{
    int max = getMax(V);

    for(int i = 1; i < max; i *= 10)
    {
        countingSort(V, i);
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
    vector<int> V {400, 430, 310, 217, 894, 759, 432, 6227, 1111, 1232, 987, 667};
    radixSort(V);
    printArray(V);
    return 0;
}