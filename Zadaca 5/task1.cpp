#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

template <typename T>
class myqueue 
{
private:
    stack<T> firstContainer;
    stack<T> secondContainer;

    void moveElements();

public:
    bool empty() { return size() == 0; }
    size_t size() { return firstContainer.size() + secondContainer.size(); }
    T front();
    void push(T value);
    void pop();
};

template <typename T>
void myqueue<T>::moveElements()
{
    while(!firstContainer.empty())
    {
        secondContainer.push(firstContainer.top());
        firstContainer.pop();
    }
}

template <typename T>
T myqueue<T>::front()
{
    if(secondContainer.empty())
    {
        moveElements();
    }
    return secondContainer.top();
}

template <typename T>
void myqueue<T>::push(T value)
{
    firstContainer.push(value);
}

template <typename T>
void myqueue<T>::pop()
{
    if(size() == 0) return;

    if(secondContainer.empty())
    {
        moveElements();
    }

    secondContainer.pop();
}

//checking whether myqueue works the same as queue
void checkValidity()
{
    myqueue<int> Q;
    queue<int> Q1;

    for(int i = 1; i < 6; i++)
    {
        cout << i << endl;
        Q.push(i);
        Q1.push(i);
    }

    for(int i = 0; i < 2; i++)
    {
        cout << "size " << Q.size() << " - " << Q1.size() << endl;
        cout << Q.front() << " - " << Q1.front() << endl;
        Q.pop();
        Q1.pop();
    }

    for(int i = 6; i < 10; i++)
    {
        cout << i << endl;
        Q.push(i);
        Q1.push(i);
    }

    for(int i = 0; i < 2; i++)
    {
        cout << "size " << Q.size() << " - " << Q1.size() << endl;
        cout << Q.front() << " - " << Q1.front() << endl;
        Q.pop();
        Q1.pop();
    }
}

void measureMyQueue(const vector<int>& instructions)
{
    auto start = high_resolution_clock::now();

    myqueue<int> Q;

    for(auto i : instructions)
    {
        if(i)
        {
            Q.push(rand() % 1000);
        }
        else 
        {
            Q.pop();
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "myqueue running time - " << duration.count() << "ms" << endl;
}

void measureQueue(const vector<int>& instructions)
{
    auto start = high_resolution_clock::now();

    queue<int> Q;

    for(auto i : instructions)
    {
        if(i)
        {
            Q.push(rand() % 1000);
        }
        else 
        {
            Q.pop();
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "queue running time - " << duration.count() << "ms" << endl;
}

int main()
{
    int instructionsCount = 10000000;
    int elementsCount = 0;
    vector<int> instructions(instructionsCount);

    for(int i = 0; i < instructionsCount; i++)
    {
        //I don't want to pop when there are no items in my queue
        if(elementsCount == 0)
        {
            instructions[i] = 1;
            elementsCount++;
        }
        else
        {
            int randomInstruction = rand() % 2;
            instructions[i] = randomInstruction;

            if(randomInstruction) elementsCount++;
            else elementsCount--;
        }
    }

    measureQueue(instructions);
    measureMyQueue(instructions);

    /*
    Results on my PC:
    - running time for 10000000 random instructions
        - queue running time ~560ms
        - myqueue running time ~960ms

    - running time for 1000000 random instructions
        - queue running time ~57ms
        - myqueue running time ~100ms

    - running time for 100000 instructions
        - queue running time ~6ms
        - myqueue running time ~11ms
    */
}