#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, y, a, b;

ll solve(void)
{
    ll ans = 0;

    if (x < y)
        swap(x, y);

    if (y == 0 and x == 0)
        return 0;
    if (y == 0)
        return a * x;

    // 1. both equal

    ans += a * (x - y);
    x = y;

    // 2. chose a or b

    if (b < a * 2)
        ans += b * (x);
    else
        ans += (a * 2) * (x);

    return ans;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> x >> y;
        cin >> a >> b;
        cout << solve() << endl;
    }
    return 0;
}
