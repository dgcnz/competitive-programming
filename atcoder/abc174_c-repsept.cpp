#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int k)
{
    ll n = 7;
    for (ll i = 1; i <= k; ++i)
    {
        ll m = n % k;
        if (m == 0)
            return i;
        n = n * 10 + 7;
        n %= k;
    }

    return -1;
}

int main(void)
{
    int k;
    cin >> k;
    cout << solve(k) << endl;

    return 0;
}
