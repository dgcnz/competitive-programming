#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

ll solve(int h, int w, int a, int b)
{
    function<ll(int, int, int)> count = [&](int mask, int d, int m) {
        if (!m and !d)
            return 1LL;
        ll ans = 0;
        for (int r = 0; r < h; ++r)
        {
            for (int c = 0; c < w; ++c)
            {
                int ix = r * w + c;
                if (mask & (1 << ix))
                    continue;
                int mono_mask      = mask | (1 << ix),
                    duo_mask_right = mono_mask | 1 << (ix + 1),
                    duo_mask_down  = mono_mask | 1 << (ix + w);

                if (m)
                    ans += count(mono_mask, d, m - 1);
                if (d and c < w - 1 and not(mask & (1 << (ix + 1))))
                    ans += count(duo_mask_right | 1 << (ix + 1), d - 1, m);
                if (d and r < h - 1 and not(mask & (1 << (ix + w))))
                    ans += count(duo_mask_down | 1 << (ix + w), d - 1, m);
                return ans;
            }
        }
        return ans;
    };

    return count(0, a, b);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    cout << solve(h, w, a, b) << endl;
    return 0;
}
