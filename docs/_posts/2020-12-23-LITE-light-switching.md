---
layout: post
mathjax: true
title: LITE - Light Switching
problem_url: https://www.spoj.com/problems/LITE/
tags: data_structures, segment_tree, lazy
memory_complexity: O(n)
time_complexity: O(q \log{n})
---

Choose your favorite range-update, range-query data structure. I'll be using
AtCoder's Lazy Segment Tree for this.

Let's store for each segtree node the amount of elements is covering in its
respective range, $n$ and the amount of lights set "on", $setcnt$.

A range-update (switching lights), $(l, r)$, would be equal to turning off
all set lights and vice versa, or $setcnt = n - setcnt$.


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
struct S
{
    int n, set_cnt;
};
S op(S a, S b) { return {a.n + b.n, a.set_cnt + b.set_cnt}; }
S e() { return {0, 0}; }
using F = bool;
S mapping(F f, S x) { return (f ? S{x.n, x.n - x.set_cnt} : x); }
F composition(F f, F g) { return f ^ g; }
F id() { return 0; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<S> a(n);
    for (auto &ai : a)
        ai = S{1, 0};
    using namespace atcoder;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r, l--, r--;
        if (type == 0)
            seg.apply(l, r + 1, true);
        else
        {
            auto x = seg.prod(l, r + 1);
            cout << x.set_cnt << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

