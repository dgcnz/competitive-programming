---
layout: post
mathjax: true
title: 2134 - Path Queries Ii
problem_url: https://cses.fi/problemset/task/2134
tags: data_structures, trees, hld, segment_tree
memory_complexity: O(n)
time_complexity: O(q \log{n})
---

Same as problem Path Queries but with maximum as the segment tree operation.


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
using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi val(n);
    for (auto &x : val)
        cin >> x;
    HLD<atcoder::segtree, S, op, e> hld(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        hld.add_edge(u, v);
    }
    hld();
    for (int u = 0; u < n; ++u)
        hld.set(u, val[u]);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, x;
            cin >> u >> x, u--;
            hld.set(u, x);
        }
        else
        {
            int u, v;
            cin >> u >> v, u--, v--;
            cout << hld.query(u, v) << " ";
        }
    }
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

