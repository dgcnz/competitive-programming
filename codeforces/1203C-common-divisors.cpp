#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 4e5 + 11;

ll n, a[NMAX];

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

ll solve(void)
{
    ll ngcd = a[0], ans = 0;

    for (int i = 1; i < n; ++i)
        ngcd = gcd(ngcd, a[i]);

    for (ll i = 1; i <= sqrt(ngcd); ++i)
    {
        if (ngcd % i == 0)
        {
            if (ngcd / i == i)
                ++ans;
            else
                ans += 2;
        }
    }

    return ans;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << solve() << endl;
    return 0;
}
