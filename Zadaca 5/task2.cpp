#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <typename T>
class myvector
{
private:
    vector<T> container;

public:
    const size_t size() { return container.size(); }
    void push(T value) { container.push_back(value); }
    const int access(T);
    void transpose(int i, int j);
    void print() const;
};

template <typename T>
const int myvector<T>::access(T value)
{
    for(int i = 0; i < container.size(); i++)
    {
        if(container[i] == value)
        {
            //moving to front without maintaining order
            transpose(i, 0);
            return i;
        }
    }

    return -1;
}

template <typename T>
void myvector<T>::transpose(int i, int j)
{
    swap(container[i], container[j]);
}

template <typename T>
void myvector<T>::print() const
{
    for(auto i : container)
    {
        cout << i << " ";
    }
    cout << endl;
}

void measureFewElements(myvector<int>& V)
{
    auto start = high_resolution_clock::now();

    for(int i = 0; i < V.size(); i++)
    {
        V.access((rand() % 10) + 50);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Access few elements running time - " << duration.count() << "ms" << endl;
}

void measureAllElements(myvector<int>& V)
{
    auto start = high_resolution_clock::now();

    for(int i = 1; i <= V.size(); i++)
    {
        V.access(i);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Access all elements running time - " << duration.count() << "ms" << endl;
}

int main()
{
    myvector<int> V;

    for(int i = 1; i <= 5000; i++)
    {
        V.push(i);
    }

    measureFewElements(V);
    measureAllElements(V);
    
    /*
    Results on my PC:
    - running time for 5000 elements
        - access only top 10: ~1.5ms
        - access all once: ~90ms

    - running time for 10000 elements
        - access only top 10: ~5ms
        - access all once: ~350ms
    
    - running time for 100000 elements
        - access only top 10: 41ms
        - access all once: ~35000ms
    */
}