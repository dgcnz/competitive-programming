#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

const int NMAX = 1e5 + 11;

int n, x, a[NMAX];

int solve(void)
{
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        if ((sum / ((ll)i + 1)) < (ll)x)
            return i;
    }
    return n;
}

int main(void)
{
    int t;

    cin >> t;

    while (t--)
    {
        cin >> n >> x;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a, a + n, greater<int>());
        cout << solve() << endl;
    }
    return 0;
}
