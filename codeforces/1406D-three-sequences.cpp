/** @file
 * @date                2021-01-26
 * @url                 https://codeforces.com/contest/1406/problem/D
 * @tags                difference_array, greedy, constructive
 * @status              AC
 * @score               3
 * @difficulty          4
 * @editorial           no
 * @reading_time        1
 * @thinking_time       60
 * @coding_time         60
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/82560).
 *
 * @endidea
 */

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

template <typename T>
T ceil(T a, T b)
{
    return a / b + (((a ^ b) >= 0) && (abs(a) % abs(b) != 0));
}

template <typename T>
struct DifferenceArray
{
    vector<T>    d;
    array<ll, 2> unsigned_sum;

    DifferenceArray(const vector<T> &a) : d(a.size()), unsigned_sum({0, 0})
    {
        adjacent_difference(all(a), begin(d));
        for (auto di : d)
            unsigned_sum[di > 0] += abs(di);
        unsigned_sum[d[0] > 0] -= abs(d[0]);
    }

    void update(int i, T x)
    {
        if (i >= isz(d))
            return;

        if (i > 0)
            unsigned_sum[d[i] > 0] -= abs(d[i]);
        d[i] += x;
        if (i > 0)
            unsigned_sum[d[i] > 0] += abs(d[i]);
    }

    void update(int l, int r, T x) { update(l, +x), update(r + 1, -x); }

    vector<T> A() const
    {
        vector<T> ans(d.size());
        partial_sum(all(d), begin(ans));
        return ans;
    }

    ll query() { return ceil(d[0] + unsigned_sum[1], 2LL); }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;

    DifferenceArray da(a);

    cout << da.query() << endl;
    dbg(da.unsigned_sum, da.A(), da.d);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x, l--, r--;
        da.update(l, r, x);

        cout << da.query() << endl;
    }
    return 0;
}
