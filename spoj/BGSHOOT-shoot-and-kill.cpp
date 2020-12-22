/** @file
 * @date                2020-12-21
 * @url                 https://url.com
 * @tags                data_structures, segment_tree, coordinate_compression
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        2
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Essentially the problem asks you to find the maximum number of intersections
 * of ranges `[x, y]` in a given range `[l, r]`.
 *
 * Since the ranges are too big, we have to do coordinate compression to be able
 * to fit all of them in an array.
 *
 * So, ideally we'll have a frequency array $freq$, where $freq_i$ denotes the
 * number of ranges that pass through that point. To compute this efficiently,
 * we may use a difference array to construct the frequency array in $O(n)$.
 *
 * Having done this, we may use a segment tree built on top of the resulting
 * frequency array, to efficiently query for maximum on a range `[l, r]`.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace atcoder;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename T>
map<T, int> compress(vector<T> values)
{
    map<T, int> mp;
    int         cnt = 0;
    for (auto v : values)
        mp[v];
    for (auto &[k, v] : mp)
        v = cnt++;
    return mp;
}

int e(void) { return 0; }
int f(int a, int b) { return max(a, b); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n;

    vector<ii>  xy(n);
    vector<int> values;

    for (auto &[x, y] : xy)
    {
        cin >> x >> y, x--, y--;
        values.push_back(x), values.push_back(y);
    }

    cin >> q;
    vector<ii> lr(q);
    for (auto &[l, r] : lr)
    {
        cin >> l >> r, l--, r--;
        values.push_back(l), values.push_back(r);
    }

    auto c = compress(values);
    int  m = isz(c);

    vector<int> freq(m + 2, 0);
    for (auto [x, y] : xy)
        freq[c[x]] += 1, freq[c[y] + 1] -= 1;

    int cnt = 0;
    for (auto &x : freq)
        cnt += x, x = cnt;

    segtree<int, f, e> st(freq);

    for (auto [l, r] : lr)
        cout << st.prod(c[l], c[r] + 1) << endl;

    return 0;
}
