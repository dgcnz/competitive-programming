---
layout: post
mathjax: true
title: practice2_j - Segment Tree
problem_url: https://atcoder.jp/contests/practice2/tasks/practice2_j
tags: data_structures, segment_tree, binary_search
memory_complexity: O(n)
time_complexity: O(q \log{n})
---

[AC-Library
test](https://atcoder.github.io/ac-library/production/document_en/segtree.html)


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
using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return -1; }
bool f(S target, S v) { return v < target; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    using RangeMax = atcoder::segtree<S, op, e>;
    using placeholders::_1;
    RangeMax st(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, v;
            cin >> x >> v, x--;
            st.set(x, v);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r, l--;
            auto ans = st.prod(l, r);
            cout << ans << endl;
        }
        else
        {
            int x, v;
            cin >> x >> v, x--;
            auto ans = st.max_right(x, bind(f, v, _1));
            cout << ans + 1 << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

