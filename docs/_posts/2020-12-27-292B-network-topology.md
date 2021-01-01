---
layout: post
mathjax: true
title: 292B - Network Topology
problem_url: https://codeforces.com/problemset/problem/292/B
tags: graphs, implementation
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Given a connected graph, $G$, with $n$ nodes, you can determine it's type by
its distribution of node-degrees.

- bus: $n-2$ nodes with degree $2$, and $2$ nodes with degree $1$ (the
extremes).
- ring: $n$ nodes of degree $2$.
- star: $n - 1$ nodes with degree $1$ and $1$ node with degree $n-1$.


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
string solve(vi d)
{
    auto dgone = [](int dg) { return dg == 1; };
    auto dgtwo = [](int dg) { return dg == 2; };
    int n = (int)(d).size();
    sort(begin(d), end(d));
    if (all_of(begin(d), end(d), dgtwo))
        return "ring topology";
    if (all_of(begin(d) + 2, end(d), dgtwo) and
        all_of(begin(d), begin(d) + 2, dgone))
        return "bus topology";
    if (d.back() == n - 1 and all_of(begin(d), end(d) - 1, dgone))
        return "star topology";
    return "unknown topology";
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi d(n, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        d[u]++, d[v]++;
    }
    cout << solve(d) << endl;
    return 0;
}

{% endraw %}
```
</details>

