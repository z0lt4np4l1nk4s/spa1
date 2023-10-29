#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

matrix baseMatrix = { vector<ll>{1, 1}, vector<ll>{1, 0} };

matrix multiplyMatrix(const matrix& A, const matrix& B)
{
    matrix res;

    for(int i = 0; i < A.size(); i++)
    {
        res.push_back(vector<ll>{});

        for(int j = 0; B.size() > 0 && j < B[0].size(); j++)
        {
            ll value = 0;

            for(int k = 0; k < B.size(); k++)
            {
                value += A[i][k] * B[k][j];
            }
            
            res[i].push_back(value);
        }
    }

    return res;
}

matrix matrixPow(const matrix& A, ll n)
{
    if(n == 1) return A;

    matrix res;

    if(n % 2)
    {
        n = (n-1) / 2;
        res = matrixPow(A, n);
        res = multiplyMatrix(multiplyMatrix(res, res), A);
    } 
    else 
    {
        n /= 2;
        res = matrixPow(A, n);
        res = multiplyMatrix(res, res);
    }

    return res;
}

ll fibonacci(ll n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    matrix A{baseMatrix};
    matrix res = matrixPow(A, n);
    return res[0][1];
}

void printMatrix(const matrix& A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void expect(ll input, ll expectedValue)
{
    ll result = fibonacci(input);
    cout << "Input: " << input << ", Result: " << result << ", Valid: " << (result == expectedValue) << endl;
}

int main()
{
    expect(5, 5);
    expect(10, 55);
    expect(18, 2584);
    expect(19, 4181);
    expect(20, 6765);
    expect(50, 12586269025);

    return 0;
}