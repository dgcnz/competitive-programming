#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

const int NMAX = 3e4 + 11;

int  coins[5] = {1, 5, 10, 25, 50};
ll   mem[NMAX][5];
bool vis[NMAX][5];

// dp(n, i) = number of ways to get n starting from the ith coin

ll dp(int n, int i)
{
    if (i >= 5 or n < 0)
        return 0;

    if (vis[n][i])
        return mem[n][i];

    vis[n][i] = true;
    ll &ans   = mem[n][i];

    if (n == 0)
        return (ans = 1);

    return (ans = dp(n - coins[i], i) + dp(n, i + 1));
}

int main(void)
{
    int n;
    ll  m;

    while (cin >> n)
    {
        memset(mem, 0, sizeof mem);
        memset(vis, 0, sizeof vis);
        m = dp(n, 0);
        if (m == 1)
            cout << "There is only 1 way to produce ";
        else
            cout << "There are " << m << " ways to produce ";
        cout << n << " cents change." << endl;
    }

    return 0;
}
