#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/math/utils>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint1000000007;

int const BIT = 30;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    read(all(a));

    vector<mint> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; ++i)
        p2[i] = p2[i - 1] * 2;

    vector<int> cnt(BIT);

    for (int i = 0; i < n; ++i)
        cnt[largest_power_two_exp(a[i])]++;

    mint ans = p2[n] - p2[n - cnt[0]];
    int  y   = n - cnt[0];

    for (int l = 1; l < BIT; l++)
    {
        int x = y;
        y -= cnt[l];
        if (x - y < 2)
            continue;
        mint delta = p2[x - 1] - p2[y];
        ans += delta;
    }
    cout << ans.val() << endl;

    return 0;
}
