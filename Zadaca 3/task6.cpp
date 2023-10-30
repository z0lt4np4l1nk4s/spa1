//online task
//https://cses.fi/problemset/task/1096

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

//6x6
//1 1 1 1 1 1
//1 0 0 0 0 0
//0 1 0 0 0 0
//0 0 1 0 0 0
//0 0 0 1 0 0
//0 0 0 0 1 0
matrix baseMatrix = { vector<ll>{1, 1, 1, 1, 1, 1}, 
                      vector<ll>{1, 0, 0, 0, 0, 0},
                      vector<ll>{0, 1, 0, 0, 0, 0},  
                      vector<ll>{0, 0, 1, 0, 0, 0},
                      vector<ll>{0, 0, 0, 1, 0, 0},
                      vector<ll>{0, 0, 0, 0, 1, 0},  
                    };

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

ll numberOfWays(ll n)
{
    if(n <= 0) return 0;

    // the formula for calculating the number of ways we 
    // can get a sum of n throwing a 6-sided dice is given as:
    // f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)
    // since we need the prevoius 6 results to calculate the next one
    // I precalculated the first 6 results and put them in a 6x1 matrix

    //32
    //16
    //8
    //4
    //2
    //1
    matrix result {
                    vector<ll> {32}, 
                    vector<ll> {16}, 
                    vector<ll> {8}, 
                    vector<ll> {4}, 
                    vector<ll> {2}, 
                    vector<ll> {1}
                  };

    // If the n is less or equal than 6 then we simply return the precalculated result
    if(n <= 6) return result[6 - n][0];

    // Otherwise, we have to exponentiate our base matrix to the (n-6) power
    matrix A{baseMatrix};
    matrix res = matrixPow(A, n - 6);

    // Finnally we multiply the precalculated results with the exponentiated matrix
    result = multiplyMatrix(res, result);

    // The results is in the first row and first column of the matrix
    return result[0][0];
}

void expect(ll input, ll expectedResult)
{
    ll result = numberOfWays(input);
    cout << "Input: " << input << ", Result: " << result << ", Valid: " << (result == expectedResult) << endl;
}

int main()
{    
    expect(1, 1);
    expect(2, 2);
    expect(3, 4);
    expect(4, 8);
    expect(5, 16);
    expect(6, 32);
    expect(7, 63);
    expect(8, 125);
    expect(9, 248);
    expect(10, 492);
    expect(50, 389043663364337);

    return 0;
}