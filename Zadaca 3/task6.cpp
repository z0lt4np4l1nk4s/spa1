#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

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
    matrix result {
                    vector<ll> {32}, 
                    vector<ll> {16}, 
                    vector<ll> {8}, 
                    vector<ll> {4}, 
                    vector<ll> {2}, 
                    vector<ll> {1}
                  };

    if(n <= 0) return 0;
    if(n <= 6) return result[6 - n][0];

    matrix A{baseMatrix};
    matrix res = matrixPow(A, n - 6);

    result = multiplyMatrix(res, result);

    return result[0][0];
}

void expect(ll input, ll expectedValue)
{
    ll result = numberOfWays(input);
    cout << "Input: " << input << ", Result: " << result << ", Valid: " << (result == expectedValue) << endl;
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
    expect(50, 660641036);

    return 0;
}