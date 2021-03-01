#include <algorithm>
#include <iostream>

using namespace std;

long fibonacciNumberNaive(long n) 
{ 
    if (n == 0) return 0;

    if (n <= 2) return 1;
    
    return fibonacciNumberNaive(n - 1) + fibonacciNumberNaive(n - 2);
}

long fibonacciNumber(long n, long* memo) 
{ 
    if (memo[n] != 0) return memo[n];

    if (n == 0) return 0;  

    if (n <= 2) return 1;

    return (memo[n] = fibonacciNumber(n - 1, memo) + fibonacciNumber(n - 2, memo)); 
}

long fibonacciNumberWithMemo(int n)
{
    long* memo = new long[n + 1]{0};

    long result = fibonacciNumber(n, memo);

    delete[] memo;
        
    return result;
}

long fibonacciNumberWithTab(int n) 
{ 
    long memo[3] = {0, 1, 1};

    for (int i = 3; i <= n; i++) 
    { 
        memo[i % 3] = memo[(i - 1) % 3] + memo[(i - 2) % 3]; 
    }

    if (n <= 2)
    {
        return memo[n];
    }
    else 
    {
        return max(max(memo[0], memo[1]), memo[2]);
    }
}

int main()
{
    int n = 45;

    cout << n << "-th Fibonacci number obtained using approach with tabulation is equal to " << fibonacciNumberWithTab(n) << endl;
    cout << n << "-th Fibonacci number obtained using memoized approach is equal to " << fibonacciNumberWithMemo(n) << endl;
    cout << n << "-th Fibonacci number obtained using naive approach is equal to " << fibonacciNumberNaive(n) << endl;
}
