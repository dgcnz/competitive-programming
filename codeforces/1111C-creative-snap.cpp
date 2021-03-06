#include <algorithm>
#include <cmath>
#include <iostream>
#define KMAX 100010

using namespace std;
using ll = long long;

ll n, k, A, B;

ll a[KMAX];

ll binary_search(ll low, ll high, ll target)
{
    // Gets the first position that matches the target
    auto p = [&](ll x) { return a[x] >= target; };

    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (p(mid))
            high = mid;
        else
            low = mid + 1;
    }

    if (not p(low))
        return high + 1;

    return low;
}

ll divide_and_conquer(ll l, ll r)
{
    // P1
    ll tl = binary_search(0, k - 1, l);
    ll tr = binary_search(0, k - 1, r + 1) - 1;

    if (tr < tl) // P2
        return A;
    else // P3
    {
        if ((r - l) == 0)
            return B * (tr - tl + 1) * 1;
        else
        {
            ll m = l + (r - l) / 2;

            return min(divide_and_conquer(l, m) + divide_and_conquer(m + 1, r),
                       B * (tr - tl + 1) * (r - l + 1));
        }
    }
}

ll solve(void)
{
    sort(a, a + k);
    return divide_and_conquer(0, (int)pow(2, n) - 1);
}

int main(void)
{
    ll ai;

    cin >> n >> k >> A >> B;

    for (int i = 0; i < k; ++i)
    {
        cin >> ai;
        a[i] = ai - 1;
    }

    cout << solve() << endl;
    return 0;
}
