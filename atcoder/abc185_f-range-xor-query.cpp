/** @file
 * @date                2020-12-13
 * @url                 https://atcoder.jp/contests/abc185/tasks/abc185_f
 * @tags                segment_tree, data_structures
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         3
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Segment Tree with xor as operation.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <class T>
struct SegmentTree
{
    using BinaryOperator = std::function<T(T, T)>;

    T              id;
    BinaryOperator op;

    int            n;
    std::vector<T> t;

    template <class InputIterator>
    explicit SegmentTree(InputIterator  first,
                         InputIterator  last,
                         T              id,
                         BinaryOperator op)
        : id(id), op(op), n(distance(first, last))
    {
        t.resize(4 * n);
        build(first, last, 1, 0, n - 1);
    }

    template <class InputIterator>
    void build(InputIterator first, InputIterator last, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = T(*(first + tl));
        else
        {
            int tm = (tl + tr) / 2;
            build(first, last, v << 1, tl, tm);
            build(first, last, (v << 1) + 1, tm + 1, tr);
            t[v] = op(t[v << 1], t[(v << 1) + 1]);
        }
    }

    T query(int l, int r) const { return query(1, 0, n - 1, l, r); }
    T query(int v, int tl, int tr, int l, int r) const
    {
        if (l > r)
            return id;
        if (l == tl and r == tr)
            return t[v];
        int tm = (tl + tr) >> 1;

        return op(query(v << 1, tl, tm, l, std::min(r, tm)),
                  query((v << 1) + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    void update(int pos, T val) { return update(1, 0, n - 1, pos, val); }
    void update(int v, int tl, int tr, int pos, T val)
    {
        if (tl == tr)
            t[v] = val;
        else
        {
            int tm = (tl + tr) >> 1;

            if (pos <= tm)
                update(v << 1, tl, tm, pos, val);
            else
                update((v << 1) + 1, tm + 1, tr, pos, val);
            t[v] = op(t[v << 1], t[(v << 1) + 1]);
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vi a(n);
    read_n(begin(a), n);

    SegmentTree<int> st(all(a), 0, bit_xor<int>());

    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            x--;
            int new_val = st.query(x, x) ^ y;
            st.update(x, new_val);
        }
        else
        {
            x--, y--;
            cout << st.query(x, y) << endl;
        }
    }

    return 0;
}
