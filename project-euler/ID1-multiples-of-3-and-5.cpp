#include <iostream>

using namespace std;

int sum_of_multiples(int limit, int x)
{
    int n = limit / x;
    return x * n * (n + 1) / 2;
}

int solve(int n)
{
    return sum_of_multiples(n - 1, 3) + sum_of_multiples(n - 1, 5) -
           sum_of_multiples(n - 1, 15);
}

int main(void)
{
    cout << solve(1000) << endl;
    return 0;
}
