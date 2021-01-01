---
layout: post
mathjax: true
title: 330B - Road Construction
problem_url: https://codeforces.com/problemset/problem/330/B
tags: graph, brute_force
memory_complexity: O(n)
time_complexity: O(n)
---

Note that the constraint (distance between pairs is at most $2$) will only be
satisfied by a star graph (all nodes connected to a center node). The problem
reduces to find a center for such graph and connect all other nodes to it.

Note that there's always an answer because of the $m < \frac{n}{2}$
constraint.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> is_center(n, true);
    while (m--)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        is_center[u] = is_center[v] = false;
    }
    int root =
        distance(begin(is_center),
                 find_if(begin(is_center), end(is_center), [](bool flag) { return flag; }));
    cout << n - 1 << endl;
    for (int u = 0; u < n; ++u)
    {
        if (u == root)
            continue;
        cout << root + 1 << " " << u + 1 << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

