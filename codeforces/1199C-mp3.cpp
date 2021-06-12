#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi a, int I)
{
    I *= 8;
    sort(all(a));
    int         n = a.size(), m = 0, prev = a.front();
    vector<int> cnt(n, 0);
    for (auto ai : a)
    {
        if (ai == prev)
            cnt[m]++;
        else
            cnt[++m]++;
        prev = ai;
    }
    cnt.resize(++m);
    vector<int> pcnt(m);
    partial_sum(all(cnt), begin(pcnt));

    auto bits = [](int K) {
        return (K == 1 ? 0 : (31 - __builtin_clz(K - 1)) + 1);
    };
    auto num = [&](int l, int r) {
        return pcnt[r] - (l > 0 ? pcnt[l - 1] : 0);
    };
    auto cost = [&](int l, int r) { return n * bits(r - l + 1); };
    int  ans  = n;
    for (int r = 0; r < m; ++r)
    {
        itll itl(0), itr(r + 1);
        auto ok = [&](int l) { return cost(l, r) <= I; };
        int  l  = *binary_search01(itl, itr, ok);
        ans     = min(ans, n - num(l, r));
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, I;
    cin >> n >> I;
    vi a(n);
    read(all(a));
    cout << solve(a, I) << endl;
    return 0;
}
