#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;

inline bool different_bits(ll x, ll y, int i)
{
    return ((x >> i) ^ (y >> i)) & 1LL;
}

ll solve(ll l, ll r)
{
    ll  ans = 0, bit_period = 1, diff = r - l;
    int i = 0;

    // in different periods of bit
    while (diff >= bit_period)
    {
        ans += bit_period;
        bit_period *= 2;
        i++;
    }
    // in (probably) the same period of bit
    while (r >= bit_period)
    {
        if (different_bits(l, r, i))
            ans += bit_period;
        bit_period *= 2;
        i++;
    }
    return ans;
}

int main(void)
{
    ll l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
    return 0;
}
