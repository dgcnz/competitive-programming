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

int solve(vi a)
{
    int n = a.size();
    vi  msb(n);
    transform(all(a), begin(msb), [](int ai) { return __builtin_clz(ai); });

    for (int i = 1; i < n - 1; ++i)
        if (msb[i - 1] == msb[i] and msb[i] == msb[i + 1])
            return 1;

    vi xa(n);
    partial_sum(all(a), begin(xa), bit_xor<int>());

    auto range_xor = [&](int l, int r) { return xa[r] ^ (l ? xa[l - 1] : 0); };

    int ans = n;
    for (int l = 0; l < n - 1; ++l)
    {
        for (int m = l; m < n - 1; ++m)
        {
            for (int r = m + 1; r < n; ++r)
            {
                int x = range_xor(l, m), y = range_xor(m + 1, r);

                if (x > y)
                    ans = min(ans, r - l - 1);
            }
        }
    }
    return ans == n ? -1 : ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    read(all(a));

    cout << solve(a) << endl;
    return 0;
}
