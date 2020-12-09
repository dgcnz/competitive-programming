---
layout: post
mathjax: true
title: 11235 - Frequent Values
problem_url: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2176
tags: segment_tree, data_structures
memory_complexity: O(n)
time_complexity: O(q \log{n})
---

Without loss of generality, assume there are at least three distinct numbers
on a given range. We can abstract this range into three section:

1. A prefix of number $x_1$.
2. A middle section with different blocks of numbers $x_2, x_3, ...$.
3. A suffix of number $x_k$.

Where $k \geq 3$.

The key observation is that for the purpose of computing the most frequent
number in a range, we only need a pair of the form $(cnt_x, x)$ for each of
the three sections in our range, where $x$ is the most frequent number on
that section and $cnt_x$ is its respective count.

Finding the count of the most frequent number on a range would be the same as
taking the maximum of the three pairs.

We can maintain this information on a Segment Tree, where nodes store these
three pairs. Merging nodes $u$ and $v%$ is straightforward:

- Prefix: prefix of $u$.
- Middle: the maximum of the middles in both nodes and the sum of the suffix
of $u$ and prefix of $v$ if both are of the same number (otherwise, they are
treated as separate blocks).
- Suffix: suffix of $v$.

Caution when merging two nodes that have less than 3 unique numbers.


{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
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
template <typename T, typename Container = vector<T>>
struct SegmentTree
{
    int n;
    vector<T> t;
    SegmentTree(Container &a) : n(a.size())
    {
        t.resize(4 * n);
        build(a, 1, 0, n - 1);
    }
    void build(Container &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = T(a[tl]);
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    inline T merge(T a, T b) { return a + b; }
    T query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return T();
        if (l == tl and r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};
struct Node
{
    ii l, m, r;
    Node() : l({0, 0}), m({0, 0}), r({0, 0}) {}
    explicit Node(int x) : l({1, x}), m({1, x}), r({1, x}) {}
    Node operator+(Node const &other) const
    {
        Node ans;
        ans.l = l;
        ans.r = other.r;
        ans.m = max(m, other.m);
        if (r.second == other.l.second)
            ans.m = max(ans.m, {r.first + other.l.first, r.second});
        else
            ans.m = max({ans.m, ans.l, ans.r});
        if (ans.l.second == ans.m.second)
            ans.l = ans.m;
        if (ans.r.second == ans.m.second)
            ans.r = ans.m;
        return ans;
    }
    int get(void) const { return max({l, m, r}).first; }
};
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    while (cin >> n, n)
    {
        cin >> q;
        vi a(n);
        read_n(begin(a), n);
        SegmentTree<Node, vi> st(a);
        while (q--)
        {
            int i, j;
            cin >> i >> j, i--, j--;
            cout << st.query(1, 0, n - 1, i, j).get() << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

