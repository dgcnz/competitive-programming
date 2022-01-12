#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

pair<vector<int>, vector<int>> solve(vector<ii> a)
{
    Compressor<int> compressor;
    for (auto [l, r] : a)
        compressor.add(l), compressor.add(r);

    auto                id = compressor.get();
    int                 m  = id.size();
    vector<vector<int>> b(m);

    for (auto &[l, r] : a)
        l = id[l], r = id[r];

    for (auto [l, r] : a)
        b[l].push_back(r);
    for (auto &r : b)
        sort(all(r));

    int                        n = a.size();
    vector<int>                contains(n, false), contained(n, false);
    atcoder::fenwick_tree<int> fwd(m), bwd(m);

    auto cmp = [&](ii x, ii y)
    { return x.first == y.first ? x.second > y.second : x.first < y.first; };

    auto sigma = argsort(all(a), cmp);
    for (auto ix : sigma)
    {
        auto [l, r]   = a[ix];
        contained[ix] = fwd.sum(r, m);
        fwd.add(r, 1);
    }

    auto cmp2 = [&](ii x, ii y)
    { return x.first == y.first ? x.second < y.second : x.first > y.first; };
    sigma = argsort(all(a), cmp2);
    for (auto ix : sigma)
    {
        auto [l, r]  = a[ix];
        contains[ix] = bwd.sum(0, r + 1);
        bwd.add(r, 1);
    }

    return {contains, contained};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> a(n);
    for (auto &[l, r] : a)
        cin >> l >> r;

    auto [a0, a1] = solve(a);
    write(all(a0), " "), cout << endl;
    write(all(a1), " "), cout << endl;
    return 0;
}
