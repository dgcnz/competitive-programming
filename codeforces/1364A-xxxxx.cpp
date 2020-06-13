#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 1e5 + 11;

int n, x, a[NMAX];

int solve(void)
{
    int l, r;
    if (accumulate(a, a + n, (ll)0) % x != 0)
        return n;
    l = 0;
    while (l < n and (a[l] % x == 0))
        ++l;

    r = n - 1;
    while (r >= 0 and (a[r] % x == 0))
        --r;

    if (l == n or r == -1)
        return -1;

    return n - min(l + 1, n - r);
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

        cout << solve() << endl;
    }
    return 0;
}
