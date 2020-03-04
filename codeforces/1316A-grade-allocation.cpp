#include <algorithm>
#include <iostream>
#include <numeric>
#define NMAX 1010

using namespace std;
using ll = long long;

ll n, m;
ll a[NMAX];
ll sum;

ll solve(void)
{
    sum   = accumulate(a, a + n, 0);
    ll a0 = min(sum, m);
    return a0;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        cout << solve() << endl;
    }

    return 0;
}
