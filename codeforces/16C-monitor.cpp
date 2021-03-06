#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

ll a, b, x, y, d, xp, yp;

ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }

ll binary_search(ll low, ll high)
{
    auto p = [&](ll k) { return b < k * yp; };
    while (low < high)
    {
        ll mid = low + (high - low + 1) / 2;

        if (p(mid))
            high = mid - 1;
        else
            low = mid;
    }
    if (p(low))
        return 0;
    return low;
}

int main(void)
{
    ll ap, bp;

    cin >> a >> b >> x >> y;

    d  = gcd(x, y);
    xp = x / d;
    yp = y / d;

    ap = xp * binary_search(0, a / xp);
    bp = y * ap / x;

    cout << ap << " " << bp << endl;

    return 0;
}
