#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(int num)
{
    string      s = to_string(num);
    vector<int> options;
    for (ll x = 1; x * x <= num; ++x)
        options.push_back(x * x);

    int n    = s.size();
    int best = 0;
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        int fsb  = 31 - __builtin_clz(mask);
        int m    = __builtin_popcount(mask);
        int x    = 0;
        ll  pten = 1;

        if (m <= best or s[n - fsb - 1] == '0')
            continue;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                x += pten * (s[n - i - 1] - '0');
                pten *= 10;
            }
        }
        auto it = lower_bound(all(options), x);
        if (it != options.end() and *it == x)
            best = m;
    }
    if (best == 0)
        return -1;
    return n - best;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
