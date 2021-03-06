#include <ios>
#include <iostream>

using namespace std;
using ll = long long;

ll solve(ll n)
{
    return (n * n * (n * n - 1) - 8 - 24 - (n - 4) * 16 - 16 - 24 * (n - 4) -
            8 * (n - 4) * (n - 4)) /
           2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cout << solve(i) << endl;
    return 0;
}
