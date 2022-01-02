#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/data_structure/mo>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    read(all(x));

    vector<ii> queries(q);
    for (auto &[l, r] : queries)
        cin >> l >> r, l--, r--;

    auto        id = compress(x);
    vector<int> y(n);
    for (int i = 0; i < n; ++i)
        y[i] = id[x[i]];

    int m = id.size();

    auto mo = Mo();
    for (auto [l, r] : queries)
        mo.add_range(l, r + 1);

    int         nuniq = 0;
    vector<int> freq(m, 0), ans(q);
    auto        add = [&](int i)
    {
        if (++freq[y[i]] == 1)
            nuniq++;
    };
    auto remove = [&](int i)
    {
        if (--freq[y[i]] == 0)
            nuniq--;
    };
    auto query = [&](int qi) { ans[qi] = nuniq; };
    mo.run(query, add, remove);
    write(all(ans));
    return 0;
}
