#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ds = array<array<ll, 3>, 2>;

ll solve(ds s012)
{
    ll ans = 0;

    ll temp = min(s012[0][2], s012[1][1]);
    ans += 2 * temp;
    s012[0][2] -= temp;
    s012[1][1] -= temp;

    if (s012[0][2] > 0)
    {
        temp = min(s012[0][2], s012[1][2]);
        s012[0][2] -= temp;
        s012[1][2] -= temp;
    }

    if (s012[0][2] > 0)
    {
        temp = min(s012[0][2], s012[1][0]);
        s012[0][2] -= temp;
        s012[1][0] -= temp;
    }

    if (s012[1][2] > 0)
    {
        temp = min(s012[1][2], s012[0][0]);
        s012[1][2] -= temp;
        s012[0][0] -= temp;
    }

    if (s012[1][2] > 0)
    {
        temp = min(s012[1][2], s012[0][1]);
        ans -= 2 * temp;
        s012[1][2] -= temp;
        s012[0][1] -= temp;
    }

    return ans;
}

ll solve2(ds s012)
{
    // the a's that contribute on increasing
    ll a1 = min(s012[0][2], s012[1][1]);
    // the b's that will match with a result of 0
    ll b0 = s012[1][0] + s012[1][1] - a1;
    // the b's that contribute on decreasing
    ll b1 = max(min(s012[0][1] - b0, s012[1][2]), 0LL);
    return 2 * a1 - 2 * b1;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        ds xyz;
        for (int s = 0; s < 2; ++s)
            for (int i = 0; i < 3; ++i)
                cin >> xyz[s][i];

        cout << solve2(xyz) << endl;
    }
    return 0;
}
